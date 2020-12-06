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
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL

#define MAXN 31631234
#define MAXM 2123456

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;

bool p[MAXN];
ll v[MAXM], ans[MAXM];
vector<ll> primos;
vector<vector<int>> adj;

void crivo(){

    for(ll i=2;i<MAXN-2;i++){
        if(!p[i]){

            for(ll j = i*i;j<MAXN-2;j+=i) p[i] = true;

            primos.pb(i);
        }
    }
}

void solve(){

    crivo();

    int n = primos.size(), cnt = 0;

    for(int i=0;i<N;i++){

        while(cnt < n && v[ adj[i][0] - N ] > 1){
            if(!(v[ adj[i][0] - N ] % primos[cnt])){

                for(auto j : adj[i]){
                    while( v[j-N] > 1 && !(v[j-N] % primos[cnt]) ) 
                        v[j-N] /= primos[cnt];
                }

                ans[i] = primos[cnt];

                cnt++;

                break;
            }   
            cnt++;
        }

        if(cnt == n){
            for(int j = i;j<N;j++)
                ans[j] = v[ adj[j][0] - N ];
        }
    }

    for(int i=0;i<N;i++) cout << ans[i] << " \n"[i==N-1];

}

int main(){

	optimize;
	
	cin >> N >> M >> K;
    
    for(int i=0;i<M;i++) cin >> v[i];

    adj.resize(N+M);

    for(int i=0;i<K;i++){
        ll a,b,c;

        cin >> a >> b >> c;

        a--, b--;

        adj[a].pb(b + N);
        adj[b + N].pb(a);
    }

	solve();

	return 0;
}