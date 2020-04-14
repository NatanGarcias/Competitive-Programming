#include<bits/stdc++.h>
using namespace std;

#define MAXN 3010
#define MAXL 12
#define FOR(x,n) for(int x=0;x<n;x++)

int st[MAXN][MAXL];
bool filho[MAXN];
vector<vector<int>> adj;

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
};

int t,m,q,aux,aux2;

int main(){
    
    cin >> t;
    int cont = 0;
    while(t--){
        cout << "Case " << ++cont  << ":\n";

        cin >> m;

        memset(filho,0,sizeof(filho));

        adj.clear();
        adj.resize(m+1);

        FOR(i,m){
            cin >> aux;
            FOR(j,aux){
                cin >> aux2;
                filho[aux2] = true;
                adj[i+1].push_back(aux2);
            }
        }

        int root = 0;

        FOR(i,m){
            if(!filho[i+1]){
                root = i+1;
                break;
            }
        }
        
        LCA lca(adj,root);

        cin >> q;

        FOR(i,q){
            cin >> aux >> aux2;
            cout << lca.query(aux,aux2) << endl;
        }
    }
    return 0;
}