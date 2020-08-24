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

#define mod 1000000007LL
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
int v[MAXN];
int vis[MAXN];
vector<vector<int>> adj;
vector<vector<int>> dist;

void bfs(vector<int> &elem, int k){

	ms(vis,0);

	queue<pii> fila;

	FOR(i,0,sz(elem)){
		fila.push(pii(elem[i],0));
		vis[elem[i]] = true;
	}

	while(!fila.empty()){
		int u = fila.front().fi;
		int t = fila.front().se;
		fila.pop();

		for(auto i : adj[u]){
			if(!vis[i]){
				vis[i] = true;
				dist[i][k] = t+1;
				fila.push(pii(i,t+1));
			}
		}
	}
}

void solve(int k){

	vector<int> aux;

	FOR(i,0,N) if(v[i] == k) aux.pb(i);

	bfs(aux,k);
}

void solve(){

	FOR(i,0,K) solve(i);

	FOR(i,0,N) sort(all(dist[i]));

	vector<int> ans;

	FOR(i,0,N){
		int aux = 0;
		
		FOR(j,0,T) aux += dist[i][j];

		ans.pb(aux);
	}
	
	FOR(i,0,N) cout << ans[i] << " \n"[i==N-1];
}

int main(){

    cin >> N >> M >> K >> T;

    FOR(i,0,N){
    	cin >> v[i];
    	v[i]--;
    }

    adj.resize(N);

	dist.resize(N);
	FOR(i,0,N) dist[i].assign(K,0);

    FOR(i,0,M){
		int a,b;
		
		cin >> a >> b;
		a--; b--;

		adj[a].pb(b);
		adj[b].pb(a);
    }

    solve();

	return 0;
}