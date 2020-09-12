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
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
ll A,B,C;
vector<vector<int>> adj;
vector<pair<vector<int>,vector<int>>> bipar;
int c[MAXN];

bool dfs(int v){
	
	stack<pii> pilha;
	pair<vector<int>,vector<int>> aux;

	pilha.push(pii(v,1));

	while(!pilha.empty()) {
		int u = pilha.top().fi;
		int cor = pilha.top().se;
		pilha.pop();

		c[u] = cor;

		if(cor == 1) aux.fi.pb(u);
		else if(cor == -1) aux.se.pb(u);

		for(auto i : adj[u]){
			if(!c[i]){
				pilha.push(pii(i, cor*(-1)));
				c[i] = cor*(-1);
			}else if(c[i] == cor) {
				return false;
			}
		}
	}

	bipar.pb(aux);
	return true;
}

void mudaC(vector<int> &V, vector<int> &P){

	FOR(i,0,sz(V)){
		B--;
		c[V[i]] = 2;
	}

	FOR(i,0,sz(P)){
		if(A){
			A--;
			c[P[i]] = 1;
		}else{
			C--;
			c[P[i]] = 3;
		}
	}
}

//I numeros de CC, j numeros de B
bool solve(int i, int j, vector<vector<int>> &dp){	
	if(i == bipar.size()) return !j;
	if(j < 0) return false;

	if(dp[i][j] == -1){
		dp[i][j] = 0;
		
		if(solve(i+1,j- bipar[i].fi.size(),dp)){
			dp[i][j] = 1;
			mudaC(bipar[i].fi ,bipar[i].se);
		}else if(solve(i+1,j- bipar[i].se.size(),dp)){
			dp[i][j] = 1;
			mudaC(bipar[i].se , bipar[i].fi);
		}
	}
	return dp[i][j];
}

void solve(){
	
	FOR(i,0,N) {
		if(!c[i] && !dfs(i)){
			cout << "NO" << endl;
			return;
		}
	}

	vector<vector<int>> dp(bipar.size()+1, vector<int> (B+1,-1));
	
	if( solve(0,B,dp) ){
		cout << "YES\n";
		FOR(i,0,N) cout << c[i];
		cout << endl;
	}else{
		cout << "NO" << endl;
	}

}

int main(){

	cin >> N >> M;
	cin >> A >> B >> C;

	adj.resize(N);

	FOR(i,0,M){
		int a,b;

		cin >> a >> b;

		a--, b--;
		adj[a].pb(b);
		adj[b].pb(a);
	} 

	solve();

	return 0;
}