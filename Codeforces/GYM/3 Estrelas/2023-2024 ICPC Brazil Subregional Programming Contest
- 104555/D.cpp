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
#define MAXN 301

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;

int d[MAXN][MAXN];
vector<tuple<int, int, int>> in;
vector<pii> adj[MAXN];

void solve() {

	cin >> N >> M;
    
    ms(d, INF);

    for(int i = 0, u, v, w; i < M; i++) {
        cin >> u >> v >> w;

        u--, v--;

        in.emplace_back(u, v, w);
        d[u][v] = d[v][u] = w;

        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    for(int k = 0; k < N; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    for(auto [s, t, w] : in) {

        if(d[s][t] < w) {
            cout << d[s][t] << endl;
            continue;
        }

        vector<int> dist(N, INF);
        vector<int> vis(N, 0);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        
        dist[s] = 0;
        pq.push({0, s});

        while(!pq.empty()) {
            auto [e, u] = pq.top();
            pq.pop();

            if(u == t) break;
            if(vis[u]) continue;

            vis[u] = true;

            for(auto [v, w1] : adj[u]) {
                if(u == s && v == t) continue; 

                if(dist[v] > dist[u] + w1) {
                    dist[v] = dist[u] + w1;
                    pq.push({dist[v], v});
                }
            }
        }

        if(dist[t] == INF) dist[t] = -1;
        cout << dist[t] << endl;
    }
}

int main() {

	optimize;
	
	T = 1;

    while(T--) {
		solve();
    }

	return 0;
}
