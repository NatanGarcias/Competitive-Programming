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
vector<int> adj[MAXN];
int A[MAXN], ans[MAXN];
vector<int> q;

void dfs(int u, int p) {

    auto it = lower_bound(q.begin(), q.end(), A[u]);
    int pos = -1, prv = -1;

    if(it == q.end()) {
        q.push_back(A[u]);
    }
    else {
        pos = it - q.begin();
        prv = q[pos];
        q[pos] = A[u];
    }

    ans[u] = q.size();

    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];

        if(v != p) dfs(v, u);
    }

    if(prv == -1) q.pop_back();
    else q[pos] = prv; 
}

void solve() {

	cin >> N;
    
    for(int i = 0, u; i < N - 1; i++) {
        cin >> u;

        adj[u - 1].push_back(i + 1);
    }

    for(int i = 0; i < N; i++) cin >> A[i];

    dfs(0, -1);

    for(int i = 1; i < N; i++) cout << ans[i] << " \n"[i == N - 1];
}

int main() {

	optimize;
	
	T = 1;
	
	//cin >> T;

    while(T--) {
		solve();
    }

	return 0;
}
