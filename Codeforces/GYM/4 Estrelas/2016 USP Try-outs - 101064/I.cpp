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
vector<vector<int>> adj, edge;
int vis[MAXN], cnt;

bool dfs(int u, int p){
	
	vis[u] = ++cnt;

	for(auto v : adj[u]){

		//Se não estou usando aquela aresta para esse filho, adiciono ela em mim
		if(!vis[v] && !dfs(v,u)) edge[u].pb(v); 

		//Se estou acessando alguém comtempo menor que o meu
		//Quer dizer que estou indo para um ancestral na árvore
		//Quando isso acontece o algoritmo joga a aresta para o vértice filho
		if(vis[v] < vis[u] && v != p){
			edge[u].pb(v);
		}
	}

	//Se falta uma aresta para completar, pego a aresta que me liga ao meu pai
	//e retorno que estou usando aquela aresta
	if(edge[u].size() & 1){
		edge[u].pb(p);
		return true;
	}

	return false;
}

void solve(){

	dfs(0,-1);

	cout << (M>>1) << endl;

	for(int i=0;i<N;i++) {
		for(int j=0;j<edge[i].size();j+=2){
			cout << edge[i][j] + 1 << " " << i + 1 << " " << edge[i][j + 1] + 1 << endl; 
		}
	}
}

int main(){

	optimize;
	
    cin >> N >> M;

    adj.resize(N);
	edge.resize(N);

    for(int i=0;i<M;i++){
        int a,b;

        cin >> a >> b;

        a--, b--;

        adj[a].pb(b);
        adj[b].pb(a);
    }	
    
    solve();

	return 0;
}