#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;

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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;

struct UF{
	vector<int> parent, rank;

	UF(int n){
		parent.assign(n+1,0);
		rank.assign(n+1,0);
		iota(all(parent), 0);
	}	

	int find(int u){
		if(u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}

	bool sameSet(int u, int v){
		return find(u) == find(v);
	}

	void unir(int u, int v){
		u = find(u);
		v = find(v);

		if(u != v){
			if(rank[u] < rank[v]) swap(u,v);
			if(rank[u] == rank[v]) rank[u]++;
			
			parent[v] = u;
		}
	}
};

struct Edge{
	ll a,b,c;

	Edge(){};
	Edge(ll _a, ll _b, ll _c) : a(_a), b(_b), c(_c) {};
};

ll seg[4*MAXN];

map<pii,ll> mapa;
vector<Edge> edge;
pii aresta;
ll vAresta;

struct HLD{
	vector<int> parent, depth, heavy, head, pos, v_seg;
	int cur_pos, n;

	HLD(const vector<vector<int>> & adj) {
	    n = adj.size();
	    parent.resize(n);
	    depth.resize(n);
	    heavy.resize(n, -1);
	    head.resize(n);
	    pos.resize(n);
		v_seg.resize(n+1);

	    cur_pos = 1;

	    dfs(0, adj);
	    decompose(0,0,adj,-1);
	    build_seg(1,1,n);
	}
	
	int dfs(int v, const vector<vector<int>> & adj){
	    int size = 1;
	    int max_c_size = 0;
	    for (int c : adj[v]) {
	        if (c != parent[v]) {
	            parent[c] = v, depth[c] = depth[v] + 1;
	            int c_size = dfs(c, adj);
	            size += c_size;
	            if (c_size > max_c_size)
	                max_c_size = c_size, heavy[v] = c;
	        }
	    }
	    return size;
	}

	void decompose(int v, int h, const vector<vector<int>> & adj, int ant){
		if(ant == -1) v_seg[cur_pos] = -1; 
		else v_seg[cur_pos] = mapa[pii(v,ant)]; 

	    head[v] = h, pos[v] = cur_pos++;
	    if (heavy[v] != -1)
	    	decompose(heavy[v], h, adj , v); 
	    
	    for (int c : adj[v]) {
	        if (c != parent[v] && c != heavy[v])
	            decompose(c, c, adj, v);
	    }
	}

	void build_seg(int p, int tl, int tr){
        if(tl == tr){
            seg[p] = v_seg[tl];
        }else{
            int tm = (tl+tr)/2;
            int e = (p << 1);
            int d = (p << 1) | 1;

            build_seg(e,tl, tm);
            build_seg(d,tm+1,tr);

            seg[p] = seg[e] + seg[d];
        }
	}

	ll query_seg(int p, int tl, int tr, int a, int b){
	    if(a > tr || b < tl){
	        return 0;
	    }else if(tl >= a && tr <= b){
	        return seg[p];
	    }else{

	        int tm = (tl+tr)/2;
	        int e = (p << 1);
	        int d = (p << 1) +1;

	        return query_seg(e,tl,tm,a,b) + query_seg(d,tm+1,tr,a,b);
	    }
	}

	ll query(int a, int b) {
	    ll res = 0;
	    for (; head[a] != head[b]; b = parent[head[b]]) {
	        
			if (depth[head[a]] > depth[head[b]])	swap(a, b);
	        
			ll cur_heavy_path_max = query_seg(1, 1, n, pos[head[b]], pos[b]);
	
			res += cur_heavy_path_max;
	    }

	    if (depth[a] > depth[b])	swap(a, b);
	    
		ll last_heavy_path_max = query_seg(1, 1, n, pos[a]+1, pos[b]); 
		res += last_heavy_path_max;
	    
		return res;
	}
};

vector<vector<int>> adj;

void pre(){

	UF uf(N);

	for(int i=0;i<N;i++){
		
		int a = edge[i].a;
		int b = edge[i].b;

		if(!uf.sameSet(a,b)){
			uf.unir(a,b);
			
			adj[a].pb(b);
			adj[b].pb(a);
		}
		else{
			aresta.fi = a;
			aresta.se = b;

			vAresta = edge[i].c;
		}
	}
}

void solve(){

	pre();

	HLD hld(adj);

	for(int i=0;i<M;i++){
		ll ans;

		int a,b;

		cin >> a >> b;

		ans = hld.query(a,b);

		ll aux = hld.query(a, aresta.fi) + vAresta + hld.query(aresta.se, b);
		ll aux2 = hld.query(a, aresta.se) + vAresta + hld.query(aresta.fi, b);

		ans = min(ans, aux);
		ans = min(ans, aux2);
		
		cout << ans << endl;
	}

}

int main(){

	optimize;
	
	while(cin >> N && N){

		adj.resize(N);

		for(int i=0;i<N;i++){
			ll a,b,c;

			cin >> a >> b >> c;

			edge.emplace_back(a,b,c);

			mapa[pii(a,b)] = c;
			mapa[pii(b,a)] = c;
		}

		cin >> M;

		solve();

		for(int i=0;i<N;i++) adj[i].clear();

		edge.clear();
		mapa.clear();
	}

	return 0;
}