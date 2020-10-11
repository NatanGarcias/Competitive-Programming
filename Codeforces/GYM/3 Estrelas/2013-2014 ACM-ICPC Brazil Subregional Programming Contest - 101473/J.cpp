#include<bits/stdc++.h>
using namespace std;

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
#define MAXN 20010

ll N,M,S;
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

        FOR(i,0,4*MAXN) seg[i] = INF;

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

		if(ant == -1) v_seg[cur_pos] = INF; 
		else v_seg[cur_pos] = mapa[pii(v,ant)]; 

	    head[v] = h, pos[v] = cur_pos++;

	    if (heavy[v] != -1)
	        decompose(heavy[v], h, adj,v);
	    
	    for (int c : adj[v]) {
	        if (c != parent[v] && c != heavy[v])
	            decompose(c, c, adj,v);
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

            seg[p] = min(seg[e],seg[d]);
        }
	}

	int query_seg(int p, int tl, int tr, int a, int b){

	    if(a > tr || b < tl){
	        return INF;
	    }else if(tl >= a && tr <= b){
	        return seg[p];
	    }else{
	        int tm = (tl+tr)/2;
	        int e = (p << 1);
	        int d = (p << 1) +1;

	        return min(query_seg(e,tl,tm,a,b), query_seg(d,tm+1,tr,a,b));
	    }
	}

	int query(int a, int b) {
		int res = INF;
	    for (; head[a] != head[b]; b = parent[head[b]]) {
	        
			if (depth[head[a]] > depth[head[b]])	swap(a, b);
	        
			int cur_heavy_path_max = query_seg(1, 1, n, pos[head[b]], pos[b]);
	
			res = min(res,cur_heavy_path_max);
	    }

	    if (depth[a] > depth[b])	swap(a, b);
	    
		int last_heavy_path_max = query_seg(1, 1, n, pos[a]+1, pos[b]);
		
		res = min(res,last_heavy_path_max);
	    
		return res;
	}

    void imprimi_hld(){

		cout << "parent depth heavy head pos v_seg\n";
		for(int i=0;i<n;i++){
			cout << parent[i] << "        " << depth[i] << "     " << heavy[i];
			cout <<  "    " << head[i] << "   " << pos[i] << "    " << v_seg[i+1] << endl;			
		}

		cout << "v_seg: ";
		for(int i=0;i<n;i++) cout << v_seg[i+1] << " ";
		cout << endl; 
	}

	void imprimi_seg(){
		for(int i=1;i<4*n;i++) cout << seg[i] << " ";
		cout << endl;
	}
};

vector<vector<int>> adj;
vector<vector<pii>> adj2;

void prim(){
    
    vector<bool> vis(N,0);
    priority_queue<pair<int,pii>> pq;
    int x = 0;

    vis[x] = true;

    for(auto i : adj2[x]) pq.push(make_pair(i.se,pii(x,i.fi)));
    
    int cont = 1;

    while(cont < N && !pq.empty()){

        int v = pq.top().fi;
        pii edge = pq.top().se;
        pq.pop();

        if(vis[edge.se]) continue;

        vis[edge.se] = true;
        
        adj[edge.fi].pb(edge.se);
        adj[edge.se].pb(edge.fi);

        mapa[pii(edge.fi,edge.se)] = v;
        mapa[pii(edge.se,edge.fi)] = v;

        cont++;

        x = edge.se;

        for(auto i : adj2[x]) pq.push(make_pair(i.se,pii(x,i.fi)));
    }
}

void solve(){

    prim();

    HLD hld(adj);

    FOR(i,0,S){
        int a,b;

        cin >> a >> b;

        a--; b--;

        cout << hld.query(a,b) << endl;
    }
}

int main(){

    optimize;

	cin >> N >> M >> S;

    adj.resize(N);
    adj2.resize(N);

	FOR(i,0,M){

        int a,b,c;

        cin >> a >> b >> c;

        a--; b--;

        adj2[a].pb(pii(b,c));
        adj2[b].pb(pii(a,c));
    }

    solve();

	return 0;
}