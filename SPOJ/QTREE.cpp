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
#define MAXN 20000

int seg[4*MAXN]; 
map<pii,int> mapa;

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
	    decompose(0, 0, adj,-1);
	    
	    memset(seg,0,sizeof(seg));
	    build_seg(1,1,n);
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

	void decompose(int v, int h, vector<vector<int>> const& adj, int ant) { 
		
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
		if( tl == tr ){
			seg[p] = v_seg[tl];
		}else{
			int tm = (tl+tr)/2;
			int e = (p << 1) ;
			int d = (p << 1) +1;

			build_seg(e,tl,tm);
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

	        return max(query_seg(e,tl,tm,a,b), query_seg(d,tm+1,tr,a,b));
	    }
	}

	void update_seg(int p, int tl, int tr, int a, int b, int f){

	    if(a > tr || b < tl){
	        return;
	    }else if(tl >= a && tr <= b){
	        seg[p] = f;
	        return;
	    }else{
	        int tm = (tl+tr)/2;
	        int e = (p << 1);
	        int d = (p << 1) + 1;

	        update_seg(e,tl,tm,a,b,f);
	        update_seg(d,tm+1,tr,a,b,f);
	        
	        seg[p] = max(seg[e], seg[d]);
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

ll T,N,M;

void solve(){
	vector<vector<int>> adj(N);
	vector<pii> arestas(N-1);

	mapa.clear();

	string s;
	int a,b,c;

	FOR(i,0,N-1){
		cin >> a >> b >> c;

		a--; b--;

		arestas[i] = (pii(a,b));
		adj[a].pb(b);
		adj[b].pb(a);

		mapa[ pii(a,b) ] = c;
		mapa[ pii(b,a) ] = c;
	}

	HLD hld(adj);
	
	while(cin >> s){
		
		if(s[0] == 'D') break;

		if(s[0] == 'Q'){
			cin >> a >> b;

			a--; b--;

			cout << hld.query(a,b) << endl;

		}else if(s[0] == 'C'){
			cin >> a >> b;

			a--;

			pii aux = arestas[a];

			if(hld.depth[aux.fi] < hld.depth[aux.se]) aux.fi = aux.se;
			
			hld.update_seg(1,1,N,hld.pos[aux.fi], hld.pos[aux.fi], b);
		}
	}
}

int main(){

	optimize;

	cin >> T;

    while(T--){
    	cin >> N;
    	solve();
    }

	return 0;
}