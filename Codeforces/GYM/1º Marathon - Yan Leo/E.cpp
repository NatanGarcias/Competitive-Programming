#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld; 

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

#define pii pair<int,int>
#define fi first 
#define se second 
#define pb push_back

#define sz(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define FOR(x,a,n) for(int x= (int)(a);(x) < int(n);(x)++)
#define ms(x,a) memset(x,a,sizeof(x))

#define PI 3.141592653589793238462643383279502884
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007
#define MAXN 2010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;

int v[MAXN][MAXN];
vector<vector<int>> adj;
int ans = 1;
int vis[MAXN];
int vis2[MAXN];

void dfs(int u){
	
	vis2[u] = true;
	vis[u] = true;

	for(auto i : adj[u]){
		if(!vis[i]) {
			if(u < i) v[u][i] = 1;
			else v[i][u] = 1;
			dfs(i);
		}else if(!vis2[i]){
			if(u < i) v[u][i] = 1;
			else v[i][u] = 1;
		}
		else if(vis2[i]){
			ans = 2;
			if(u < i) v[u][i] = 2;
			else v[i][u] = 2;
		}
	}
	vis2[u] = false;
}

void solve(){

	FOR(i,0,N) if(!vis[i]) dfs(i);

	cout << ans << endl;
	FOR(i,0,N) FOR(j,i+1,N) cout << v[i][j] << " \n"[j==N-1];
}

int main(){
	
	optimize;
	
	cin >> N;		

	adj.resize(N);

	FOR(i,0,N){
		FOR(j,0,N){
			int a;
			cin >> a;

			if(a) adj[i].pb(j);
		}
	}

	solve();

	return 0;
}