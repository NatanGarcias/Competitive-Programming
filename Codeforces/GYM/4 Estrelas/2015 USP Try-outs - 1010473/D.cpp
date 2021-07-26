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

#define all(x) x.begin(),x.end()
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
vector<vector<pii>> adj;

vector<int> dijkstra(int s){

    vector<bool> vis(N,0);
    vector<int> dist(N,INF);

    priority_queue<pii, vector<pii>, greater<pii> > pq;

    pq.push(pii(0,s));
    dist[s] = 0;

    while(!pq.empty()){
        int u = pq.top().second;

        pq.pop();

        if(vis[u]) continue;
        vis[u] = 1;

        for(auto i : adj[u]){
            if(!vis[i.fi]){
                if(dist[i.fi] > dist[u] + i.se) {
                    dist[i.fi] = dist[u] + i.se;
                    pq.push(pii(dist[i.fi], i.fi));
                }
            }
        }
    }

    return dist;
}

void solve(){

    vector<int> dist = dijkstra(N-1);
    vector<pii> d;

    for(int i=0;i<N;i++) d.pb(pii(dist[i],i));    
    sort(all(d));

    ld ans = dist[0];
    ll acum = 0;

    for(int i=0;i<N;i++){
        //Se cheguei no vértice de partida parto
        if(!d[i].se) break;

        //Adiciono a dist entre a cidade ao acumulador
        acum += d[i].fi; 

        //Pego o mínimo entre a viagem que já tenho
        //e a chance de usar as viagens de avião e cair em uma ilha mais perto
        //do que já estou
        // i+1 = ilhas que cair nela me favorecem a partir do vértice que estou
        // N*K = quantidade de viagens de aviões necessárias para garantir que vou poder cair em qualquer ilha (distribuição é uniforme)
        // acum = é o custo de parar em cada ilha que me favorece , já que quero o valor médio vou dividir pelas ilhas que me favorecem tb  
        ans = min(ans, (acum + N * K) * 1.0l / (i+1) );
    }

    cout << fixed << setprecision(8) << ans << endl;
}

int main(){

	optimize;
    
    cin >> T;

    while(T--){

        cin >> N >> M >> K;
        
        adj.resize(N);

        for(int i=0,u,v,w;i<M;i++){
            cin >> u >> v >> w;

            u--, v--;

            adj[u].pb(pii(v,w));
            adj[v].pb(pii(u,w));
        }	

        solve();

        for(int i=0;i<N;i++) adj[i].clear();
    }
    
	return 0;
}