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

#define sz(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define FOR(x,a,n) for(int x= (int)(a);(x) < int(n);(x)++)
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;

pii edge[MAXN];
vector<vector<int>> adj, adj2;
set<pii> ans;
bool vis[MAXN], vis2[MAXN];

void dfs(int u){

    vis[u] = true;

    for(auto i : adj[u]){
        if(!vis[i]){
            ans.insert(pii(u,i));
            dfs(i);
        }
    }
}

void dfs2(int u){

    vis2[u] = true;

    for(auto i : adj2[u]){
        if(!vis2[i]){
            ans.insert(pii(i,u));
            dfs2(i);
        }
    }
}

void solve(){

    ms(vis, 0);
    ms(vis2, 0);

    dfs(0);
    dfs2(0);

    int cnt = 0;

    for(int i=0;i<M && cnt < M-2*N;i++){
        if( ans.find(edge[i]) == ans.end() ){
            cout << edge[i].fi+1 << " " << edge[i].se+1 << endl;
            cnt++;
        }
    }
}

int main(){

	//optimize;
	
	cin >> T;

    while(T--){
		cin >> N >> M;

        adj.clear();
        adj.resize(N);

        adj2.clear();
        adj2.resize(N);

        ans.clear();
        
        for(int i=0;i<M;i++){
            int a,b;

            cin >> a >> b;

            a--, b--;

            adj[a].push_back(b);
            adj2[b].push_back(a);
            edge[i] = pii(a,b);
        }

		solve();
    }

	return 0;
}