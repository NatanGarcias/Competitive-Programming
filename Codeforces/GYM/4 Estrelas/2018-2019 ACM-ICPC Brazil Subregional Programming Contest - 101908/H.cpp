#include<bits/stdc++.h>
using namespace std;

// Template 3

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
#define MAXN 100010
#define MAXM 109

ll T,N,M;
string chave, s;

int parent[MAXN], depth[MAXN], head[MAXN], pos[MAXN], heavy[MAXN];
char v_seg[MAXN];

struct SEG{
	int m, to[MAXM],match[MAXM];

	SEG(int _m = -1) : m{_m} {}
};

SEG operator +(const SEG &a, const SEG &b){
	if(b.m < 0) return a;
	if(a.m < 0) return b;

	SEG c(a.m);
	
	for(int i=0;i< c.m;i++){
		c.to[i] = b.to[ a.to[i] ];
		c.match[i] = a.match[i] + b.match[ a.to[i] ];
	}
	return c;
}

SEG seg[2][4*MAXN];

struct KMP{
    int m;
    string q;
    vector<int> lps;
    
    void build(string &_q){
    	q = _q;
        m = q.size();
        pre_process();
    }

    void pre_process(){
        lps.assign(m+1,-1);

        for(int i=0, j=-1; i<m ; ){
            while(j>=0 && q[i] != q[j]) j = lps[j];
            lps[++i] = ++j; 
        }
    }

    SEG match(char c){
        SEG ans(m);

        for(int i=0,j,cnt; i < m; i++){
        	j = i, cnt = 0;
        	while(j>=0 && c != q[j]) j = lps[j];
        	j++;

        	if( j == m ){
        		cnt++;
        		j = lps[j];
        	}

        	ans.to[i] = j;
        	ans.match[i] = cnt;
        }
        
        return ans;
    }
};

KMP kmp;

struct HLD{
	int cur_pos, n;

	HLD(vector<vector<int>> const& adj) {
	    n = adj.size();
		ms(heavy,-1);
		
	    cur_pos = 1;

	    dfs(0, adj);
	    decompose(0, 0, adj);
	    build_seg(1,1,n,0);
	   	build_seg(1,1,n,1);
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
		v_seg[cur_pos] = s[v];

	    head[v] = h, pos[v] = cur_pos++;
	    if (heavy[v] != -1)
	        decompose(heavy[v], h, adj);
	    
	    for (int c : adj[v]) {
	        if (c != parent[v] && c != heavy[v])
	            decompose(c, c, adj);
	    }
	}

	void build_seg(int p, int tl, int tr, int t){
        if(tl == tr){
            seg[t][p] = kmp.match(v_seg[tl]);
            return;
        }

        int tm = (tl+tr)/2;
        int e = (p << 1);
        int d = (p << 1) +1;

        build_seg(e,tl,tm,t);
        build_seg(d,tm+1,tr,t);

        if(t)	seg[t][p] = seg[t][d] + seg[t][e];   
        else	seg[t][p] = seg[t][e] + seg[t][d];   
    }
	
	SEG query_seg(int p, int tl, int tr, int a, int b, int t){

	    if(a > tr || b < tl){
	    	SEG aux; 
	    	ms(aux.to,0);
	    	ms(aux.match,0);
	        return aux;
	    }else if(tl >= a && tr <= b){
	        return seg[t][p];
	    }else{
	        int tm = (tl+tr)/2;
	        int e = (p << 1);
	        int d = (p << 1) +1;

	        if(t)	return query_seg(d,tm+1,tr,a,b,t) + query_seg(e,tl,tm,a,b,t); 
	        else 	return query_seg(e,tl,tm,a,b,t) + query_seg(d,tm+1,tr,a,b,t);
	    }
	}

	void update_seg(int p, int tl, int tr, int a, int b, char f, int t){

	    if(a > tr || b < tl){
	        return;
	    }else if(tl >= a && tr <= b){
	        seg[t][p] =  kmp.match(f);
	    }else{
	        int tm = (tl+tr)/2;
	        int e = (p << 1);
	        int d = (p << 1) + 1;

	        update_seg(e,tl,tm,a,b,f,t);
	        update_seg(d,tm+1,tr,a,b,f,t);
	        
	        if(t) seg[t][p] = seg[t][d] + seg[t][e];
	    	else  seg[t][p] = seg[t][e] + seg[t][d];
	    }
	}

	int query(int a, int b) {
	    SEG l,r;

	    bool escolha = true;

	    for (; head[a] != head[b]; b = parent[head[b]]) {
	        
	        if (depth[head[a]] > depth[head[b]]){
				escolha = escolha ^ 1;
				swap(a, b);
			}
	        	
	        if(!escolha) {
	        	SEG cur_heavy_path_max = query_seg(1, 1, n, pos[head[b]], pos[b], 1);
	        	l = l + cur_heavy_path_max;
	        }else {
	        	SEG cur_heavy_path_max = query_seg(1, 1, n, pos[head[b]], pos[b], 0);
	        	r = cur_heavy_path_max + r;
			}
	    }
		
		if (depth[a] > depth[b]){
	    	escolha = escolha ^ 1;
	    	swap(a, b);
	    }
	    	
        if(escolha){
        	SEG last_heavy_path_max = query_seg(1, 1, n, pos[a], pos[b], 0);
        	l = l + last_heavy_path_max;
        }else{
        	SEG last_heavy_path_max = query_seg(1, 1, n, pos[a], pos[b], 1);
        	r = last_heavy_path_max + r;
		}

		l = l+r;

		return l.match[0];
	}

	void update(int a, int b, char valor){
		if (depth[a] > depth[b])	swap(a, b);

	    update_seg(1, 1, n, pos[a], pos[b], valor, 0);
	    update_seg(1, 1, n, pos[a], pos[b], valor, 1);
	}
};

vector<vector<int>> adj;

void solve(){

    kmp.build(chave);
    
    HLD hld(adj);
    
    FOR(i,0,M){
        int a;

        cin >> a;

        if(a == 1){
            int b,c;
            
            cin >> b >> c; b--; c--;

            int ans = hld.query(b,c);

            cout << ans << endl;
        }else{
            int b;
            char k;
            
            cin >> b >> k; b--;

            hld.update(b,b,k);
        }
    }
}

int main(){

	optimize;

	cin >> N >> M;
    
    adj.resize(N);

    cin >> chave >> s;

    FOR(i,0,N-1) {
        int a,b; 
        
        cin >> a >> b;
        a--; b--;

        adj[a].pb(b);
        adj[b].pb(a);
    }

	solve();

	return 0;
}