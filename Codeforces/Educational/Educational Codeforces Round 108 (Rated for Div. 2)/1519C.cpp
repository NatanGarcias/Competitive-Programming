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

vector<vector<ll>> adj, adj2;
ll A[MAXN], B[MAXN];

struct compare{
  	bool operator()(vector<ll> &l, vector<ll> &r){
    	return l.size() > r.size();
    }
};

void solve(){

	sort(all(adj), compare());
	
	for(int i=0;i<N;i++) {
		sort(all(adj[i]));
		reverse(all(adj[i]));
	}

	for(int i=0;i<N;i++) {
		adj2[i].pb(0);

		for(int j=0;j<adj[i].size();j++){
			adj2[i].pb( adj2[i][j] + adj[i][j] );
		}
	}

	vector<ll> ans(N,0);

	for(int i=1;i<=N;i++){
		ll aux = 0;

		for(int j=0;j<N;j++){

			if(adj[j].size() >= i){
				ll p = adj[j].size()/i;
				p = p * i;
				aux += adj2[j][p];
			}
			else break; 
		}

		ans[i-1] = aux;

		if(!aux) break;
	}

	for(int i=0;i<N;i++) cout << ans[i] << " \n"[i==N-1];

}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
		cin >> N;

		adj.resize(N);
		adj2.resize(N);

		for(int i=0;i<N;i++) cin >> A[i];
		for(int i=0,u;i<N;i++){
			cin >> u;
			adj[ A[i]-1 ].pb(u);
		}
		
		solve();

		for(int i=0;i<N;i++) adj[i].clear();
		for(int i=0;i<N;i++) adj2[i].clear();
    }

	return 0;
}