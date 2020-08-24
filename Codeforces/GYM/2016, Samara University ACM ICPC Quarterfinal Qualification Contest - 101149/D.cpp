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

#define sz(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define FOR(x,a,n) for(int x= (int)(a);(x) < int(n);(x)++)
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define MAXN 103000
#define MAXM 900000
#define MAXL 55

ll N,M,R,C;
int ned, first[MAXN], work[MAXN], dist[MAXN], q[MAXN];
int cap[MAXM], to[MAXM], nxt[MAXM];

//Dinic Normal
void init() {
   memset(first, -1, sizeof first);
   ned = 0;
}

void add(int u, int v, int f) {
	to[ned] = v, cap[ned] = f;
	nxt[ned] = first[u];
	first[u] = ned++;
	
	to[ned] = u, cap[ned] = 0;
	nxt[ned] = first[v];
	first[v] = ned++;
}

int dfs(int u, int f, int t) {
	if (u == t) return f;
	for(int &e = work[u]; e != -1; e = nxt[e]) {
		int v = to[e];
		if (dist[v] == dist[u] + 1 && cap[e] > 0) {
			int df = dfs(v, min(f, cap[e]), t);
			if (df > 0) {
				cap[e] -= df;
				cap[e^1] += df;
				return df;
			}
		}
	}
	return 0;
}

bool bfs(int s, int t) {
	memset(&dist, -1, sizeof dist);
	dist[s] = 0;
	int st = 0, en = 0;
	q[en++] = s;
	while (en > st) {
		int u = q[st++];
		for(int e = first[u]; e!=-1; e = nxt[e]) {
			int v = to[e];
			if (dist[v] < 0 && cap[e] > 0) {
				dist[v] = dist[u] + 1;
				q[en++] = v;
			}
		}
	}
	return dist[t] >= 0;
}

int dinic(int s, int t) {
	int result = 0, f;
	while (bfs(s, t)) {
		memcpy(work, first, sizeof work);
		while (f = dfs(s, INF, t)) result += f;
	}
	return result;
}

//Matriz de custo, visitados e resposta
int v[MAXL][MAXL];
bool vis[MAXL][MAXL];
char ans[MAXL][MAXL];

//Retorna a posição do vértice no fluxo
// z == 0 vértice v
// z == 1 vértice v'
//vértice fora dos limites é o destino
int getP(int x, int y, bool z){
	
    if(x < 0 || y < 0 || x>=N || y>=M) return 2*N*M;
    
	if(z) return 2*(x*M + y);
	else  return 2*(x*M + y) +1;
}

//Vejo se estou numa posição válida na matriz
bool posValid(int x, int y){
	if( x<0 || y<0 || x>=N || y>=M) return false;
	return true;
}

//Construo o grafo
void fluxo(){

    init();

    int n = 2*N*M, s = getP(R,C, 1);
	
	// Adiciono aresta que liga o vertice v a v' com o fluxo v[i][j]
	FOR(i,0,N){
		FOR(j,0,M){
			add(getP(i,j,0), getP(i,j,1), v[i][j]);	
		}
	}

	//Adiciono aresta que liga o v' aos vertices adjacentes com o fluxo INF
    FOR(i,0,N){
        FOR(j,0,M){

            int u = getP(i,j,1);
	        
			for(int k = -1;k<=1; k++){
                for(int l = -1;l<=1; l++){
                    if(abs(k) + abs(l) == 1) {
						if(i+k == R && j+l == C) continue; // Ignoro a fonte
                        int w = getP(i+k, j+l, 0);

						add(u, w, INF);
                    }
                }
            }
	    }
    }

	//Imprimo o corte mínimo
	cout << dinic(s, n) << endl;
}

//Dfs para achar a matriz de resposta
void dfs(){
	
	//Inicio a matriz como se toda posição não fosse uma cerca
	FOR(i,0,N) FOR(j,0,M) ans[i][j] = '.';
	
	FOR(i,0,N*M){
        if(dist[2*i]< 0 && dist[2*i+1] >= 0){
            int px = i/M;
            int py = i%M;
            
            ans[px][py] = 'X';
        }
    }
}

//Só imprimi a matriz
void print(){

	FOR(i,0,N){
		FOR(j,0,M){
			cout << ans[i][j];
		}
		cout << endl;
	}

}

void solve(){
	fluxo();
	dfs();
	print();
}

int main(){

	optimize;
	
	cin >> N >> M >> R >> C;

	R--; C--;

    FOR(i,0,N) FOR(j,0,M) cin >> v[i][j];
		
	solve();

	return 0;
}