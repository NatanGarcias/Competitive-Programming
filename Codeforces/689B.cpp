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

#define PI 3.141592653589793238462643383279502884
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
vector<vector<int>> adj;
int vis[MAXN];
int p[MAXN];

void bfs(){
	queue<pii> fila;

	fila.push(pii(0,0));

	vis[0] = true;

	while(!fila.empty()){
		int u = fila.front().fi;
		int t = fila.front().se;
		fila.pop();

		for(auto i : adj[u]){
			if(!vis[i]){
				vis[i] = true;
				p[i] = t+1;
				fila.push(pii(i,t+1));
			}
		}
	}
}

void solve(){

	bfs();

	FOR(i,0,N) cout << p[i] << " \n"[i==N-1];
}

int main(){

	cin >> N;
	
	adj.resize(N);
	
	FOR(i,0,N){
		int a;
		
		cin >> a;

		a--;

		adj[i].pb(a);
	}
	
	FOR(i,0,N-1){
		adj[i].pb(i+1);
		adj[i+1].pb(i);
	}

	solve();

	return 0;
}