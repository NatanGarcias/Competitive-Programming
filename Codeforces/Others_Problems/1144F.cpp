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
vector<bool> ans;
map<pii,int> mapa;
set<pii> edge;
int vis[MAXN];

bool bfs(int x){

	queue<pii> fila;

	fila.push(pii(x,0));
	vis[x] = 0;

	while(!fila.empty()){
		int u = fila.front().fi;
		int c = fila.front().se;
		fila.pop();

		for(auto i : adj[u]){
			if(vis[i] != -1){

				if(c){
					if(edge.find(pii(u,i)) != edge.end()) ans[ mapa[pii(u,i)] ] = 0;
					else ans[ mapa[pii(u,i)] ] = 1;	
				}else{
					if(edge.find(pii(u,i)) != edge.end()) ans[ mapa[pii(u,i)] ] = 1;
					else ans[ mapa[pii(u,i)] ] = 0;
				}

				if( (c && vis[i]) || (!c && !vis[i])) return false;
			}else{
				fila.push(pii(i, c^1));
				vis[i] = c^1;

				if(c){
					if(edge.find(pii(u,i)) != edge.end()) ans[ mapa[pii(u,i)] ] = 0;
					else ans[ mapa[pii(u,i)] ] = 1;	
				}else{
					if(edge.find(pii(u,i)) != edge.end()) ans[ mapa[pii(u,i)] ] = 1;
					else ans[ mapa[pii(u,i)] ] = 0;
				}
			}
		}
	}

	return true;
}

void solve(){

	ms(vis,-1);

	int temp = bfs(0);

	if(temp){
		cout << "YES\n";

		for(auto i : ans)	cout << i;
		cout << endl;
		
	}else cout << "NO\n";
}

int main(){

    cin >> N >> M;

	adj.resize(N);
	ans.assign(M,false);

	FOR(i,0,M){
		int a,b;

		cin >> a >> b;

		a--; b--;

		adj[a].pb(b);
		adj[b].pb(a);

		edge.insert(pii(a,b));

		mapa[pii(a,b)] = i;
		mapa[pii(b,a)] = i;
	}

    solve();

	return 0;
}