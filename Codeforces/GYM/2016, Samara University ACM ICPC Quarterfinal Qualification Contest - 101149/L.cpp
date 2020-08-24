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
ll T,N,M,K,A,B;

int dist[MAXN], dist2[MAXN], dist3[MAXN];
bool vis[MAXN];
vector<vector<int>> adj, adj2;

void bfs(int d[], int x, vector<vector<int>> &adja){

    queue<pii> fila;

    fila.push(pii(x,0));

    ms(vis,0);
    
    d[x] = 0;
    vis[x] = true;
    
    while(!fila.empty()){
        int u = fila.front().fi;
        int t = fila.front().se;
        
        fila.pop();

        for(auto i: adja[u]){
            if(!vis[i]){
                vis[i] = true;
                d[i] = t+1;
                fila.push(pii(i,t+1));
            }
        }
    } 
}

void solve(){

    FOR(i,0,N+1){
        dist[i] = INF;
        dist2[i] = INF;
        dist3[i] = INF;
    }

    bfs(dist, A, adj);
    bfs(dist2, B, adj);
    bfs(dist3, 0, adj2);

    ll ans = 0, menor = INF;

    FOR(i,0,N+1){
        if(dist[i] != INF && dist2[i]!= INF){
            ll aux = dist[i] + dist2[i]  + dist3[i];
            menor = min(menor, aux);
        }
    }

    cout << menor << endl;
}

int main(){

	optimize;
	
	cin >> N >> M >> A >> B; 

    adj.resize(N+1);
    adj2.resize(N+1);

    FOR(i,0,M){
        int a,b;

        cin >> a >> b;
		
        adj[b].pb(a);
        adj2[a].pb(b);
    }

    solve();
        
	return 0;
}