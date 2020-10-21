#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld; 

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

#define pii pair<int,int>
#define fi first 
#define se second 
#define pb push_back

#define sz(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define FOR(x,a,n) for(int x= (int)(a);(x) < int(n);(x)++)
#define ms(x,a) memset(x,a,sizeof(x))

#define PI 3.141592653589793238462643383279502884
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007
#define MAXN 200010

ll T,N,M,K,A,B,C;
vector<vector<int>> adj;
ll peso[MAXN];
bool vis[MAXN];
int distA[MAXN];
int distB[MAXN];
int distC[MAXN];

void bfs(int a, int dist[], bool vis[]){

    vis[a] = true;
    dist[a] = 0;

    queue<pii> fila;

    fila.push(pii(a,0));

    while(!fila.empty()){
        int u = fila.front().fi;
        int t = fila.front().se;
        fila.pop();

        for(auto i : adj[u]){
            if(!vis[i]){
                vis[i] = true;
                dist[i] = t+1;
                fila.push(pii(i,t+1));
            }
        }
    } 
}

void solve(){

    sort(peso,peso+M);

    ms(distA,0);
    ms(distB,0);
    ms(distC,0);

    ms(vis,0);
    bfs(A,distA,vis);

    ms(vis,0);
    bfs(B,distB,vis);
    
    ms(vis,0);
    bfs(C,distC,vis);

    int menor = INF;
    int menorB = INF;

    vector<ll> custo(4*N+1, INFLL);
    custo[0] = 0;

    FOR(i,0,N-1){
        custo[i+1] = custo[i] + peso[i];
    }

    ll ans = INFLL;

    FOR(i,0,N){
        int pos = distA[i] + distB[i] + distC[i];
        int pos2 = distB[i];

        ans = min(ans , custo[pos]+custo[pos2]);
    }

    cout << ans << endl;
}

int main(){

    optimize; 

	cin >> T;

    while(T--){
		cin >> N >> M >> A >> B >> C;

        A--; B--; C--;

        int a,b;
        
        adj.resize(N);
        FOR(i,0,N) adj[i].clear();

        FOR(i,0,M) cin >> peso[i];

        FOR(i,0,M){
            cin >> a >> b;

            a--; b--;

            adj[a].pb(b);
            adj[b].pb(a);
        }
		solve();
    }
	return 0;
}