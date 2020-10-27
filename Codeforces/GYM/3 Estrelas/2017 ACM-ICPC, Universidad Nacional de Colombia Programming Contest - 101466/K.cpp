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
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 100010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;

vector<int> seg[4*MAXN];
ll value[MAXN];
int nums[6] = {2,3,5,7,11,13};

struct HLD{
	vector<int> parent, depth, heavy, head, pos, v_seg, sz;
	int cur_pos, n;

	HLD(const vector<vector<int>> & adj) {
	    n = adj.size();
	    parent.resize(n);
	    depth.resize(n);
	    heavy.resize(n, -1);
	    head.resize(n);
	    pos.resize(n);
        sz.resize(n);
		v_seg.resize(n+1);

	    cur_pos = 1;

	    dfs(0, adj);
	    decompose(0, 0, adj);
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
        sz[v] = size; 
	    return size;
	}

	void decompose(int v, int h, const vector<vector<int>> & adj) { 
		v_seg[cur_pos] = value[v];

	    head[v] = h, pos[v] = cur_pos++;
	    if (heavy[v] != -1)
	        decompose(heavy[v], h, adj);

	    for (int c : adj[v]) {
	        if (c != parent[v] && c != heavy[v])
	            decompose(c, c, adj);
	    }
	}

    vector<int> combine(vector<int> a, vector<int> b){
        vector<int> aux(6);
        for(int i=0;i<6;i++) aux[i] = a[i] + b[i];
        return aux;
    }

	void build_seg(int p, int tl, int tr){

        if(tl == tr) {
            vector<int> aux(6,0);
            int num = v_seg[tl];
            int cnt = 0;
            
            while(num > 1){
                if( ! (num % nums[cnt]) ){
                    aux[cnt]++;
                    num = num / nums[cnt];
                }
                else{
                    cnt++;
                }
            }

            seg[p] = aux;

            return;
        }

        int tm = (tl+tr)/2;
        int e = (p << 1);
        int d = (p << 1) +1;

        build_seg(e,tl,tm);
        build_seg(d,tm+1,tr);

        seg[p] = combine(seg[e], seg[d]);
	}

	vector<int> query_seg(int p, int tl, int tr, int a, int b){

	    if(a > tr || b < tl) {
            vector<int> aux(6,0);
            return aux;
        }

	    if(tl >= a && tr <= b) return seg[p];
	    
        else{
	        int tm = (tl+tr)/2;
	        int e = (p << 1);
	        int d = (p << 1) +1;

	        return combine(query_seg(e,tl,tm,a,b), query_seg(d,tm+1,tr,a,b));
	    }
	}

	void update_seg(int p, int tl, int tr, int a, ll f){

	    if(a > tr || a < tl){
	        return;
	    }else if(tl >= a && tr <= a){
            vector<int> aux(6,0);
            ll num = f;
            int cnt = 0;
            
             while(num > 1){
                if( ! (num % nums[cnt]) ){
                    aux[cnt]++;
                    num = num / nums[cnt];
                }
                else{
                    cnt++;
                }
            }

	        seg[p] = combine(seg[p],aux);

	        return;
	    }else{
	        int tm = (tl+tr)/2;
	        int e = (p << 1);
	        int d = (p << 1) + 1;

	        //Atualiza o filho a esq e a dir
	        update_seg(e,tl,tm,a,f);
	        update_seg(d,tm+1,tr,a,f);
	        
	        //Atualiza a sua posição
	        seg[p] = combine(seg[e],seg[d]);
	    }
	}

	vector<int> query(int a) {
        vector<int> aux;
	    
        aux = query_seg(1,1,n, pos[a], pos[a] + sz[a]-1);
	    
		return aux;
	}

	void update(int a, ll valor){
	    update_seg(1, 1, n, pos[a], valor);
	}
};

vector<vector<int>> adj;

ll countDivisors(vector<int> arr){
    ll ans = 1LL;
    for(int i = 0; i < 6; i++)
        ans = (ans * (arr[i] + 1)) %mod;
    return ans;
}

ll fastExpo(ll a, ll n) {
	ll ret = 1;
	ll b = a;
  	while (n) {
    	if (n & 1)
     	 	ret = (ret * b) % mod;
    	b = (b * b) %mod;
    	n >>= 1;
  	}
  	return (ll)ret;
}

void solve(){

    cin >> M;

    HLD hld(adj);
    
    for(int i=0;i<M;i++){
        string s;
        ll a,b;

        cin >> s;

        if(s[0] == 'R'){
            //Query
            cin >> a;

            vector<int> ans = hld.query(a);

            ll aux = 1;

            for(int i=0;i<6;i++){
                aux = (aux * fastExpo(nums[i], ans[i])) % mod ;
            }

            //Adicionar negocio dos divisores
            cout << aux << " " << countDivisors(ans) << endl;
        }
        else{
            //Update
            cin >> a >> b;

            hld.update(a,b);
        }
    }
}

int main(){

	optimize;
	
	cin >> N;

    adj.resize(N);

    for(int i=0;i<N-1;i++){
        int a,b;

        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=0;i<N;i++){
        cin >> value[i];
    }
	
	solve();
    
	return 0;
}