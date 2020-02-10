#include<bits/stdc++.h>
using namespace std;

#define MAXN 30010
#define INF 0x7fffffff
bool v[MAXN];
vector<vector<int>> adj;

int N,M,K;

int dfs(int x){

    int ans = 1;

    v[x] = true;
    stack<int> pilha;

    pilha.push(x);

    while(pilha.size()){
        int u = pilha.top();
        pilha.pop();

        for(int i=0;i<adj[u].size();i++){
            int aux = adj[u][i];
            if(!v[aux]){
                v[aux] = true;
                pilha.push(aux);
                ans++;
            }
        }
    }

    return ans;
}

int dfs(){

    int ans = -INF;

    for(int i=0;i<N;i++){
        if(!v[i]){
            ans = max(ans,dfs(i));
        }
    }

    return ans;
}

int main(){

    int K;

    cin >> K;

    while(K--){
        cin >> N >> M;

        memset(v,0,sizeof(v));

        adj.clear();

        adj.resize(N);

        for(int i=0;i<M;i++){
            int a, b;

            cin >> a >> b;

            adj[a-1].push_back(b-1);
            adj[b-1].push_back(a-1);
        }

        cout << dfs() << endl; 
    }
    return 0;
}