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
#define MAXN 1010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;

vector<int> adjU[MAXN];
int pairU[MAXN], pairV[MAXN];
bool vis[MAXN];
int m, n;

bool dfs(int u) {
    vis[u] = true;
    if (u == 0) return true;
    for (int i = 0; i < (int)adjU[u].size(); i++) {
        int v = adjU[u][i];
        if (!vis[pairV[v]] && dfs(pairV[v])) {
            pairV[v] = u; pairU[u] = v;
            return true;
        }
    }
    return false;
}

int kuhn() {
    memset(&pairU, 0, sizeof pairU);
    memset(&pairV, 0, sizeof pairV);
    int result = 0;
    for (int u = 1; u <= m; u++) {
        memset(&vis, false, sizeof vis);
        if (pairU[u]==0 && dfs(u)) result++;
    }
    return result;
}

vector<vector<int>> adj;
int cor[MAXN];

void bipartite(){

    queue<pii> fila;

    fila.push(pii(1,0));
    cor[1] = 0;

    while(!fila.empty()){
        int u = fila.front().fi;
        bool c = fila.front().se;

        fila.pop();

        c = !c;

        for(int v : adj[u]){
            if(!(cor[v] + 1)){
                cor[v] = c;
                fila.push(pii(v,c));
            }
        }
    }

}

void solve(){

    vector<int> pos(N+1,0);
    ms(cor, -1);

    bipartite();

    int cnt = 0, cnt2 = 0;

    for(int i=1;i<=N;i++) {
        if(cor[i]) pos[i] = ++cnt;
        else pos[i] = ++cnt2;
    }

    for(int i=1;i<=N;i++) {
        if(cor[i]){
            for(int j : adj[i]){
                adjU[ pos[i] ].pb(pos[j]);
            }
        }
    }

    n = cnt, m = cnt2;
    
    int ans = kuhn();

    cout << N - ans << endl;

    for(int i=0;i<=cnt;i++) adjU[i].clear();
}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
		cin >> N >> M;

        adj.resize(N+1);

        for(int i=0,u,v;i<M;i++){
            cin >> u >> v;

            adj[u].pb(v);
            adj[v].pb(u);
        }
		
		solve();

        for(int i=0;i<=N;i++) adj[i].clear();
    }

	return 0;
}