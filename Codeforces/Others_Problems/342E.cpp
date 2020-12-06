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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;

#define MAXN 200010
#define MAXL 23

const int tbuf = 333;
int level[MAXN], dp[MAXN][MAXL], ans[MAXN], cor[MAXN], vis[MAXN], cnt;
vector<vector<int>> adj;
vector<int> buf;

void dfs(int v, int p){
    dp[v][0] = p;
    
    ans[v] = level[v] = level[p] + 1;
    
    for (int i = 1; i < MAXL; i++)
        dp[v][i] = dp[dp[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }
}

void precalc(int root = 1) {

	ms(dp, 0);

    level[0] = -1;
    cor[1] = 1;

    dfs(root, 0);
}

int LCA(int u, int v){
    
    if(level[u] < level[v]) swap(u,v);

    for(int i = MAXL-1; i >= 0; i--){
        if(dp[u][i] && level[ dp[u][i] ] >= level[v])
            u = dp[u][i];
    }

    if(u == v) return u;

    for(int i = MAXL-1; i >= 0; i--){
        if(dp[u][i] != dp[v][i]){
            u = dp[u][i];
            v = dp[v][i];
        }
    }
    
    return dp[u][0];
}

int dist(int u, int v){
	return level[u] + level[v] - 2 * level[LCA(u,v)];
}

void bfs(){

	queue<pii> fila;

	cnt++;

	for(int i=1;i<=N;i++){
		if(cor[i]){
			fila.push(pii(i,0));
			vis[i] = cnt;
			ans[i] = 0;
		}
	}

	while(!fila.empty()){
		int u = fila.front().fi;
		int t = fila.front().se; 

		fila.pop();

		for(auto i : adj[u]){
			if(vis[i] != cnt){
				vis[i] = cnt;
				fila.push(pii(i,t+1));

				ans[i] = t+1; 
			}
		}
	}

	buf.clear();
	buf.reserve(tbuf);
}

int main(){

	optimize;
	
   	cin >> N >> M;
    
    adj.resize(N+1);

    for(int i=1;i<N;i++){
    	int a,b;

    	cin >> a >> b;

    	adj[a].pb(b);
    	adj[b].pb(a);
    }

    precalc();

    buf.reserve(tbuf);

    for(int i=0;i<M;i++){
    	int a,b;

    	cin >> a >> b;

    	if(a == 1){
    		cor[b] = 1;
    		buf.pb(b);
    	}
    	else{
    		if(buf.size() >= tbuf){
    			bfs();
    		}

    		int aux = ans[b];

    		for(auto i : buf)
    			if(cor[i] == 1) aux = min(aux, dist(b,i));

    		cout << aux << endl;
    	}
    }

	return 0;
}