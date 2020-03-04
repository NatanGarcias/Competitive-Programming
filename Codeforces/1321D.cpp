#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld; 

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define endl "\n"
#define space " " 

#define pii pair<int,int>
#define fi first 
#define se second 
#define pb push_back
#define sz(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define ms(x) memset(x,0,sizeof(x))
#define ms2(x) memset(x,-1,sizeof(x))

#define PI 3.141592653589793238462643383279502884
#define FOR(x,n) for(int x=0;(x) < int(n);(x)++)
#define FOR1(x,n) for(int x=1;(x) <= int(n);(x)++)

#define INF 0x3fffffff
#define INFLL 0x3fffffffffffffff

#define mod %1000000007

#define MAXN 200010
#define MAXM 2029
#define MAXL 20

int N,M,C;
vector<vector<int>> adj;

vector<vector<int>> adj2;
int c[MAXN];
int dist[MAXN];
multiset<int> tempo;

void bfs(int x){

	vector<bool> vis(N,0);

	queue<pii> fila;

	fila.push({x,0});

	vis[x] = true;

	while(!fila.empty()){
		int u = fila.front().fi;
		int t = fila.front().se;
		fila.pop();
		
		dist[u] = t;

		tempo.insert(t);
		
		for(auto i : adj[u]){

			if(!vis[i]){
				vis[i] = true;
				fila.push({i,t+1});
			}
		}
	}
}

void solve(){

	bfs(c[C-1]);

	int ant;
	int menor = 0, maior = 0;

	FOR(i,C){
		if(!i){
			ant = c[i];
		}else{
			if(dist[ c[i] ] >= dist[ant]){
				menor++;
				maior++;
			}else{
				int cont = 0;

				for(auto j: adj2[ ant ]){
					if( dist[j] == dist[ c[i] ] ){
						cont++;
					}
				}
				
				if(cont > 1) {
					maior++;
				}
			}
			ant = c[i];
		}
	}

	cout << menor << " " << maior << endl;
}

int main(){

	cin >> N >> M;

	adj.resize(N);
	adj2.resize(N);

	int a,b;

	FOR(i,M){
		cin >> a >> b;

		adj[b-1].pb(a-1);
		adj2[a-1].pb(b-1);
	}

	cin >> C;

	FOR(i,C){
		cin >> c[i];
		c[i]--;
	}	

	solve();

	return 0;
}