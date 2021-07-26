#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

// #define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
// #define endl "\n"

#define fi first 
#define se second 
#define pb push_back

#define all(x) x.begin(),x.end()
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 500010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

int T,N,M,K;
int seg[4*MAXN];

pii aresta[MAXN];
int parent[MAXN], depth[MAXN], heavy[MAXN], head[MAXN], pos[MAXN], v_seg[MAXN];
string ans;

struct HLD{
	int cur_pos, n;

	HLD(const vector<vector<pii>> & adj) {
	    n = adj.size();
	    ms(heavy, -1);
	    cur_pos = 1;

		v_seg[0] = -1;

	    dfs(0, adj);
	    decompose(0,0,adj);
	    build_seg();
	}
	
	int dfs(int v, const vector<vector<pii>> & adj){
	    int size = 1;
	    int max_c_size = 0;
	    for (pii c : adj[v]) {
	        if (c.fi != parent[v]) {
	            parent[c.fi] = v, depth[c.fi] = depth[v] + 1;
	            int c_size = dfs(c.fi, adj);
	            size += c_size;

				v_seg[c.fi] = c.se;

	            if (c_size > max_c_size)
	                max_c_size = c_size, heavy[v] = c.fi;
	        }
	    }
	    return size;
	}

	void decompose(int v, int h, const vector<vector<pii>> & adj){

	    head[v] = h, pos[v] = cur_pos++;
	    if (heavy[v] != -1)
	    	decompose(heavy[v], h, adj); 
	    
	    for (pii c : adj[v]) {
	        if (c.fi != parent[v] && c.fi != heavy[v])
	            decompose(c.fi, c.fi, adj);
	    }
	}

	void build_seg(){
        for(int i=0;i<n;i++) {
			update_seg(1, 1, n, pos[i],pos[i],v_seg[i]);
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

	        return query_seg(e,tl,tm,a,b) + query_seg(d,tm+1,tr,a,b);
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
	    
		int last_heavy_path_max = query_seg(1, 1, n, pos[a]+1, pos[b]); 
		res += last_heavy_path_max;
	    
		return res;
	}

	void update(int a, int b, ll valor){
	    for (; head[a] != head[b]; b = parent[head[b]]) {
	        
			if (depth[head[a]] > depth[head[b]])	swap(a, b);
	    	update_seg(1, 1, n, pos[head[b]], pos[b], valor);
	    }
		if (depth[a] > depth[b])	swap(a, b);

	    update_seg(1, 1, n, pos[a]+1, pos[b], valor);
	}
};

vector<vector<pii>> adj;

void solve(){

    HLD hld(adj);

    cin >> M;

    string str = "WE NEED BLACK PANDA\n";
    string str2 = "JAKANDA FOREVER\n";

    for(int i=0;i<M;i++){
        int a, b, c;

        scanf("%d %d %d", &a, &b, &c);

        if(a == 1){
            b--, c--;

            int aux = hld.query(b, c);

            if( (aux & 1) ) ans += str;
            else            ans += str2;
        }
        else{
            b--;

            c = (c&1);

            hld.update(aresta[b].fi, aresta[b].se, c);
        }
    }

    printf("%s", ans.c_str());
}

int main(){
    
    scanf("%d", &N);
    
    adj.resize(N);

    for(int i=0;i<N-1;i++){
        int a, b, c;

        scanf("%d %d %d", &a, &b, &c);

        a--, b--;

        c = (c&1);

        aresta[i] = pii(a,b);
        adj[a].pb(pii(b,c));
		adj[b].pb(pii(a,c));
    }

	solve();
    
	return 0;
}