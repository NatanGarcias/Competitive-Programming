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
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;

int l[MAXN];
int vis[MAXN];
vector<vector<int>> adj;
vector<int> tour, tour2;

void bfs(int u){

    queue<pii> fila;
    vis[u] = 1;
    fila.push(pii(u,1));

    while(!fila.empty()) {
        int v = fila.front().fi;
        int t = fila.front().se;
        fila.pop();

        for(auto i : adj[v]){
            if(!vis[i]){
                vis[i] = t+1;
                fila.push(pii(i,t+1));
            }
        }
    }
}   

void dfs(int u, int d){
    tour.pb(u);
    vis[u] = true;

    if(u == d) tour2 = tour;

    for(auto i : adj[u]){
        if(!vis[i]){
            dfs(i, d);
        }
    }
    vis[u] = false;
    tour.pop_back();
}

int main(){

	optimize;
	
	cin >> N >> M;
    
    adj.resize(N);

    for(int i=0;i<N-1;i++){
        int a,b;

        cin >> a >> b;

        a--,b--;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    for(int i=0;i<M;i++) {
        int a;    
        cin >> a;
        a--;
        
        l[i] = a;
    }

    bfs(l[0]);
    
    int p = -1, maior = -1;

    for(int i=0;i<M;i++){
        if(vis[l[i]] > maior){
            maior = vis[l[i]];
            p = l[i];
        }
    }
    
    ms(vis, 0);
    dfs(l[0], p);
    
    int f = tour2.size();

    vector<int> c;

    if(f & 1) c.pb(tour2[tour2.size()/2]);

    for(auto i : c){
        ms(vis, 0);
        bfs(i);

        bool ans = true;
        int dist = vis[l[0]];

        for(int j=1;j<M;j++) if(vis[l[j]] != dist) ans = false;

        if(ans){
            cout << "YES\n";
            cout << i+1 << endl;
            return 0;
        }
    }

    cout << "NO\n";

	return 0;
}