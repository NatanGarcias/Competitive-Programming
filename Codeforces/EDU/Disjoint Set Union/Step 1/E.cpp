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
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;

struct UF{
	vector<int> parent, rank;

	UF(int n){
		parent.assign(n+1,0);
		rank.assign(n+1,0);
		iota(all(parent), 0);
	}	

	int find(int u){
		if(u == parent[u]) return u;
		return parent[u] = find(parent[u]); 
	}

	bool sameSet(int u, int v){
		return find(u) == find(v);
	}

	void unir(int u, int v){
        u = find(u);
        v = find(v);

        if(u != v){
            if(rank[u] < rank[v]) swap(u,v);
            parent[v] = u;

            if(rank[u] == rank[v]) rank[u]++;
        }
    }
};

int adj[MAXN][2];
bool used[MAXN][2], vis[MAXN];
vector<vector<int>> adj2;

void bfs(int u, int w, vector<int> &t){

    vis[u] = true;

    for(auto i : adj2[u]){
        if(i != 1 && !vis[i] && t[i] == -1){
            t[i] = w;
            bfs(i, w, t);
        }
    }
}

void solve(){

	UF uf(N);
    vector<pii> q(M), cai;
    vector<bool> ans;
    vector<int> t(N+1,-1);

    adj2.resize(N+1);

	for(int i=1;i<=N;i++){
        int a, b;
        cin >> a >> b;

        adj[i][0] = a;
        adj[i][1] = b;
    }

    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;

        b--;

        q[i] = make_pair(a,b);
        used[a][b] = true;
    }

    for(int i=1;i<=N;i++){
        for(int j=0;j<2;j++){
            if(!used[i][j] && adj[i][j] != -1){
                uf.unir(i, adj[i][j]);

                adj2[i].pb(adj[i][j]);
                adj2[adj[i][j]].pb(i);
            }
        }
    }

    for(int i = M-1 ; i >= 0 ; i--){
        
        int a = q[i].fi;
        int b = q[i].se;
        int u = adj[a][b];

        if(uf.sameSet(a,u)) continue;
        
        else if(!uf.sameSet(1,a) && !uf.sameSet(1,u)){
            uf.unir(a,u);
        }

        else{
            int w = a; 

            if(uf.sameSet(1,a)) w = u;

            uf.unir(1,w);
            t[w] = i;
            cai.pb(pii(i, w));
        }
    }

    int ptr = 0;

    for(int i = M-1;i>=0;i--){
        int a = q[i].fi;
        int b = q[i].se;
        int u = adj[a][b];
        
        while(ptr < cai.size() && cai[ptr].fi == i){
            int v = cai[ptr].se;
            int w = cai[ptr].fi;

            bfs(v, w, t);

            ptr++;
        }
        
        adj2[a].pb(u);
        adj2[u].pb(a);
    }

    for(int i=1;i<=N;i++) cout << t[i] << endl;
}

int main(){

	optimize;
	
	cin >> N >> M;

	solve();

	return 0;
}