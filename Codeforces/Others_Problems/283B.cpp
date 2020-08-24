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
#define MAXN 2000010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K,X,Y;
int v[MAXN];
int vis[MAXN][2];
vector<vector<int>> adj[2];
ll dp[MAXN][2];

ll dfs(int u, int t, int cod){

	vis[u][t] = cod;
	
	if(dp[u][t] != -1 ) return dp[u][t];

	for(auto i : adj[t][u]){
		if( i <= 0 || i > N) return dp[u][t] = abs(u-i);
		else{
			if(vis[i][t^1] == cod) return dp[u][t] = INFLL;
			if(i == 1){
				if(!t) return dp[u][t] = abs(u-i);
				else return dp[u][t] = INFLL;
			}else{
				ll aux = dfs(i,t^1,cod);
				if(aux == INFLL) return dp[u][t] = aux;
				else return dp[u][t] = abs(u-i) + aux;
			}
		}
	}
}

void solve(){
	
	adj[0].resize(N+1);
	adj[1].resize(N+1);

	FOR(i,2,N+1){
		adj[0][i].pb(i+v[i]);
		adj[1][i].pb(i-v[i]);
	}

	ms(dp, -1);

	FOR(i,2,N+1) if(!vis[i][1]) dfs(i,1,i);

	FOR(i,1,N){
		if(dp[1+i][1] == INFLL) cout << -1 << endl;
		else cout << dp[i+1][1] + i << endl;
	}

}

int main(){

    cin >> N;

    FOR(i,2,N+1) cin >> v[i];

    solve();

	return 0;
}