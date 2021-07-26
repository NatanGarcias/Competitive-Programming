#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

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
int s,t;

vector<vector<pll>> adj;
ll dist[2][MAXN];

bool vis[MAXN], inv;
ll qtd[MAXN], lowQtd[MAXN], cheguei[MAXN];

void dijkstra(int b, int p, int c){

    for(int i=0;i<N;i++) dist[b][i] = INFLL;

    dist[b][p] = 0;

    set<pll> s;

    s.insert(pll(0, p));

    while(!s.empty()){
        int u = (*s.begin()).se;

        s.erase(s.begin());

        for(auto i : adj[u]){
            int v = i.fi;
            ll w = i.se;

            if(dist[b][v] > dist[b][u] + w){
                
                s.erase( pll(dist[b][v], v) );

                dist[b][v] = dist[b][u] + w;

                s.insert( pll(dist[b][v], v) );
            }            
        }
    }
}

void dfs(int u, int p, int cost){

    if(inv) return;

    vis[u] = true;
    cheguei[u] = (u == t);
    lowQtd[u] = qtd[u];

    for(auto i : adj[u]){
        if(inv) return;

        int v = i.fi;
        ll w = i.se;

        //Se to indo para o meu pai é inválido
        if(v == p) continue;

        //Se aquela aresta faz parte de um caminho de s a t em que custo dele é menor que cost
        if(dist[0][u] + w + dist[1][v] > cost && dist[0][v] + w + dist[1][u] > cost) continue;

        if(vis[v]){
            //Se já visitei aquele nó só atualizo a lowQtd
            lowQtd[u] = min(lowQtd[u], lowQtd[v]); 
        }
        else{
            //Se estou visitando aquele nó pela primeira vez

            //Atualizo a qtd de arestas para aquele vértice
            qtd[v] = 1 + qtd[u];

            //Chamo a dfs recursivamente
            dfs(v,u,cost);

            //Atualizo a lowQtd
            lowQtd[u] = min(lowQtd[u], lowQtd[v]); 

            //Verifico se o caminho é inválido
            if(lowQtd[v] > qtd[u] && cheguei[v]){
                inv = 1;
                return;
            }

            //Atualizo que já cheguei naquele vértice
            cheguei[u] += cheguei[v];
        }
    } 
}

//Retorna se aquele custo é inválido, ou seja, dado um grafo montado com os arestas percentes a caminhos com custos menores que cost, não existe nenhuma ponte 
bool f(int u, int p, int cost){

    for(int i=0;i<N;i++) vis[i] = 0, cheguei[i] = 0;

    qtd[u] = 0;
    inv = 0;
    dfs(u, p, cost);

    return inv;
}

ll bb(){

    ll l = 0, r = INF;

    while(l < r){
        ll m = (l+r)/2;

        if( f(s, s, m + dist[0][t] ) ) l = m + 1;
        else    r = m;
    }

    return l;
}

void solve(){

    dijkstra(0,s,t);
    dijkstra(1,t,s);

    //Se é inválido tentando com infinito não existe solução
    if( f(s, s, INF) ){
        cout << -1 << endl;
        return;
    }

    ll ans = bb();

    cout << ans + dist[0][t] << endl;
}

int main(){

	optimize;
	
	cin >> N >> M;
    
    cin >> s >> t;

    s--, t--;

    adj.resize(N);

    for(int i=0;i<M;i++){
        ll a,b,c;
        
        cin >> a >> b >> c;

        a--, b--;    
        
        adj[a].pb(pll(b,c));
        adj[b].pb(pll(a,c));
    }

	solve();
    
	return 0;
}