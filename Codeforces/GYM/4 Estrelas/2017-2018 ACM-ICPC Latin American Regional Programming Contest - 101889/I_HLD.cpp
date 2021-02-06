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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;

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

map<pii,int> mapa, mapa2;
int sum, vis[MAXN];

int seg[4*MAXN];

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

		//Começo com 1 pq faço seg 1-indexada
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
            int d = (p << 1)+1;

            build_seg(e,tl, tm);
            build_seg(d,tm+1,tr);

            seg[p] = max(seg[e],seg[d]);
        }
	}

	int query_seg(int p, int tl, int tr, int a, int b){

	    if(a > tr || b < tl){
	        return 0;
	    }else if(tl >= a && tr <= b){
	        return seg[p];
	    }else{

	        int tm = (tl+tr)/2;
	        int e = (p << 1);
	        int d = (p << 1) +1;

	        return max(query_seg(e,tl,tm,a,b),query_seg(d,tm+1,tr,a,b));
	    }
	}

	int query(int a, int b) {
	    int res = 0;
	    for (; head[a] != head[b]; b = parent[head[b]]) {
	        
			if (depth[head[a]] > depth[head[b]])	swap(a, b);
	        
			int cur_heavy_path_max = query_seg(1, 1, n, pos[head[b]], pos[b]);
	
			res = max(res,cur_heavy_path_max);
	    }

	    if (depth[a] > depth[b])	swap(a, b);
	    
		int last_heavy_path_max = query_seg(1, 1, n, pos[a]+1, pos[b]); 
		res = max(res,last_heavy_path_max);
	    
		return res;
	}
};

vector<vector<pii>> adj;
vector<vector<int>> adj2;

void prim(){

    priority_queue<Edge, vector<Edge>, greater<Edge> > pq;

    vis[0] = true;

    int cnt = 1;

    for(auto i : adj[0]) 	pq.push(Edge(0,i.fi,i.se));

    while(cnt < N){
        int c = pq.top().c;
        int u = pq.top().u;
        int v = pq.top().v;

        pq.pop();

        if(vis[v]) continue;

        vis[v] = true;
        sum += c;
        cnt++;

        mapa[pii(u,v)] = c;
		mapa[pii(v,u)] = c;

		adj2[u].pb(v);
		adj2[v].pb(u);

        for(auto i : adj[v])	pq.push(Edge(v,i.fi,i.se));
    }
}

void solve(){
    
    prim();

    cin >> K;

    HLD hld(adj2);

    while(K--){
        int a,b;

        cin >> a >> b;

        if(a > b) swap(a,b);
        
		a--, b--;

        if(mapa.find(pii(a,b)) != mapa.end()){
            cout << sum << endl;
        }
        else{
            int aux = hld.query(a,b);
            int d = mapa2[pii(a,b)];

            cout << sum + d - aux << endl;
        }
    }
}

int main(){

	optimize;
	
    cin >> N >> M;
    
    adj.resize(N);
    adj2.resize(N);

    for(int i=0;i<M;i++){
        int a,b,c;

        cin >> a >> b >> c;

        a--, b--;

        adj[a].pb(pii(b,c));
        adj[b].pb(pii(a,c));

		mapa2[pii(a,b)] = c;
		mapa2[pii(b,a)] = c;
    }

	solve();

	return 0;
}