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

ll T,N,M,K,A,B;
vector<vector<int>> adj;
int vis[MAXN], cnt[MAXN];

void bfs(int u){

	vis[u] = true;

	queue<int> fila;

	fila.push(u);

	while(!fila.empty()){
		int v = fila.front();
		fila.pop();

		for(int i: adj[v]){
			if(vis[i]) continue;

			cnt[i]++;

			if(cnt[i]*2 >= adj[i].size()){
				vis[i] = true;
				fila.push(i);
			}
		}
	}
}

void solve(){

	A--, B--;

	bfs(B);

	if(vis[A])  cout << "leave\n";
	else 		cout << "stay\n";
}

int main(){

	optimize;
		
	cin >> N >> M >> A >> B;
		
	adj.resize(N);

	for(int i=0,u,v;i<M;i++){
		cin >> u >> v;

		u--, v--;

		adj[u].pb(v);
		adj[v].pb(u);
	}

	solve();

	return 0;
}