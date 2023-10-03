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
string s, t;
bool ok;

void dfs(int u, int p, vector<vector<int>> & adj) {

	int k = 0, f = 0;

	for(int v: adj[u]) {
		if(v != p) {
			dfs(v, u, adj);

			if(t[v] == s[u]) k++;			
			f++;
		}
	}

	// Raiz
	if(u == 0) {
		// Raiz ou é definida pelos filhos ou pode ser qualquer coisa ou é inválida
		if(2 * k < f) {
			ok = false;
		}
	}
	else {  // Outros
		if(2 * k > f) {
			if(t[u] == '0') t[u] = s[p];
		}
		else if(2 * k == f) {
			if(t[p] != '0' && t[p] != s[u]) ok = false;
			
			t[p] = s[u];

			if(t[u] == '0') t[u] = s[p];
		}
		else {
			ok = false;
		}
	}
}

void solve() {

	cin >> N;

	vector<vector<int>> adj(N);
	t.assign(N, '0');
	ok = true;

	for(int i = 0, u, v; i < N - 1; i++) {
		cin >> u >> v;

		u--, v--;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	cin >> s;

	dfs(0, -1, adj);
	
	if(t[0] == '0') t[0] = 'B';

	if(ok) 	cout << t << endl;
	else 	cout << -1 << endl;
}

int main() {

	optimize;
	
	T = 1;
	
	cin >> T;

    while(T--) {
		solve();
    }

	return 0;
}
