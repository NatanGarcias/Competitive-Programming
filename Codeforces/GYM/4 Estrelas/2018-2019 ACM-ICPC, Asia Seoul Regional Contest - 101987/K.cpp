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
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 200010
#define MAXM 20010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;

int n; 
vector<vector<int>> adj, adj2;
vector<int> order;
int comp[MAXN];
bool vis[MAXN], valor[MAXN];

struct Pessoa{
	int x[3];
	bool y[3];
};

Pessoa p[MAXM];

void dfs(int v) {
    vis[v] = true;
    for (int u : adj[v]) {
        if (!vis[u])
            dfs(u);
    }
    order.push_back(v);
}

void dfs2(int v, int cl) {
    comp[v] = cl;
    for (int u : adj2[v]) {
        if (comp[u] == -1) dfs2(u, cl);
    }
}

void compConexo() {
    for (int i = 0; i < n; ++i) {
        if (!vis[i])
            dfs(i);
    }

    ms(comp, -1);

    for (int i = 0, j = 0; i < n; ++i) {
        int v = order[n - i - 1];
        if (comp[v] == -1) dfs2(v, j++);
    }
}

bool solve_2SAT(){
    
    compConexo();

    for (int i = 0; i < n; i += 2) {
        if (comp[i] == comp[i + 1]) return false;
        valor[i / 2] = comp[i] > comp[i + 1];
    }
    
    return true;
}

void addEdge(int x, int y){
    adj[x].push_back(y);
    adj2[y].push_back(x);
}

void solve(){

    adj.resize(2*N);
    adj2.resize(2*N);

    n = 2*N;

    for(int i=0;i<M;i++){
        int v[3];
        bool cnt[3] = {0};
        pii pos[3] = { pii(0,1) , pii(0,2), pii(1,2)};

        for(int j=0;j<3;j++){
            v[j] = 2 * p[i].x[j];
            if(p[i].y[j]) cnt[j] = 1;
        }

        for(int j=0;j<3;j++){
            if(cnt[ pos[j].fi ]){
                if(cnt[ pos[j].se ]){
                    addEdge(v[ pos[j].fi ] + 1, v[ pos[j].se ]);
                    addEdge(v[ pos[j].se ] + 1, v[ pos[j].fi ]);
                }
                else{
                    addEdge(v[ pos[j].fi ] + 1, v[ pos[j].se ] + 1);
                    addEdge(v[ pos[j].se ] , v[ pos[j].fi ]);
                }
            }
            else{
                if(cnt[ pos[j].se ]){
                    addEdge(v[ pos[j].fi ] , v[ pos[j].se ]);
                    addEdge(v[ pos[j].se ] + 1, v[ pos[j].fi ] + 1);
                }
                else{
                    addEdge(v[ pos[j].fi ] , v[ pos[j].se ] + 1 );
                    addEdge(v[ pos[j].se ] , v[ pos[j].fi ] + 1 );
                }
            }
        }
    }

	bool ans = solve_2SAT();

    if(ans){
        for(int i=0;i<N;i++)
            cout << (valor[i] ? 'R' : 'B');
        cout << "\n";
    }
    else{
        cout << -1 << endl;
    }

}

int main(){

	optimize;
	
	cin >> N >> M;

	for(int i=0;i<M;i++){
		for(int j=0;j<3;j++){
			char k;

			cin >> p[i].x[j] >> k;

            p[i].x[j]--;

			if(k == 'R') 	p[i].y[j] = 1;
			else 			p[i].y[j] = 0;
		}
	}

	solve();

	return 0;
}