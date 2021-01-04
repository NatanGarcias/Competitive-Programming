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
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;

#define MAXN 2009
vector<int> B;
vector< bitset<MAXN> > A;
bitset<MAXN> x;

bool check() {
	int n = A.size(), m = MAXN;
	for(int i = 0; i < n; i++) {
		int acum = 0;
		for(int j = 0; j < m; j++) {
			if (A[i][j]) acum ^= x[j];
		}
		if (acum != B[i]) return false;
	}
	return true;
}

bool gaussxor() {
	int cnt = 0, n = A.size(), m = MAXN;
	bitset<MAXN> vis; vis.set();
	for(int j = m-1, i; j >= 0; j--) {
		for(i = cnt; i < n; i++) {
			if (A[i][j]) break;
		}
		if (i == n) continue;
		swap(A[i], A[cnt]); swap(B[i], B[cnt]);
		i = cnt++; vis[j] = 0;
		for(int k = 0; k < n; k++) {
			if (i == k || !A[k][j]) continue;
			A[k] ^= A[i]; B[k] ^= B[i];
		}
	}
	x = vis;
	for(int i = 0; i < n; i++) {
		int acum = 0;
		for(int j = 0; j < m; j++) {
			if (!A[i][j]) continue;
			if (!vis[j]) {
				vis[j] = 1;
				x[j] = acum^B[i];
			}
			acum ^= x[j];
		}
		if (acum != B[i]) return false;
	}
	return true;
}

bool par[MAXN];
vector<vector<int>> adj;
	
void solve(){

	for(int i=0;i<N;i++) sort(all(adj[i]));

	for(int i=0;i<N;i++){
		bitset<MAXN> aux;

		for(int j=0;j<adj[i].size();j++){
			aux[adj[i][j]] = 1;
		}

		A.pb(aux);
		if(par[i])	B.pb(1);
		else		B.pb(0);
	}

	if(gaussxor())	cout << "Y\n";
	else 			cout << "N\n";
}

int main(){

	optimize;
	
	cin >> N >> M;
		
	adj.resize(N);


	for(int i=0;i<M;i++){
		int a,b;

		cin >> a >> b;
		
		a--, b--;

		adj[a].pb(b);
		adj[b].pb(a);
	}	

	for(int i=0;i<N;i++) {
		if(adj[i].size()&1)
			adj[i].pb(i);
		else
			par[i] = true;
	}
	
	solve();
    
	return 0;
}