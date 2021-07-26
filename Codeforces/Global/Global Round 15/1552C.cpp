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
#define MAXN 2010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
vector<pii> edge;

void solve(){

	vector<bool> vis(2*N + 1,0);

	for(int i=0;i<M;i++){
		int u = edge[i].fi;
		int v = edge[i].se;

		vis[u] = true;
		vis[v] = true;
	}

	vector<int> unvis;
	for(int i=1;i<=2*N;i++) if(!vis[i]) unvis.pb(i);

	while(!unvis.empty()){
		int u = unvis.back();
		unvis.pop_back();
		
		vis[u] = true;

		int n = unvis.size();
		int v = unvis[n/2]; 

		unvis.erase(unvis.begin() + n/2);

		if(u > v) swap(u,v);

		edge.emplace_back(u,v);
	}

	int ans = 0;

	for(int i=0;i<N;i++){
		int u = edge[i].fi;
		int v = edge[i].se;

		for(int j=0;j<N;j++){
			if(i == j) continue;

			int u2 = edge[j].fi;
			int v2 = edge[j].se;

			if(u2 > u && u2 < v && v2 > v) ans++;
		}
	}

	cout << ans << endl;
}

int main(){

	optimize;
	
	cin >> T;

	while(T--){
		cin >> N >> M;
		
		for(int i=0,u,v;i<M;i++){
			cin >> u >> v;

			if(u > v) swap(u,v);
			edge.emplace_back(u,v);
		}

		solve();
		edge.clear();
	}

	return 0;
}