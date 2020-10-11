#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<int,ll> pii;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

#define fi first 
#define se second 
#define pb push_back

#define sz(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define FOR(x,a,n) for(int x= (int)(a);(x) < int(n);(x)++)
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 998244353LL
#define MAXN 300010
#define MAXM 510

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;

struct Q{
    int id, c;
    ll t;

    Q() {}
    Q(int _id, int _c, ll _t) : id(_id), c(_c), t(_t) {}

};

Q q[MAXN];
ll v[MAXM][MAXM];
ll t[MAXM][MAXM];
bool hor[MAXM], ver[MAXM];

void solve(){
    ll ans = 0;
    
    for(int k = K-1;k>=0 ;k--){
        if(!q[k].id && !hor[ q[k].c ]){ //Linha
            hor[ q[k].c ] = true;
            int i = q[k].c; 
            
            FOR(j,0,M){
                
                if(t[i][j] > q[k].t) continue;
                
                ll fi = (q[k].t - t[i][j])%mod;
                fi = (fi * v[i][j])%mod;

                t[i][j] = q[k].t;

                ans = (ans + fi)%mod;
            }
        } //Coluna  
        else if(q[k].id && !ver[ q[k].c ]){
            
            int j = q[k].c; 
            FOR(i,0,N){

                if(t[i][j] > q[k].t) continue;
                
                ll fi = (q[k].t - t[i][j])%mod;
                fi = (fi * v[i][j])%mod;

                t[i][j] = q[k].t;
                
                ans = (ans + fi)%mod;
            }
        }
    }

    cout << ans << endl;
}

int main(){

	optimize;
	
    cin >> N >> M >> K;
		
	FOR(i,0,N){
        FOR(j,0,M){
            cin >> v[i][j];
            v[i][j] %= mod;
        }
    }

    FOR(i,0,K){
        char k;
        int a,b;
        ll c;

        cin >> k >> b >> c;

        if(k == 'r') a = 0;
        else a = 1;

        Q aux(a,b-1,c);

        q[i] = aux;
    }

    solve();

	return 0;
}