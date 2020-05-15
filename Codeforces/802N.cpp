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
#define MAXL 2240

ll T,N,M,K;
int v[MAXL], v2[MAXL];

#define MAXN 100009
#define MAXM 900009
#define INFLL 0x3f3f3f3f3f3f3f3f

int ned;
int first[MAXN], to[MAXM], nxt[MAXM], prv[MAXN];
ll cap[MAXM], cost[MAXM], dist[MAXN], pot[MAXN]; 

void init() {
	memset(first, -1, sizeof first);
	ned = 0;
}

void add(int u, int v, ll f, ll c) {
	to[ned] = v, cap[ned] = f;
	cost[ned] = c, nxt[ned] = first[u];
	first[u] = ned++;
	to[ned] = u, cap[ned] = 0;
	cost[ned] = -c, nxt[ned] = first[v];
	first[v] = ned++;
}

bool dijkstra(int s, int t, int n) {
	memset(&prv, -1, sizeof prv);
	for(int i = 1; i <= n; i++) dist[i] = INFLL;
	set< pair<ll, int> > q;
	q.insert(make_pair(0LL, s));
	dist[s] = prv[s] = 0;
	while(!q.empty()) {
		int u = q.begin()->second;
		q.erase(q.begin());
		for(int e = first[u]; e != -1; e = nxt[e]) {
			if (cap[e] <= 0) continue;
			int v = to[e];
			ll new_dist = dist[u] + cost[e] + pot[u] - pot[v];
			if (new_dist < dist[v]) {
				q.erase(make_pair(dist[v], v));
				dist[v] = new_dist;
				prv[v] = e;
				q.insert(make_pair(new_dist, v));
			}
		}
	}
	return prv[t] != -1;
}

ll augment(int s, int t, ll &maxflow, int n) {
	ll flow = maxflow;
	for(int i = t; i != s; i = to[prv[i]^1])
		flow = min(flow, cap[prv[i]]);
	for(int i = t; i != s; i = to[prv[i]^1]) {
		cap[prv[i]] -= flow;
		cap[prv[i]^1] += flow;
	}
	maxflow -= flow;
	ll flowCost = flow*(dist[t]-pot[s]+pot[t]);
	for(int i = 1; i <= n; i++)
		if (prv[i] != -1) pot[i] += dist[i];
	return flowCost;
}

ll mincostmaxflow(int s, int t, ll &maxflow, int n) {
	ll flowCost = 0;
	memset(pot, 0, sizeof pot);
	while(maxflow > 0 && dijkstra(s, t, n)) {
		flowCost += augment(s, t, maxflow, n);
	}
	return flowCost;
}

void solve(){

    init();

    FOR(i,0,N)   add(0,i+1,1,v[i]);
    FOR(i,0,N)   add(i+1,N+1,1,v2[i]);
    FOR(i,0,N-1) add(i+1,i+2,INF,0);

    cout << mincostmaxflow(0,N+1,M,N+2) << endl;
}

int main(){

	cin >> N >> M;

    FOR(i,0,N) cin >> v[i];
    FOR(i,0,N) cin >> v2[i];

	solve();

	return 0;
}