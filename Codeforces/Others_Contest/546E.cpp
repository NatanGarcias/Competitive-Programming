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
#define MAXN 103000
#define MAXM 900000

int ned, first[MAXN], work[MAXN], dist[MAXN], q[MAXN];
int cap[MAXM], to[MAXM], nxt[MAXM];

void init() {
   memset(first, -1, sizeof first);
   ned = 0;
}

void add(int u, int v, int f) {
	to[ned] = v, cap[ned] = f;
	nxt[ned] = first[u];
	first[u] = ned++;
	
	to[ned] = u, cap[ned] = 0;
	nxt[ned] = first[v];
	first[v] = ned++;
}

int dfs(int u, int f, int t) {
	if (u == t) return f;
	for(int &e = work[u]; e != -1; e = nxt[e]) {
		int v = to[e];
		if (dist[v] == dist[u] + 1 && cap[e] > 0) {
			int df = dfs(v, min(f, cap[e]), t);
			if (df > 0) {
				cap[e] -= df;
				cap[e^1] += df;
				return df;
			}
		}
	}
	return 0;
}

bool bfs(int s, int t) {
	memset(&dist, -1, sizeof dist);
	dist[s] = 0;
	int st = 0, en = 0;
	q[en++] = s;
	while (en > st) {
		int u = q[st++];
		for(int e = first[u]; e!=-1; e = nxt[e]) {
			int v = to[e];
			if (dist[v] < 0 && cap[e] > 0) {
				dist[v] = dist[u] + 1;
				q[en++] = v;
			}
		}
	}
	return dist[t] >= 0;
}

int dinic(int s, int t) {
	int result = 0, f;
	while (bfs(s, t)) {
		memcpy(work, first, sizeof work);
		while (f = dfs(s, INF, t)) result += f;
	}
	return result;
}

#define MAXL 115

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;

ll l[MAXL], d[MAXL], sum, sum2, m[MAXL][MAXL];
vector<vector<int>> adj;

void solve(){

    init();

    for(int i=0;i<N;i++){
        add(0,i+1,l[i]);
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(adj[i][j]) 
                add(i+1,j+N+1,INF);
            else
                add(i+1,j+N+1,0);
        }
    }

    for(int i=0;i<N;i++){
        add(i+N+1,2*N+1,d[i]);
    }

    if(sum == dinic(0, 2*N+1)){
        cout << "YES\n";

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                m[i][j] = cap[2*(N*(i+1)+j) +1];
            }
        }

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout << m[i][j] << " \n"[j==N-1];
            }
        }   
    }

    else{
        cout << "NO\n";
    }
}

int main(){

	optimize;
	
    cin >> N >> M;
    
    for(int i=0;i<N;i++) {
        cin >> l[i];
        sum += l[i];
    }

    for(int i=0;i<N;i++) {
        cin >> d[i];
        sum2 += d[i];
    }
    
    if(sum != sum2){
        cout << "NO\n";
        return 0;
    }

    adj.resize(N);

    for(int i=0;i<N;i++){
        adj[i].resize(N);
    }

    for(int i=0;i<N;i++) adj[i][i] = 1;

    for(int i=0;i<M;i++){
        int a, b;
        cin >> a >> b;

        a--, b--;

        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    
    solve();

	return 0;
}