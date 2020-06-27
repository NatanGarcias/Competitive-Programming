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
vector<vector<int>> adj;
int vis[MAXN];
bool ind[MAXN];
vector<int> tour;
vector<int> ans2;

void dfs(int u){
    vis[u] = tour.size();
    tour.push_back(u);   
    
    for(auto i : adj[u]){
        if(vis[i] == -1){
            dfs(i);
        }else{
            if(vis[u] - vis[i] == K-1 && ans2.empty()){
                for(int j = vis[i] ; j<= vis[u] ;j++) ans2.pb(tour[j]);
            }
        }
    }

    if(!ind[u]) for(auto i: adj[u]) ind[i] = true;
    tour.pop_back();
}

void solve(){

    ms(vis,-1);
    dfs(0);

    int qttd = 0;
    FOR(i,0,N) if(!ind[i]) qttd++;

    if(qttd >= (K+1)/2){
        vector<int> ans;

        for(int i=0;i<N;i++){
            if(!ind[i]) ans.pb(i);
        }

        cout << "1\n";
        FOR(i,0,(K+1)/2) cout << ans[i]+1 << " \n"[i == (K+1)/2 -1];
    }else{
        cout << "2\n";
        cout << sz(ans2) << endl;
        FOR(i,0,sz(ans2)) cout << ans2[i]+1 << " \n"[i == sz(ans2)-1];
    }

}

int main(){

    cin >> N >> M >> K;

    adj.resize(N);
    FOR(i,0,M){
        int a,b;

        cin >> a >> b; a--; b--;

        adj[a].pb(b);
        adj[b].pb(a);  
    }

    solve();

	return 0;
}