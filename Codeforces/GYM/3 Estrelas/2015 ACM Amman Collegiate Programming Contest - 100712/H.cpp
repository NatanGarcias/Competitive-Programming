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
#define MAXN 100010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;

int cont;
int low[MAXN], disc[MAXN], parent[MAXN];

vector<int> adj[MAXN];
int szPontes, qttd;

void init(){
    memset(low, -1, N * sizeof(int));
    memset(disc, -1, N * sizeof(int));
    memset(parent, -1, N * sizeof(int));

    szPontes = 0, qttd = 0, cont = 0;
}

int tarjan(int u){

	low[u] = disc[u] = cont++;
	
    int m1 = 0, m2 = 0;

	for(int i = 0 ; i < adj[u].size() ; i++){

		int v = adj[u][i];

		if(disc[v] == -1){
			parent[v] = u;

			int aux = tarjan(v);

            if(low[v] > disc[u]) szPontes++, aux++;

			low[u] = min(low[u], low[v]);

            if(aux > m1){
                m2 = m1;
                m1 = aux;
            }else if(aux > m2) {
                m2 = aux;
            }
            qttd = max(qttd, m1 + m2);
		}
		else if(v != parent[u]){
			low[u] = min(low[u], disc[v]);
		}
	}

    return m1;
}

int dfs(){
    return tarjan(0);
}

void solve(){

    init();

    int cnt = dfs();

    cout << szPontes - qttd << endl; 
}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
		cin >> N >> M;

        for(int i = 0, u, v ; i < M ; i++) {
            cin >> u >> v;
            
            u--, v--;

            adj[u].pb(v);
            adj[v].pb(u);
        }

		solve();

        for(int i = 0 ; i < N ; i++) adj[i].clear();
    }

	return 0;
}