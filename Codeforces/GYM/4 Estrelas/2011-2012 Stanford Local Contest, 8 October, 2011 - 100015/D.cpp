#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<int,ld> pid;

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
#define MAXN 10100

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
vector<vector<pid>> adj, adj2;
ld dp[MAXN][2], sum[MAXN], sumW[MAXN];

ld dfs(int i, bool j){

	if(adj[i].empty()) 	return 0.0;

	if(dp[i][j] != -1.0) return dp[i][j];

	ld a = 0.0, b = 0.0;

	for(auto u : adj[i]){
		dfs(u.fi,0);

		a += u.se;
		b += (u.se * (1.0L + dfs(u.fi,0) ) );
	}

	sumW[i] = a;
	sum[i] = b; 
	
	ld aux = b / (a * 1.0L);
	
	return dp[i][j] = aux;
}

int root;

ld prob(int i, int j){
	
	if(dp[i][j] != -1.0) return dp[i][j];

	ld aux = 0.0;

	if(i == root) return dp[i][j] = 1.0;

	for(auto u : adj2[i]){
		if(dfs(u.fi,0) != -1.0) aux += prob(u.fi,j) * u.se / sumW[u.fi];
	}

	return dp[i][j] = aux;
}


void solve(){

	for(int i=0;i<N;i++){
		dp[i][0] = -1.0;
		dp[i][1] = -1.0;
	}

	ld ans = dfs(root,0);
	ld best = 0.0;

	for(int i=0;i<N;i++){
		if(dfs(i,0) != -1.0 && adj[i].size() > 1){
			for(auto u : adj[i]){
				// Best = Probabilidade de chegar no vértice i * 
				// ( o maior comprimento possível experado começando no vértice i excluindo a aresta i->u.fi * a probabilidade daquela aresta 
				// - o maior comprimento possível experado começando no vértice i)

				// == Probabilidade de chegar no vértice i * 
				// chance de excluir a aresta i-u.fi * quantos ganho excluindo aquela aresta
				best = max(best, prob(i, 1) * ( (sum[i] - (1.0L + dfs(u.fi,0) ) * u.se) / (sumW[i] - u.se) - dfs(i,0) ) );
			}
		}
	}
	
	cout << root << ": ";
	cout << fixed << setprecision(8) << ans << " "; 
	cout << fixed << setprecision(8) << ans + best << endl; 

	//cout << fixed << setprecision(8) << ans + best << endl; 
}

int main(){

	optimize;
	
	while(cin >> N >> M){
		if(!N && !M) break;

		adj.resize(N);
		adj2.resize(N);

		for(int i=0;i<M;i++){
			int a, b;
			ld c;

			cin >> a >> b >> c;

			adj[a].pb(pid(b,c));
			adj2[b].pb(pid(a,c));
		}

		root = 12;
		solve();
		

		adj.clear();
		adj2.clear();
    }

	return 0;
}