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
#define MAXN 10010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
bool vis[MAXN];
int A[MAXN];
vector<vector<pii>> adj;

vector<int> dijkstra(int s){

    vector<int> d(N,INF);
    ms(vis, 0);

    d[s] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.push(pii(0,s));

    while(!pq.empty()){
        int u = pq.top().se;
        int w = pq.top().fi;

        pq.pop();

        if(vis[u]) continue;
        
        vis[u] = true;

        for(auto i : adj[u]){
            if(!vis[i.fi]){
                vis[i.fi] == true;

                if(d[i.fi] > d[u] + i.se){
                    d[i.fi] = d[u] + i.se;
                    pq.push(pii(d[u] + i.se, i.fi));
                }
            }
        }
    }

    return d;
}

void solve(){

    vector<int> indo = dijkstra(A[0] - 1);
    vector<int> volt = dijkstra(A[K-1] - 1);

    int cnt = 0;

    for(int i=0;i<N;i++){
        for(int j=0;j<adj[i].size();j++){
            int u = adj[i][j].fi;
            int w = adj[i][j].se;

            if(indo[i] + w + volt[ u ] == indo[ A[K-1] - 1 ]) cnt++;
        }
    }

    if(cnt >= K)    cout << "yes\n";
    else            cout << "no\n";
}

int main(){

	optimize;
	
	cin >> N >> M >> K;

    for(int i=0;i<K;i++) cin >> A[i];

    adj.resize(N);

    for(int i=0,u,v,w;i<M;i++){
        cin >> u >> v >> w;

        u--, v--;

        adj[u].pb(pii(v,w));
        adj[v].pb(pii(u,w));
    }
		
	solve();

	return 0;
}