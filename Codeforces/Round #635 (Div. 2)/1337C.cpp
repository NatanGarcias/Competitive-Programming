#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld; 

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define space " " 

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
#define MAXN 200010

ll T,X,N,M;
vector<vector<int>> adj;
ll v[MAXN];
ll alt[MAXN];
bool industria[MAXN];
ll v2[MAXN];
bool vis[MAXN];

ll dfs(int x, int h){

	vis[x] = true;
	alt[x] = h;

	ll cont = 0;

	for(auto i: adj[x]){
		if(!vis[i]){
			cont = cont + dfs(i,h+1) + 1;
		}
	}

	v[x] = cont;

	return cont;
}

void dfs2(int x, int happy){

	vis[x] = true;

	if(!industria[x]) happy++;

	v2[x] = happy;

	for(auto i: adj[x]){
		if(!vis[i]){
			dfs2(i, happy);
		}
	}
}

void solve(){

	dfs(0,0);

	priority_queue<tuple<int,int>> pq;

	FOR(i,0,N){
		auto a = make_tuple( alt[i] - v[i], i);
		pq.push(a);
	}

	while(M--){
		auto u = pq.top();
		pq.pop();

		industria[ get<1>(u) ] = true;
	}

	ms(vis,0);

	dfs2(0,0);
	
	ll ans = 0;
	FOR(i,0,N){
		if(industria[i]) ans += v2[i];
	}

	cout << ans << endl;
}	

int main(){

   	cin >> N >> M;

   	adj.resize(N);

   	int a,b;

   	FOR(i,0,N-1){
   		cin >> a >> b;

   		a--; b--;

   		adj[a].pb(b);
   		adj[b].pb(a);
   	}
	
	solve();
   	
	return 0;
}