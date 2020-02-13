#include<bits/stdc++.h>
using namespace std;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define ll long long
#define ld long double 

#define endl "\n"

#define pll pair<ll,ll>
#define fi first 
#define se second 

#define INF 0x7fffffff
#define INFLL 0x0fffffffffffffff

#define mod %1000000007

int C,N,M,S,T;
vector<vector<pll>> adj;

ll dijkstra(){

    //Inicia a dist para todo mundo com INF
    vector<ll> dist(N,INFLL);
    
    //Vetor de visitados
    bool v[N] = {0};

    //Dist para o vértice que estou partindo é 0
    dist[S] = 0;
    
    //Fila de prioridade para encontrar vértice com menor distância em tempo log
    priority_queue<pll> pq;

    //Inicializando a pq
    pq.push({ 0,S });

    while(!pq.empty()){
        //Pega o vértice com menor distância da fila
        ll u = pq.top().second;
        pq.pop();

        v[u] = true;

        if(dist[u] == INFLL)
            break;

        //Atualiza a dist para os vizinhos dele
        for(int i=0;i<adj[u].size();i++){
            ll w = adj[u][i].first;
            ll p = adj[u][i].second;

            if(v[w])
                continue;
            else{
                if(dist[w] > dist[u] + p ){
                    
                    ll aux = dist[u] + p;
                    
                    dist[w] = aux;
                    pq.push({ -aux, w });
                }
            }
        }
    }

    if(dist[T] == INFLL)
        return -1;

    return dist[T];
}

int main(){

	cin >> C;

    int cont = 0;
	
    while(C--){

		cin >> N >> M >> S >> T;
        
        adj.clear();
        adj.resize(N);

        for(int i=0;i<M;i++){
            ll a,b,c;

            cin >> a >> b >> c;

            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
        }

        ll ans = dijkstra();

        cout << "Case #" << ++cont << ": ";
        if(ans == -1)
            cout << "unreachable";
        else
            cout << ans;
        cout << endl;
	}

    return 0;
}