#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld; 

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define space " " 

#define pii pair<int,int>
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
#define MAXN 200010

int seg[4*MAXN]; 
int lazy[8*MAXN];

struct HLD{
	vector<int> parent, depth, heavy, head, pos, v_seg;
	int cur_pos, n;

	HLD(vector<vector<int>> const& adj) {
	    n = adj.size();
	    parent.resize(n);
	    depth.resize(n);
	    heavy.resize(n, -1);
	    head.resize(n);
	    pos.resize(n);
		v_seg.resize(n+1);

	    cur_pos = 1;

	    dfs(0, adj);
	    decompose(0, 0, adj);
	    build_seg();
	}

	int dfs(int v, vector<vector<int>> const& adj){
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

	void decompose(int v, int h, vector<vector<int>> const& adj) { 
		v_seg[cur_pos] = v;

	    head[v] = h, pos[v] = cur_pos++;
	    if (heavy[v] != -1)
	        decompose(heavy[v], h, adj);
	    for (int c : adj[v]) {
	        if (c != parent[v] && c != heavy[v])
	            decompose(c, c, adj);
	    }
	}

	void build_seg(){
		memset(seg,0,sizeof(seg));
		memset(lazy,0,sizeof(lazy));
	}

	void push_seg(int p , int tl, int tr){
    
	    int e = (p << 1);
	    int d = (p << 1) +1;
		
		seg[p] = seg[p] + ((tr - tl + 1) * lazy[p]);	
	    
	    lazy[e] += lazy[p];
		lazy[d] += lazy[p];
	    lazy[p] = 0;
	}

	int query_seg(int p, int tl, int tr, int a, int b){

	    push_seg(p,tl,tr);
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

	void update_seg(int p, int tl, int tr, int a, int b, int f){

	    push_seg(p,tl,tr);

	    if(a > tr || b < tl){
	        return;
	    }else if(tl >= a && tr <= b){
	        lazy[p] = f;
	        push_seg(p,tl,tr);
	        return;
	    }else{
	        int tm = (tl+tr)/2;
	        int e = (p << 1);
	        int d = (p << 1) + 1;

	        update_seg(e,tl,tm,a,b,f);
	        update_seg(d,tm+1,tr,a,b,f);
	        
	        seg[p] = seg[e] + seg[d];
	    }
	}

	int query(int a, int b) {
	    int res = 0;
	    for (; head[a] != head[b]; b = parent[head[b]]) {
	        
			if (depth[head[a]] > depth[head[b]])	swap(a, b);
	        
			int cur_heavy_path_max = query_seg(1, 1, n, pos[head[b]], pos[b]);
	
			res += cur_heavy_path_max;
	    }

	    if (depth[a] > depth[b])	swap(a, b);
	    
		int last_heavy_path_max = query_seg(1, 1, n, pos[a], pos[b]);
		
		res += last_heavy_path_max;
	    
		return res;
	}

	void update(int a, int b, int valor){
	    for (; head[a] != head[b]; b = parent[head[b]]) {
	        
			if (depth[head[a]] > depth[head[b]])	swap(a, b);
	    	update_seg(1, 1, n, pos[head[b]], pos[b], valor);
	    }
		if (depth[a] > depth[b])	swap(a, b);

	    update_seg(1, 1, n, pos[a], pos[b], valor);
	}
};

ll T,N,M;
vector<vector<int>> adj;

void solve(){

	HLD hld(adj);
    
	int a,b,c,d;

    FOR(i,0,T){
		cin >> a >> b >> c >> d;
		
		a--; b--;
		c--; d--;

		hld.update(a,b,1);
		
		cout << hld.query(c,d) << endl;

		hld.update(a,b,-1);
	}
}

int main(){
	
	optimize;
	
	cin >> N >> T;

	adj.resize(N);

	int a,b;
	FOR(i,0,N-1){
		cin >> a >> b;
		
		a--; b--;

		adj[a].pb(b);
		adj[b].pb(a);
	}

	solve();
}
