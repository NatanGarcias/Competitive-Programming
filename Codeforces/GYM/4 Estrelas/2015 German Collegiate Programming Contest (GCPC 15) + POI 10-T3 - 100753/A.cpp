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
#define MAXN 20010
#define MAXM 20

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

int T,N,M,K,P,G;
vector<pii> lug;
vector<vector<pii>> adj;
int compAdj[MAXM][MAXM];
int dp[(1 << 17)][MAXM][2];
int btMax;
bool vis[MAXN];

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

int solve(int bt, int i, bool ok){

    if(dp[bt][i][ok]) return dp[bt][i][ok];
    
    int ans = INF;

    if(bt == btMax) {
        ans = min(ans, compAdj[i][0] + lug[0].se);
        
        if(!ok) ans = min(ans, T + lug[0].se);
        
        return dp[bt][i][ok] = ans;
    }

    for(int j=0;j<P;j++){
        //Ainda não visitei aquele lugar
        if(! (bt & (1 << j) ) ){
            ans = min(ans, solve(bt | (1 << j), j, ok) + compAdj[i][j] + lug[j].se);
            
            if(!ok) ans = min(ans, solve(bt | (1 << j), j,  1) + T + lug[j].se);
        }
    }

    return dp[bt][i][ok] = ans;
}

void solve(){

    for(int i=0;i<P;i++){
        auto dist = dijkstra(lug[i].fi);

        for(int j=0;j<P;j++){
            compAdj[i][j] = dist[lug[j].fi];
        }
    }

    if(solve(1,0,1) <= G) cout << "possible without taxi\n";
    else if(solve(1,0,0) <= G) cout << "possible with taxi\n";
    else cout << "impossible\n";
}

int main(){

	optimize;
	
	cin >> N >> P >> M >> G >> T;

    for(int i=0,u,t;i<P;i++){
        cin >> u >> t;

        lug.pb(pii(u,t));
    }

    sort(all(lug));

    if(!P || lug[0].fi != 0) {
        lug.pb(pii{0,0});
        swap(lug[0], lug[lug.size()-1]);
        P++;
    }

    btMax = (1 << P) - 1;

    adj.resize(N);

    for(int i=0,u,v,w;i<M;i++){
        cin >> u >> v >> w;

        adj[u].pb(pii(v,w));
        adj[v].pb(pii(u,w));
    }

	solve();

	return 0;
}