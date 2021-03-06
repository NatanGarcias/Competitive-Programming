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
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;

vector<vector<pii>> adj;
ll nums[MAXN];
bool vis[MAXN];

void dfs(int u, ll d){
	vis[u] = true;
	
	for(auto i : adj[u]){
		if(!vis[i.fi] && d + i.se <= nums[i.fi]) dfs(i.fi, max(0LL, d + i.se ));	
	}
}

void solve(){

	dfs(0,0LL);

	ll ans = 0;
	
	FOR(i,0,N) if(vis[i]) ans++;
	
	cout << N - ans << endl;
}

int main(){

	cin >> N;

	FOR(i,0,N) cin >> nums[	i];
	
	adj.resize(N);

	FOR(i,0,N-1){
		ll a,b;
		cin >> a >> b;

		a--;

		adj[i+1].pb(pii(a,b));
		adj[a].pb(pii(i+1,b));
	}

	solve();

	return 0;
}