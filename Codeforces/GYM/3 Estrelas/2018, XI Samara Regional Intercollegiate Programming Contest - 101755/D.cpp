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

#define mod 1000000007LL
#define MAXL 400
#define MAXN 103000
#define MAXM 900000

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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
vector<int> adj[MAXL];
vector<pii> edges;
int A[MAXL],B[MAXL];
int m[MAXL][MAXL];

void dfs(int u){

    for(int i=0;i<adj[u].size();i++){
        
        int w = adj[u][i];
        
        if(w<0) continue;
        
        adj[u][i] = -1;
        
        if(A[w]){
            dfs(w);

            edges.pb(pii(u+1,w+1));
            A[u] = 0;
            A[w] = 1;
        }else{
            edges.pb(pii(u+1,w+1));
            A[u] = 0;
            A[w] = 1;
            
            dfs(w);
        }

        return;
    }
}

void solve(){
    int s = 2*N , n = 2*N +1;

    init();

    FOR(i,0,N){
        FOR(j,0,N){
            if(m[i][j]) add(i, j, INF);
            else add(i, j, 0);
        }
    }
    
    FOR(i,0,N) if(A[i]) add(s, i, 1);

    FOR(i,0,N) if(B[i]) add(i, n, 1);
    
    int ans = dinic(s,n);

    if(ans == M){
        cout << "YES\n";
        
        //Descobrir as arestas
        FOR(i,0,N){
            FOR(j,0,N){
                if(m[i][j]){
                    int w = 2 * (i*N + j) + 1;

                    int aux = 0;

                    while(aux < cap[w]){
                        adj[i].pb(j);
                        aux++;
                    }
                }
            }
        }

        //Montando as trocas
        FOR(i,0,N) if(A[i]) dfs(i);

        cout << edges.size() << endl;
        for(auto i : edges){
            cout << i.fi <<  " " << i.se << endl;
        }

    }
    else{
        cout << "NO\n";
    }
}

int main(){

	optimize;
	
	cin >> N >> M;

    FOR(i,0,M){
        int a;
        cin >> a;
        a--;
        A[a]++;
    }

    FOR(i,0,M){
        int a;
        cin >> a;
        a--;
        B[a]++;
    }

    FOR(i,0,N){
        FOR(j,0,N){
            char k;
            cin >> k;

            if(k == '1') m[i][j] = 1;            
        }
    }

    solve();
    
	return 0;
}