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

#define mod 1000000007
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
vector<vector<int>> adj;
int v[MAXN];
int r[MAXN];

struct Node{
	int u,t,l;
	Node(int _u, int _t, int _l) : u{_u}, t{_t}, l{_l} {} 
};

void bfs(){

	int ans = 0;
	queue<Node> fila;

	fila.push(Node(0,0,1));

	while(!fila.empty()){
		int u = fila.front().u;
		int t = fila.front().t;
		int l = fila.front().l;
		
		fila.pop();

		if(l) r[t]++;
		
		for(auto i : adj[u]){
			int aux = adj[u].size()%2;
			fila.push(Node(i,t+1,aux));
		}
	}

	FOR(i,0,N+1) if(r[i]%2) ans++;

	cout << ans << endl;
}

void solve(){

	adj.resize(N);

	FOR(i,0,N-1){
		int aux = v[i]-1;

		adj[aux].pb(i+1);
	}

	bfs();
}

int main(){

	cin >> N;

	FOR(i,0,N-1){
		cin >> v[i];
	}
	
	solve();
    
	return 0;
}