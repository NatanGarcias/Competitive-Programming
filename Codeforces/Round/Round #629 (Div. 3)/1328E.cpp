#include<bits/stdc++.h>
using namespace std;

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
#define INF 0x33ffffff
#define INFLL 0x33ffffffffffffff

#define mod %1000000007

#define MAXN 200010
#define MAXL 20

vector<vector<int>> adj;
int st[2*MAXN + 1][MAXL];

struct LCA{
    vector<int> first,altura,euler,log;
    vector<bool> vis;
    int N,K;
    
    LCA(const vector<vector<int>> &adj , int root = 0){
        N = adj.size();
        K = log2(N)+1;
        first.resize(N);
        altura.resize(N);
        log.assign(2*N+1,0);
        euler.reserve(2*N);
        vis.assign(N,false);
        
        dfs(adj,root,0);

        build(euler.size());    
    }

    void dfs(const vector<vector<int>> &adj , int u,int h = 0){
        vis[u] = true;
        altura[u] = h;
        first[u] = euler.size();
        euler.push_back(u);
        
        for(auto i : adj[u]){
            if(!vis[i]){
                dfs(adj,i,h+1);
                euler.push_back(u);
            }
        }
    }

    void build(int n){
        memset(st,0,sizeof(st));

        for(int i=0;i<n;i++){
            st[i][0] = euler[i];
        }

        for(int j=1;j<=K;j++){
            for(int i=0;i + (1<<j) <= n;i++){
                int l = st[i][j-1];
                int r = st[i + (1<<(j-1))][j-1];
                st[i][j] =  altura [l] < altura[r] ? l : r;
            }
        }

        for(int i=2;i<=n;i++){
            log[i] = log[i/2] + 1;
        }
    }

    int query(int u, int v){
        int L = first[u];
        int R = first[v];

        if(L>R) swap(L,R);
        
        int j = log[R-L+1];

        int l = st[L][j];
        int r = st[R-(1<<j) + 1 ][j];
        return altura[l] < altura[r] ? l:r;
    }

    int getAlt(int u){
    	return altura[u];
    }

    int dist(int u, int v){
    	return getAlt(u) + getAlt(v) - 2*getAlt( query(u,v));
    }

};


int main(){

    int N,M;

    cin >> N >> M;
    adj.resize(N);
    int a,b;

    FOR(i,0,N-1){
        cin >> a >> b;
        adj[a-1].pb(b-1);
        adj[b-1].pb(a-1);
    }

    LCA lca(adj,0);

    FOR(i,0,M){
        cin >> a;
        
        vector<int> v(a);
 		
 		int maior = 0;

        FOR(j,0,a){
            cin >> v[j];
            v[j]--;
            if(lca.getAlt(v[j]) > lca.getAlt(maior)){
            	maior = v[j];
            }
        }

        bool certo = true;
        FOR(j,0,a){
        	int c = lca.query(v[j],maior);

        	if(lca.dist(c,v[j]) > 1 ){
        		certo = false;
        		break;
        	}
        }

        if(certo)	cout << "YES\n";
        else	cout << "NO\n";
    }
}