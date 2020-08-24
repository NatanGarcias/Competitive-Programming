//Dinic and Binary Search

#include<bits/stdc++.h>
using namespace std;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define endl "\n"
#define sz(x) (int)(x.size())
#define all(x) x.begin(),x.end()
#define FOR(x,n) for(int x=0;(x) < int(n);(x)++)
#define INFLL 0x3fffffffffffffff
#define ll long long
#define INF 0x3f3f3f3f
#define MAXN 103000
#define MAXM 900000
#define MAXL 1010

int P,R,A;
ll total;
int refinarias[MAXL];
int postos[MAXL];
vector<int> tempos;

int ned, first[MAXN], work[MAXN], dist[MAXN], q[MAXN];
int cap[MAXM], to[MAXM], nxt[MAXM];

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

struct Aresta{
    int u,v,t;
};

vector<Aresta> arestas;

bool cmp(const struct Aresta &a, const struct Aresta &b){
    if(a.t < b.t){
        return true;
    }else if(a.t > b.t){
        return false;
    }
}

bool verifica(int m){

    int cont = 0;

    init();

    vector<bool> vis(P,0);

    while(cont < A && arestas[cont].t <= m){
        vis[ arestas[cont].u-1 ] = true;
        add(arestas[cont].v, arestas[cont].u + R ,INF);
        cont++;
    }

    FOR(i,P){
        if(!vis[i]){
            return false;
        }
    }

    FOR(i,P){
        add(R+i+1, P+R+1, postos[i]);
    }

    FOR(i,R){
        add(0, i+1 ,refinarias[i]);
    }

    if(dinic(0,1+R+P) >= total){
        return true;
    } else{
        return false;
    }

}

int binarySearch(){

    int l = 0, r = sz(tempos);

    while(true){
        int m = (l+r)/2;

        if(m == sz(tempos)){
            return -1;
        }else if(l==r){
            return tempos[m];
        }else if(verifica( tempos[m] )){
            r = m;
        }else{
            l = m+1;
        }
    }
}

int main(){

    optimize;

    cin >> P >> R >> A;

    FOR(i,P){
        cin >> postos[i];
        total+= postos[i];
    }

    FOR(i,R){
        cin >> refinarias[i]; 
    }   

    arestas.resize(A);
    tempos.resize(A);

    FOR(i,A){
        cin >> arestas[i].u >> arestas[i].v >> arestas[i].t;
        tempos[i] = arestas[i].t;
    }

    sort(all(tempos));
    sort(all(arestas), cmp);

    int ans = binarySearch();
    
    cout << ans << endl;

	return 0;
}