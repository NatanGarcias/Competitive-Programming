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
#define MAXN 20010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
vector<pii> adj[MAXN];

ll dijkstra(int s, int t, ll costMax){

    vector<ll> dist(N, INFLL);
    vector<bool> vis(N, 0);

    priority_queue<pii, vector<pii>, greater<pii> > pq;

    pq.push(pii(0,s));
    dist[s] = 0;

    while(!pq.empty()){
        int u = pq.top().se;

        pq.pop();

        if(vis[u]) continue;
        vis[u] = true;

        for(auto i : adj[u]){
            int v = i.fi;
            ll w = i.se;

            if(w <= costMax && dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push(pii(dist[v],v));
            }
        }
    }

    return dist[t];
}

bool f(ll x){
    if(dijkstra(0,N-1,x) <= K) return true;
    return false;
}

ll bb(){

    ll l = 1, r = INFLL;

    while(l < r){
        ll m =(l+r)/2;

        if(f(m)) r = m;
        else l = m + 1;
    }

    return l;
}

void solve(){
    cout << bb() << endl;
}

int main(){

	cin >> N >> M >> K;
		
    for(int i=0;i<M;i++){
        ll u,v,w;

        cin >> u >> v >> w;

        u--, v--;

        adj[u].pb(pii(v,w));
        adj[v].pb(pii(u,w));
    }

    K = ( (K+100)/100.0 ) * dijkstra(0,N-1,INFLL);

	solve();

	return 0;
}