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

int A[MAXN], B[MAXN], vis[MAXN];
int ans = 0;

int getCost(int u, int id) {
    int m = INF;

    while(vis[u] == id) {
        m = min(m , A[u]);
        vis[u] += N;
        u = B[u];     
    }

    return m;
}

void bfs(int u, int id) {

    if(vis[u]) {
        if(vis[u] != id)    return;
        else                ans += getCost(B[u], id);
    }

    vis[u] = id;

    if(B[u] == u)   ans += A[u];
    else            bfs(B[u], id);
}

void solve() {
    for(int i = 0; i < N; i++) if(!vis[i]) bfs(i, i + 1); 
    cout << ans << endl;
}

int main() {

	cin >> N;

    for(int i = 0; i < N; i++)	cin >> A[i];
    for(int i = 0; i < N; i++)	cin >> B[i];
    for(int i = 0; i < N; i++)	B[i]--;

	solve();
    
	return 0;
}