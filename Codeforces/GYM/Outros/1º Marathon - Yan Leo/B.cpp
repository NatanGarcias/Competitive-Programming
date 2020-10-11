#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
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

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007
#define MAXT 310

struct Aresta{
	int u,v,t;
	Aresta(int _u, int _v, int _t) : u{_u}, v{_v}, t{_t} {}
	bool operator<(const Aresta& a) const{
		return t < a.t;
	}
};

int T,N,M,K;

int m[MAXT][MAXT];
bool vis[MAXT][MAXT];

map<int,int> mapa1;
map<int,int> mapa2;

vector<int> navios;
vector<vector<int>> dist2;
vector<Aresta> arestas;

#define MAXN 100009
#define MAXM 900009

int ned;
int first[MAXN], to[MAXM], nxt[MAXM], prv[MAXN];
ll cap[MAXM], cost[MAXM], dist[MAXN], pot[MAXN]; 

void init() {
	memset(first, -1, sizeof first);
	ned = 0;
}

void add(int u, int v, ll f, ll c) {
	to[ned] = v, cap[ned] = f;
	cost[ned] = c, nxt[ned] = first[u];
	first[u] = ned++;
	to[ned] = u, cap[ned] = 0;
	cost[ned] = -c, nxt[ned] = first[v];
	first[v] = ned++;
}

bool dijkstra(int s, int t, int n) {
	memset(&prv, -1, sizeof prv);
	for(int i = 1; i <= n; i++) dist[i] = INFLL;
	set< pair<ll, int> > q;
	q.insert(make_pair(0LL, s));
	dist[s] = prv[s] = 0;
	while(!q.empty()) {
		int u = q.begin()->second;
		q.erase(q.begin());
		for(int e = first[u]; e != -1; e = nxt[e]) {
			if (cap[e] <= 0) continue;
			int v = to[e];
			ll new_dist = dist[u] + cost[e] + pot[u] - pot[v];
			if (new_dist < dist[v]) {
				q.erase(make_pair(dist[v], v));
				dist[v] = new_dist;
				prv[v] = e;
				q.insert(make_pair(new_dist, v));
			}
		}
	}
	return prv[t] != -1;
}

ll augment(int s, int t, ll &maxflow, int n) {
	ll flow = maxflow;
	for(int i = t; i != s; i = to[prv[i]^1])
		flow = min(flow, cap[prv[i]]);
	for(int i = t; i != s; i = to[prv[i]^1]) {
		cap[prv[i]] -= flow;
		cap[prv[i]^1] += flow;
	}
	maxflow -= flow;
	ll flowCost = flow*(dist[t]-pot[s]+pot[t]);
	for(int i = 1; i <= n; i++)
		if (prv[i] != -1) pot[i] += dist[i];
	return flowCost;
}

ll mincostmaxflow(int s, int t, ll &maxflow, int n) {
	ll flowCost = 0;
	memset(pot, 0, sizeof pot);
	while(maxflow > 0 && dijkstra(s, t, n)) {
		flowCost += augment(s, t, maxflow, n);
	}
	return flowCost;
}

bool posValid(int a, int b){
    if(a >=0 && a < N && b>=0 && b<M) return true;
    else return false;
}

void bfs(int k, int a){

    ms(vis,0);

    queue<pair<pii,int>> fila;

    fila.push(make_pair(pii(0,a),0));

    vis[0][a] = true;

    while(!fila.empty()){
        pii u = fila.front().fi;
        int t = fila.front().se;
        fila.pop();

        if(posValid(u.fi+1, u.se) && !vis[u.fi+1][u.se] && m[u.fi+1][u.se] != 1){

            if(m[u.fi+1][u.se] == 2){
			    dist2[ k ][ mapa2[u.se] ] = min(dist2[ k ][ mapa2[u.se] ], t+1 );
            }

            fila.push(make_pair(pii(u.fi+1, u.se), t+1));
            vis[u.fi+1][u.se] = true;
        }
        if(posValid(u.fi-1, u.se) && !vis[u.fi-1][u.se] && m[u.fi-1][u.se] != 1){
             
            if(m[u.fi-1][u.se] == 2)
                dist2[ k ][ mapa2[u.se] ] = min(dist2[ k ][ mapa2[u.se] ], t+1 );

            fila.push(make_pair(pii(u.fi-1, u.se), t+1));
            vis[u.fi-1][u.se] = true;
        }
        if(posValid(u.fi, u.se+1) && !vis[u.fi][u.se+1] && m[u.fi][u.se+1] != 1){
            
            if(m[u.fi][u.se+1] == 2)
                dist2[ k ][ mapa2[u.se+1] ] = min(dist2[ k ][ mapa2[u.se+1] ], t+1 );

            fila.push(make_pair(pii(u.fi, u.se+1), t+1));
            vis[u.fi][u.se+1] = true;
        }
        if(posValid(u.fi, u.se-1) && !vis[u.fi][u.se-1] && m[u.fi][u.se-1] != 1){
            
			if(m[u.fi][u.se-1] == 2)
                dist2[ k ][ mapa2[u.se-1] ] = min(dist2[ k ][ mapa2[u.se-1] ], t+1 );
            
            fila.push(make_pair(pii(u.fi, u.se-1), t+1));
            vis[u.fi][u.se-1] = true;
        }
    }
}

ll fluxo(){

	init();

	// Navios para os Portos
	FOR(i,0,sz(arestas)){
		add(arestas[i].u + 1, arestas[i].v + T + 1, INF, arestas[i].t);
	}

	//Fonte para os Navios
	FOR(i,0,T){	
		add(0,i+1,1,0);
	}

	//Portos para o Sorvedouro 
	FOR(i,0,K){
		add( T+1+i ,T+K+1,1, 0);
	}

	ll f = sz(navios);
	ll ans = mincostmaxflow(0,T+K+1, f , T+K+2);
	
	if(f) return -1;
	return ans;
}

void cria(){
	FOR(i,0,T){
		FOR(j,0,K){
			if( dist2[i][j] != INF){
				arestas.emplace_back(i,j, dist2[i][j]);
			}
		}
	}
}

void solve(){

    FOR(i,0,T){
    	int k = mapa1[navios[i]];
        bfs(k,navios[i]); 
    }
	
	cria();

    ll ans = fluxo();
    cout << ans << endl;
}

int main(){

    optimize;

    cin >> N >> M >> T >> K;

    int a;

    navios.resize(T);
    dist2.resize(T,vector<int> (K,INF));

    FOR(i,0,N){
        FOR(j,0,M){
            cin >> m[i][j];
        }
    }

    FOR(i,0,T){
        cin >> a;
        a--;
        navios[i] = a;
        mapa1[a] = i;
    }

    FOR(i,0,K){
        cin >> a;
        a--;
        m[N-1][a] = 2;
        mapa2[a] = i;
    }
    solve();
}