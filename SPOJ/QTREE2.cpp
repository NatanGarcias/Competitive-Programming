#include<bits/stdc++.h>
using namespace std;

// Template 1
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld; 

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

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

#define MAXN 200010

ll T,N,M,K;

int seg[4*MAXN]; 
map<pii,int> mapa;

// Quando for fazer a consulta do hld nas arestas lembre-se que a aresta é representada pela posição
// do vértice adjacente a ela mais alto da árvore

struct HLD{
	vector<int> parent, depth, heavy, head, pos, v_seg, rpos;
	int cur_pos, n;

	HLD(const vector<vector<int>> & adj) {
	    n = adj.size();
	    parent.resize(n);
	    depth.resize(n);
	    heavy.resize(n, -1);
	    head.resize(n);
	    pos.resize(n);
		rpos.resize(n+1);
		v_seg.resize(n+1);

	    cur_pos = 1;

	    dfs(0, adj);
	    decompose(0,0,adj,-1);
		ms(seg,0);
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

	void decompose(int v, int h, const vector<vector<int>> & adj, int ant) { 
		if(ant == -1) v_seg[cur_pos] = 0; 
		else v_seg[cur_pos] = mapa[pii(v,ant)]; 

	    head[v] = h, rpos[cur_pos] = v, pos[v] = cur_pos++;
	    if (heavy[v] != -1)
	        decompose(heavy[v], h, adj, v); 
	    
	    for (int c : adj[v]) {
	        if (c != parent[v] && c != heavy[v])
	            decompose(c, c, adj, v);
	    }
	}

	void build_seg(int p, int tl, int tr){
		if(tl == tr){
			seg[p] = v_seg[tl];
			return;
		}
		
		int tm = (tl+tr)/2;
		int e = (p << 1);
		int d = (p << 1) +1;
		
		build_seg(e,tl,tm);
		build_seg(d,tm+1,tr);

		seg[p] = seg[e] + seg[d];
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

	        return query_seg(e,tl,tm,a,b) + query_seg(d,tm+1,tr,a,b);
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
	    
		int last_heavy_path_max = query_seg(1, 1, n, pos[a]+1, pos[b]);
		
		res += last_heavy_path_max;
	    
		return res;
	}

	int kth(int a, int b, int k) {
	    //Descobre o tamanho do caminho
		int t = 0, A = a, B = b;

	    for (; head[a] != head[b]; b = parent[head[b]]) {
	        
			if (depth[head[a]] > depth[head[b]])	swap(a, b);
	        
			int cur_heavy_path_max = abs(depth[head[b]] - depth[b]) +1;

			t += cur_heavy_path_max;
	    }

	    if (depth[a] > depth[b])	swap(a, b);
	    
		int last_heavy_path_max = abs(depth[a] - depth[b]) + 1;
			
		t += last_heavy_path_max;
	    
		//Calcula o elemento naquela posição
		int indo = k-1;
		int vindo = t-k;

		a = A;
		b = B;
		
		if(k == 1) return a;
		if(k == t) return b;
	
		bool esc = true;
		
		for (; head[a] != head[b] && (indo && vindo); b = parent[head[b]]) {
			
			if (depth[head[a]] > depth[head[b]]){
				swap(a, b);
				esc = esc^1;
			}
	        
			int cur_heavy_path_max = abs(depth[head[b]] - depth[b]);

			if(!esc){
				if(indo <= cur_heavy_path_max){
					return rpos[ pos[b] - indo];
				}
				else{
					indo -= cur_heavy_path_max+1;
				}
			}
			else{
				if(vindo <= cur_heavy_path_max){	
					return rpos[ pos[b] - vindo ];
				}
				else{
					vindo -= cur_heavy_path_max+1;
				}
			}
		}

		if(!indo || !vindo) return rpos[pos[b]];

		if (depth[a] > depth[b]){
			swap(a, b);
			esc = esc^1;
		}

		if(esc) return rpos[ pos[a] + indo ];
		else	return rpos[ pos[a] + vindo];

		return 0;
	}
};

vector<vector<int>> adj;

void solve(){

	HLD hld(adj);
	
	string s;

	while(cin >> s){
		if(s == "DONE") break;

		int a,b,c;

		if(s[0] == 'D'){	
			cin >> a >> b; a--; b--;

			cout << hld.query(a,b) << endl;

		}else{
			cin >> a >> b >> c; a--; b--;

			int aux = hld.kth(a,b,c);

			cout << aux+1 << endl;
		}
	}
}

int main(){

	cin >> T;

	while(T--){
		cin >> N;

		adj.resize(N);
		FOR(i,0,N) adj[i].clear();
		
		mapa.clear();

		FOR(i,0,N-1){
			int a,b,c;

			cin >> a >> b >> c; 
			a--; b--;

			adj[a].pb(b);
			adj[b].pb(a);

			mapa [ pii(a,b) ] = c; 
			mapa [ pii(b,a) ] = c;
		}

		solve();
		cout << endl;
    }

	return 0;
}