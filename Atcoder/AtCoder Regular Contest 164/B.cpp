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
vector<int> adj[MAXN];
int A[MAXN], vis[MAXN];

struct UF{
	vector<int> parent, rank;

	UF(){}	

    void resize(int n){
		parent.assign(n + 1, 0);
		rank.assign(n + 1, 0);
		iota(all(parent), 0);
	}	

	int find(int u){
		if(u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}

	bool sameSet(int u, int v){
		return find(u) == find(v);
	}

	void unir(int u, int v){
		u = find(u);
		v = find(v);

		if(u != v){
			if(rank[u] < rank[v]) swap(u,v);
			if(rank[u] == rank[v]) rank[u]++;
			
			parent[v] = u;
		}
	}
};

UF uf;

void dfs(int u) {

    vis[u] = true;

    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];

        if(!vis[v] && A[v] != A[u]) {
            uf.unir(u, v);
            dfs(v);
        }
    }
}

void solve() {

	cin >> N >> M;

    uf.resize(N);

    vector<pii> edge;

    for(int i = 0; i < M; i++) {
        int u, v;

        cin >> u >> v;

        u--, v--;

        adj[u].push_back(v);
        adj[v].push_back(u);

        edge.push_back({u, v});
    }

    for(int i = 0; i < N; i++) cin >> A[i];

    for(int i = 0; i < N; i++) if(!vis[i]) dfs(i);

    int ok = 0;

    for(int i = 0; i < M; i++) {
        int u = edge[i].first;
        int v = edge[i].second;

        if(uf.sameSet(u, v) && A[u] == A[v]) {
            ok = true;
            break;
        }
    }

    if(ok)  cout << "Yes\n";
    else    cout << "No\n";
}

int main() {

	optimize;
	
	T = 1;
	
	//cin >> T;

    while(T--) {
		solve();
    }

	return 0;
}
