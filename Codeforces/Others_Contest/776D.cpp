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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;

int n;
vector<vector<int>> adj, adj2;
vector<int> order; 
int comp[MAXN]; 
bool vis[MAXN], valor[MAXN], v[MAXN];

struct Porta{
	vector<int> x;

	Porta(){
		x.reserve(2);
	}
};

Porta p[MAXN];

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
        if (comp[v] == -1)
            dfs2(v, j++);
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

//Já adiciono a contra-positiva e no grafo reverso
void addEdge(int x, int y){
    adj[x].push_back(y);
    adj2[y].push_back(x);

    adj[y ^ 1].push_back(x ^ 1);
    adj2[x ^ 1].push_back(y ^ 1);
}

void solve(){
    
    n = 2*M;

    for(int i=0;i<N;i++){
        if(v[i]){
            addEdge(2 * p[i].x[0] , 2 * p[i].x[1]);
            addEdge(2 * p[i].x[0] + 1 , 2 * p[i].x[1] + 1);
        }
        else{
            addEdge(2 * p[i].x[0] , 2 * p[i].x[1] + 1);
            addEdge(2 * p[i].x[0] + 1, 2 * p[i].x[1]);
        }
    }

    bool ans = solve_2SAT();

    if(ans) cout << "YES\n";
    else    cout << "NO\n";
}

int main(){

	optimize;
	
	cin >> N >> M;
		
	for(int i=0;i<N;i++) cin >> v[i];

	adj.resize(2*M);
	adj2.resize(2*M);

    for(int i=0;i<M;i++){
		int a;
		cin >> a;

		for(int j=0;j<a;j++) {
            int b;
            cin >> b;

			p[--b].x.push_back(i);
		}
	}

    solve();

	return 0;
}