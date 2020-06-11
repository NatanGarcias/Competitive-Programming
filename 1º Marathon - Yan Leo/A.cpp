	#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld; 

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define endl "\n"
#define space " " 

#define pii pair<ll,ll>
#define fi first 
#define se second 

#define pb push_back
#define sz(x) (ll)(x.size())
#define all(x) x.begin(),x.end()

#define FOR(x,a,n) for(int x= (int)(a);(x) < int(n);(x)++)
#define ms(x,a) memset(x,a,sizeof(x))

#define PI 3.141592653589793238462643383279502884

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007
#define MAXN 1000010

struct Caminho{
	int u,c,p;
	Caminho(int _u, int _c, int _p) : u{_u}, c{_c}, p{_p} {};
	bool operator<(const Caminho&a){
		return u < a.u;
	}
};

ll T,N,M,K;
vector<vector<pii>> adj;
vector<bool> vis;

bool v[MAXN];

set<ll> primos;
ll _tam_crivo;

void crivo(ll limite) {
    _tam_crivo = limite + 1;
    for (ll i = 2; i <= _tam_crivo; i++){
		if (!v[i]) {
            for (ll j = i*i; j <= _tam_crivo;j+=i)   v[j] = true;
            primos.insert(i);
        }
    }
}

ll maior;

ll dfs(int x){	
	vis[x] = true;

	ll m1 = 0, m2 = 0;

	for(auto u : adj[x]){
		if(!vis[u.fi]){
			ll aux = dfs(u.fi) + u.se;
			if( aux > m1 ){
				m2 = m1;
				m1 = aux;
			}else if( aux > m2) {
				m2 = aux;
			}
			maior = max(maior, m1+m2);
		}
	}
	return m1;
}

void solve(){

	FOR(i,0,T)
		if(!vis[i]) dfs(i);

	cout << maior << endl;
}

int main(){

	crivo(100010);

	cin >> T;

	adj.resize(T);
	vis.assign(T,false);

    FOR(i,0,T-1){
		cin >> N >> M >> K;
		M--; N--;
		if(primos.find(K) != primos.end()){
			adj[N].pb({M,K});
			adj[M].pb({N,K});
		}
    }
	solve();

	return 0;
}