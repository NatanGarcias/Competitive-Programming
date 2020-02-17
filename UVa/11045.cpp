#include<bits/stdc++.h>
using namespace std;

int N,n,k;

#define FOR(x,n) for(int x=0;x<n;x++)
#define INF 0x3f3f3f3f
#define INFLL 0x3fffffffffffffff
#define ll long long int

struct Edge{
    int v,u;
    ll cap, flow = 0;
    Edge(int v, int u, ll cap): v(v), u(u), cap(cap) {}
};

struct Dinic{
    const ll flow_inf = INFLL;
    vector<Edge> edges;
    vector<vector<int>> adj;
    int n,m = 0; //Vértices e arestas (arestas conta as do fluxo de bloqueio também) 
    int s,t; //Fonte e Sorvedouro
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t): n(n), s(s), t(t){
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add(int v, int u, int cap){
        edges.emplace_back(v,u,cap);
        edges.emplace_back(u,v,0);

        adj[v].push_back(m);
        adj[u].push_back(m+1);

        m+=2;
    }

    bool bfs(){
        while(!q.empty()){
            int v = q.front();
            q.pop();
            for(int id : adj[v]){
                if(edges[id].cap - edges[id].flow < 1)
                    continue;
                if(level[edges[id].u] != -1)
                    continue;
                
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    bool dfs(int v , ll pushed){
        if(pushed == 0) return 0;
        if(v == t) return pushed;

        for(int& cid = ptr[v]; cid<(int)adj[v].size(); cid++){
            int id = adj[v][cid];
            int u = edges[id].u;

            if(level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1){
                continue;
            }

            ll tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));

            if(tr == 0) continue;

            edges[id].flow +=tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    ll fluxo(){
        ll f = 0;

        while(true){
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);

            if(!bfs()) break;

            fill(ptr.begin(), ptr.end(), 0);

            while(ll pushed = dfs(s, flow_inf)){
                f += pushed;
            }
        }
        return f;
    }
};

int main(){

    cin >> N;
    string a,b;
    int u,v;

    while(N--){
        cin >> n >> k;

        Dinic D(k+8,0,k+7);
        
        FOR(i,k){

            D.add(0,i+1,1);
            cin >> a >> b;

            if(a == "XXL"){
                u = k+1; 
            }else if(a == "XL"){
                u = k+2; 
            }else if(a == "L"){
                u = k+3; 
            }else if(a == "M"){
                u = k+4; 
            }else if(a == "S"){
                u = k+5; 
            }else if(a == "XS"){
                u = k+6; 
            } 

            if(b == "XXL"){
                v = k+1; 
            }else if(b == "XL"){
                v = k+2; 
            }else if(b == "L"){
                v = k+3; 
            }else if(b == "M"){
                v = k+4; 
            }else if(b == "S"){
                v = k+5; 
            }else if(b == "XS"){
                v = k+6; 
            }
            
            D.add(i+1,v,INF);
            D.add(i+1,u,INF); 
        }

        FOR(i,6){
            D.add(k+i+1,k+7,n/6);
        }

        if(D.fluxo() >= k){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }

    return 0;
}