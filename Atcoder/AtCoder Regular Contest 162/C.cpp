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
#define MAXN 12345

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;

int A[MAXN], B[MAXN];
vector<int> adj[MAXN];

struct MEX {
    vector<int> vis;
    int ans;
    int emp;

    MEX() {
        vis.assign(N + 2, 0); 
        ans = 0;
        emp = 0;
    }

    void add(int u) {
        if(u == -1) {
            emp++;
            return;
        }

        vis[u] = 1;
        while(vis[ans]) ans++;
    }

    int get() {
        return ans;
    }

    bool win() {
        if(ans == K && emp <= 1) return true;
        if(emp == 1){
            add(ans);
            return (get() == K);
        }
        return false;
    }
};

void dfs(int u, int p, MEX &mex) {

    mex.add(B[u]);

    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];

        if(v != p) dfs(v, u, mex);
    }
}

void solve() {

	cin >> N >> K;

    for(int i = 0; i < N; i++) adj[i].clear();

    A[0] = -1;

    for(int i = 1, u; i < N; i++) {
        cin >> u;

        u--;

        A[i] = u;

        adj[u].push_back(i);
        adj[i].push_back(u);
    }

    for(int i = 0; i < N; i++) cin >> B[i];
    
    // Calculo do mex para cada subarvore
    for(int i = 0; i < N; i++) {
        MEX mex;

        dfs(i, A[i], mex);

        if(mex.win()) {
            cout << "Alice\n";
            return;
        }
    }

    cout << "Bob\n";
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
