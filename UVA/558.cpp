#include<bits/stdc++.h>
using namespace std;
#define INF 9999999

//Numero de vertices e arestas do caso de teste
int n,m;

void bellmanFord(vector<vector<pair<int,int>>>&adj){
    //Vetor que guarda as distancias do vertice i para os outros
    vector<int> dist(n,INF);

    //dist para a Terra eh 0
    dist[0] = 0;

    //Repito N-1 vezes 
    // Para cada aresta vejo se a dist[u] + u-v < dist[v]
    // Se for menor atualizo
    for(int i=0;i<n;i++){
        for(int j=0;j<adj[i].size();j++){
            int u = adj[i][j].first;
            int w = adj[i][j].second;

            if(dist[i] + w < dist[u]){
                dist[u] = dist[i] + w;
            }
        }
    }
    
    //Para cada aresta olho se dist[u]+ u-v + dist[v]
    // Se algum valor diminuir é pq o grafo tem ciclo negativo
    for(int i=0;i<n;i++){
        for(int j=0;j<adj[i].size();j++){
            int u = adj[i][j].first;
            int w = adj[i][j].second;

            if(dist[i] + w < dist[u]){
                cout << "possible" << endl;
                return;
            }
        }
    }
    cout << "not possible" << endl;
}

int main(){

    int casos;

    cin >> casos;

    //Enquanto houver casos de teste
    while(casos--){

        cin >> n >> m;

        vector<vector<pair<int,int>>> adj(n);

        int a,b,c;

        for(int i=0;i<m;i++){
            cin >> a >> b >> c;

            adj[a].push_back({b,c});
        }

        bellmanFord(adj);
    }   
}