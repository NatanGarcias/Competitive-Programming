#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

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

#define mod 1000000007
#define MAXN 50

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
int v[MAXN][MAXN];

void solve(){
    
    vector<pii> ans(N+M -2 +1);

    FOR(i,0,N){
        FOR(j,0,M){
            int pos = N+M-i-j-2;
            if(v[i][j]){
                ans[pos].fi++; 
            }else{
                ans[pos].se++;
            }
        }
    }

    ll resp = 0;
    FOR(i,0,(N+M)/2 ){
        if(i == N+M-i-2) continue;
        else{
            pii aux = pii(0,0);

            aux.fi += ans[i].fi;
            aux.se += ans[i].se;

            aux.fi += ans[N+M-i-2].fi;
            aux.se += ans[N+M-i-2].se;

            resp += min(aux.fi,aux.se);
        }
    }

    cout << resp << endl;
}

int main(){

	cin >> T;

    while(T--){
		cin >> N >> M;
    
        FOR(i,0,N) FOR(j,0,M) cin >> v[i][j];

		solve();
    }

	return 0;
}