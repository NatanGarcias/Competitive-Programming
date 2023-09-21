#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;

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
bool vis[MAXN];
pii ans[MAXN];
vector<pii> adj[MAXN];
pii edge[2 * MAXN];

void bfs(ll s) {

    queue<ll> q;

    q.push(s);

    while(q.size()) {
        ll u = q.front();
        q.pop();

        for(ll i = 0; i < adj[u].size(); i++) {
            ll v = adj[u][i].first;
            ll e = adj[u][i].second;

            if(!vis[v]) {
                ans[v].first = ans[u].first + edge[e].first;
                ans[v].second = ans[u].second + edge[e].second;

                vis[v] = true;

                q.push(v);
            }
        }
    }
}

void solve() {

	cin >> N >> M;
    
    for(int i = 0; i < M; i++) {

        ll u, v, x, y;

        cin >> u >> v >> x >> y;

        u--, v--;

        adj[u].push_back({v, i});
        adj[v].push_back({u, i + M});

        edge[i] = make_pair(x, y);
        edge[i + M] = make_pair(-x, -y);
    }

    bfs(0);

    vis[0] = true;
    ans[0] = make_pair(0, 0);

    for(int i = 0; i < N; i++) {
        if(vis[i])    cout << ans[i].first << " " << ans[i].second << endl;
        else        cout << "undecidable" << endl;
    }

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
