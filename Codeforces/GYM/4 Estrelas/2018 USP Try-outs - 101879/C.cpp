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
#define MAXN 300010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
vector<vector<int>> adj;
vector<pii> edge;
int inv[MAXN];
bool vis[MAXN];

void dfs(int u, int p){

    vis[u] = true;

    for(auto i : adj[u]){
        if(i != p && !vis[i]){
            dfs(i,u);
        }
    }

    if(u != p && inv[u]){
        edge.pb(pii(u + 1,p + 1));
        inv[u] = !inv[u];
        inv[p] = !inv[p];
    }
}

void solve(){

    for(int i=0;i<N;i++){
        if(!vis[i]){
            dfs(i,i);

            if(inv[i]){
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n" << edge.size() << endl;
    
    for(int i=0;i<edge.size();i++){
        cout << edge[i].fi << " " << edge[i].se << endl;
    }

}

int main(){

	optimize;
	
	cin >> N >> M >> K;

    adj.resize(N);

    for(int i=0;i<M;i++){
        int a,b;

        cin >> a >> b;

        a--, b--;

        inv[a] = !inv[a];
        inv[b] = !inv[b];
    }

    for(int i=0;i<K;i++){
        int a,b;

        cin >> a >> b;

        a--, b--;

        adj[a].pb(b);
        adj[b].pb(a);
    }

	solve();
    
	return 0;
}