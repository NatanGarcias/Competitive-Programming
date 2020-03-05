#include<bits/stdc++.h>
using namespace std;

#define MAXN 200010
#define MAXL 20

#define FOR(x,n) for(int x=0;x<n;x++)

int st[MAXN][MAXL];
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

    int alt(int x){
        return altura[x];
    }
    
    int dist(int x, int y){
        int d = query(x,y);
        return altura[x] + altura[y] -2*altura[d];
    }

    void dist(int x, int y, int a, int b, int k){
        int d = dist(a,b);
        int d1 = dist(a,x) + dist(y,b) + 1;
        int d2 = dist(a,y) + dist(x,b) + 1; 
        
        if(d <= k && ((k-d)%2) == 0) {
            cout << "YES" << endl;
        }else if(d1 <= k && ((k-d1)%2) == 0){
            cout << "YES" << endl;
        }else if(d2 <= k && ((k-d2)%2) == 0){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }

};

int main(){
	
    int n,a,b,x,y,k,q;
    
    cin >> n;

    adj.resize(n+1);

    FOR(i,n-1){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    LCA lca(adj,1);

    cin >> q;
    FOR(i,q){
        cin >> x >> y >> a >> b >> k;

        lca.dist(x,y,a,b,k);
    }
    return 0;
}