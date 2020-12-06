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
#define MAXL 23
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;

int idade[MAXN], level[MAXN], dp[MAXN][MAXL], ans[MAXN];
bool vis[MAXN];
int l;

vector<vector<int>> adj;
vector<vector<pii>> festas;

//BIT TREE
int bit[MAXN + 20];

void update(int x, int valor){
	for(;x<=K;x+= x&-x) bit[x] += valor;
}

int query(int x){
	int sum = 0;
	
	for(;x>0;x-= x&-x){
		sum += bit[x];
	}

	return sum;
}

//BINARY LIFTING
void dfsl(int v, int p){
    dp[v][0] = p;
    
    for (int i = 1; i < MAXL; i++)
        dp[v][i] = dp[dp[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfsl(u, v);
    }
}

void precalc(int root = 1) {

	ms(dp, 0);

    dfsl(root, 0);
}

int LCA(int u, int lim){
    	    
    for(int i = MAXL-1; i >= 0; i--){
        if(dp[u][i] && idade[dp[u][i]] <= lim)
            u = dp[u][i];
    }
    
    return u;
}
 
//QUERYS
void add(int a, int b, int c){
    //Descubro o maior vértice que pode ir para a festa (menor level)
    int v = LCA(a,c);

    //Adiciono a query nele
    festas[v].push_back(pii(b,1));
    festas[v].push_back(pii(c+1,-1));
}

void dfs(int u){

    for(auto i : festas[u]) {
        update(i.fi, i.se);
    }

    ans[u] = query(idade[u]);

    vis[u] = true;

    for(auto i : adj[u]){
        if(!vis[i]){
            dfs(i);
        }
    }

    for(auto i : festas[u]) {
        update(i.fi, -i.se);
    }
}

void solve(){

    precalc();

    for(int i=0;i<M;i++){
        int a,b,c;

        cin >> a >> b >> c;

        //Adiciono aquela festa no maior pai possivel
        add(a,b,c);
    }	

    //Processo as festas
    dfs(1);

    for(int i=1;i<=N;i++) cout << ans[i] << " \n"[i == N];
}

int main(){

	optimize;
	
    cin >> N >> M;

    adj.resize(N+1);
    festas.resize(N+1);

    K = 200000;

    for(int i=1;i<=N;i++){
        int a,b;

        cin >> a >> b;

        idade[i] = a;

        if(i != 1){
            adj[i].pb(b);
            adj[b].pb(i);
        }
    }
    
    solve();

	return 0;
}