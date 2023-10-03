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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;

// Block-Cut Tree
//
// Cria a block-cut tree, uma arvore com os blocos
// e os pontos de articulacao
// Blocos sao componentes 2-vertice-conexos maximais
// Uma 2-coloracao da arvore eh tal que uma cor sao
// os blocos, e a outra cor sao os pontos de art.
// Funciona para grafo nao conexo
//
// art[i] responde o numero de novas componentes conexas
// criadas apos a remocao de i do grafo g
// Se art[i] >= 1, i eh ponto de articulacao
// 
// Para todo i <= blocks.size()
// blocks[i] eh uma componente 2-vertce-conexa maximal
// edgblocks[i] sao as arestas do bloco i
// tree[i] eh um vertice da arvore que corresponde ao bloco i
// 
// pos[i] responde a qual vertice da arvore vertice i pertence
// Arvore tem no maximo 2n vertices
//
// O(n+m)

struct block_cut_tree {
	vector<vector<int>> g, blocks, tree;
	vector<vector<pair<int, int>>> edgblocks;
	stack<int> s;
	stack<pair<int, int>> s2;
	vector<int> id, art, pos;
	
	block_cut_tree(vector<vector<int>> g_) : g(g_) {
		int n = g.size();
		id.resize(n, -1), art.resize(n), pos.resize(n);
		build();
	}

	int dfs(int i, int& t, int p = -1) {
		int lo = id[i] = t++;
		s.push(i);	
		
		if (p != -1) s2.emplace(i, p);
		for (int j : g[i]) if (j != p and id[j] != -1) s2.emplace(i, j);
		
		for (int j : g[i]) if (j != p) {
			if (id[j] == -1) {
				int val = dfs(j, t, i);
				lo = min(lo, val);

				if (val >= id[i]) {
					art[i]++;
					blocks.emplace_back(1, i);
					while (blocks.back().back() != j) 
						blocks.back().push_back(s.top()), s.pop();

					edgblocks.emplace_back(1, s2.top()), s2.pop();
					while (edgblocks.back().back() != pair(j, i))
						edgblocks.back().push_back(s2.top()), s2.pop();
				}
				// if (val > id[i]) aresta i-j eh ponte
			}
			else lo = min(lo, id[j]);
		}
		
		if (p == -1 and art[i]) art[i]--;
		return lo;
	}

	void build() {
		int t = 0;
		for (int i = 0; i < g.size(); i++) if (id[i] == -1) dfs(i, t, -1);
		
		tree.resize(blocks.size());
		for (int i = 0; i < g.size(); i++) if (art[i]) 
			pos[i] = tree.size(), tree.emplace_back();

		for (int i = 0; i < blocks.size(); i++) for (int j : blocks[i]) {
			if (!art[j]) pos[j] = i;
			else tree[i].push_back(pos[j]), tree[pos[j]].push_back(i);
		}
	}
};

vector<vector<int>> adj2, adj;

#define MAXN 400100
#define MAXL 25
int level[MAXN], dp[MAXN][MAXL], cnt[MAXN], art[MAXN], pos[MAXN];

void dfs(int v, int p){
    dp[v][0] = p;

	cnt[v] = art[v];

	if(p >= 0) cnt[v] += cnt[p];
	
    level[v] = level[p] + 1;
    
    for (int i = 1; i < MAXL; i++)
        dp[v][i] = dp[dp[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }
}

int LCA(int u, int v){
    
    if(level[u] < level[v]) swap(u,v);

    for(int i = MAXL-1; i >= 0; i--){
        if(dp[u][i] && level[ dp[u][i] ] >= level[v])
            u = dp[u][i];
    }

    if(u == v) return u;

    for(int i = MAXL-1; i >= 0; i--){
        if(dp[u][i] != dp[v][i]){
            u = dp[u][i];
            v = dp[v][i];
        }
    }
    
    return dp[u][0];
}

int dist(int u, int v){
	int x = LCA(u,v);
    return cnt[u] + cnt[v] - 2 * cnt[x] - art[u] - art[v] + art[x];
}

void preCalc() {
	block_cut_tree bct(adj2);

	adj.resize(bct.tree.size());	

	for(int i = 0; i < bct.pos.size(); i++) pos[i] = bct.pos[i];
	for(int i = 0; i < bct.art.size(); i++) art[pos[i]] = (bct.art[i] >= 1);

	for(int u = 0; u < bct.tree.size(); u++) {
		for(int v : bct.tree[u]) {
			adj[u].push_back(v);
		}
	}

    level[0] = -1;

    dfs(0, -1);
}

void solve() {

	cin >> N >> M;

	adj2.resize(N);

	for(int i = 0, u, v; i < M; i++) 	{
		cin >> u >> v;

		u--, v--;

		adj2[u].push_back(v);
		adj2[v].push_back(u);
	}
		
	cin >> K;

	preCalc();

	for(int i = 0, u, v; i < K; i++) {
		cin >> u >> v;

		u--, v--;

		u = pos[u];
		v = pos[v];

		cout << dist(u, v) << endl;
	}
}

int main() {

	optimize;
	
	T = 1;

    while(T--) {
		solve();
    }

	return 0;
}
