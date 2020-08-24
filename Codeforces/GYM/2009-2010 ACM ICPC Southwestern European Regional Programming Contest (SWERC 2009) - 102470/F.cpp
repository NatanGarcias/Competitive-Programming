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
#define MAXN 1000

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K,G,E;

bool grave[MAXN];
bool haunted[MAXN];

int dist[MAXN];
vector<pii> adj[MAXN];
bool hasNegativeWeightCycle;

int bellmanford(int s, int t){
	
    memset(&dist, INF, sizeof dist);
    
	dist[s] = 0;

	for (int i = 0, v, w; i < K; i++) {
		for (int u = 0; u < K; u++) {
			for (int j = 0; j < (int)adj[u].size(); j++) {
				v = adj[u][j].first;
				w = adj[u][j].second;
				if (i==K-1 && dist[u] != INF && dist[v] > dist[u] + w)
					hasNegativeWeightCycle = true;
				else if(dist[u] != INF) dist[v] = min(dist[v], dist[u] + w);
			}
		}
	}

    return dist[t];
}

int getP(int x, int y){
    return y*N +x;
}

bool posValid(int x, int y){
    if(x<0 || y<0 || x>=N || y>=M) return false;
    return true;
}

void solve(){

    FOR(i,0,N){
        FOR(j,0,M){
            
            int u = getP(i,j);

            if(grave[u] || haunted[u] || (i == N-1 && j == M-1)) continue;

            for(int k=-1;k<=1;k++){
                for(int l=-1;l<=1;l++){
                    if(abs(k+l) == 1 && posValid(i+k,j+l)){

                        int v = getP(i+k,j+l);

                        if(!grave[v]) adj[u].pb(pii(v,1));
                    }
                }    
            }
        }
    }
    int ans = bellmanford(0, getP(N-1,M-1));

    if(hasNegativeWeightCycle) cout << "Never\n";
    else if(ans == INF) cout << "Impossible\n";
    else cout << ans << "\n";
}

int main(){

	optimize;
	
    while(cin >> N >> M){
        if(!N && !M) break;

        K = N*M;

        cin >> G;        

        FOR(i,0,G){
            int a, b;

            cin >> a >> b;

            grave[getP(a,b)] = true;
        }

        cin >> E;

        
        FOR(i,0,E){
            int a, b, c, d, e;

            cin >> a >> b >> c >> d >> e;

            haunted[getP(a,b)] = true;

            adj[getP(a,b)].pb(pii(getP(c,d),e));
        }

        solve();

        FOR(i,0,N*M) if(!adj[i].empty()) adj[i].clear();
        
        hasNegativeWeightCycle = false;
        
        ms(grave,0);
        ms(haunted,0);
    }
		
	return 0;
}