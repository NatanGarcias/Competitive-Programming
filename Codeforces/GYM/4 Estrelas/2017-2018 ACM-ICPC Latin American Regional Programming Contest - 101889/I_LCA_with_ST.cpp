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

#define all(x) x.begin(),x.end()
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 200010
#define MAXL 20
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
vector<vector<pii>> adj, adj2;
int vis[MAXN], level[MAXN], dp[MAXN][MAXL], st[MAXN][MAXL];
map<pii, int> mapa;
ll sum;

struct Edge{
    int u,v,c;

    Edge(){}
    Edge(int _u, int _v, int _c) : u(_u), v(_v), c(_c) {}

    bool operator<(const Edge &a) const{
        if(c != a.c) return c < a.c;
        else if(u != a.u) return u < a.u;
        else if(v != a.v) return v < a.v;
    }

	bool operator>(const Edge &a) const{
        if(c != a.c) return c > a.c;
        else if(u != a.u) return u > a.u;
        else if(v != a.v) return v > a.v;
    }
};

void prim(int root = 1){

    priority_queue<Edge, vector<Edge>, greater<Edge> > pq;

    vis[root] = true;

    int cnt = 1;

    for(auto i : adj[root]) 	pq.push(Edge(root,i.fi,i.se));

    while(cnt < N){
        int c = pq.top().c;
        int u = pq.top().u;
        int v = pq.top().v;

        pq.pop();

        if(vis[v]) continue;

        vis[v] = true;
        sum += c;
        cnt++;

		adj2[u].pb(pii(v,c));
		adj2[v].pb(pii(u,c));

        for(auto i : adj[v])	pq.push(Edge(v,i.fi,i.se));
    }
}

void dfs(int u, int pai, int c){

	level[u] = level[pai] + 1;
	dp[u][0] = pai;
	st[u][0] = c;

	for(int i = 1;i < MAXL ; i++){
		dp[u][i] = dp[ dp[u][i-1] ][i-1];
		st[u][i] = max(st[u][i-1], st[ dp[u][i-1] ][i-1]);
	}

	for(auto i : adj2[u]){
		if(pai != i.fi) dfs(i.fi, u, i.se);
	}

}

void precalc(int root = 1){

	level[0] = -1;

	dfs(root,0,0);
}

int LCA (int u, int v){

	if(level[u] < level[v]) swap(u,v);

	int ans = 0;

	for(int i = MAXL - 1 ; i >= 0 ; i--){
		if(dp[u][i] && level[ dp[u][i] ] >= level[v]) {
			ans = max(ans, st[u][i]);
			u = dp[u][i];
		}
	}

	if(u == v) return ans;

	for(int i = MAXL - 1 ; i >= 0 ; i--){
		if(dp[u][i] != dp[v][i] ) {
			ans = max(ans, st[u][i]);
			ans = max(ans, st[v][i]);
			
			u = dp[u][i];
			v = dp[v][i];
		}
	}

	return max(ans, max(st[u][0], st[v][0]) );
}

void solve(){

	prim();

	precalc();

	cin >> K;

	for(int i=0;i<K;i++){
		int a,b;

		cin >> a >> b;

		if(a > b) swap(a,b);

		int ans = LCA(a,b);

		cout << sum - ans + mapa[pii(a,b)] << endl;
	}
}

int main(){

	optimize;
	
	cin >> N >> M;
	
	adj.resize(N+1);
	adj2.resize(N+1);

	for(int i=0;i<M;i++){
		int a,b,c;

		cin >> a >> b >> c;

		adj[a].pb(pii(b,c));
		adj[b].pb(pii(a,c));

		if(a > b) swap(a,b);
		mapa[pii(a,b)] = c;
	}

	solve();

	return 0;
}