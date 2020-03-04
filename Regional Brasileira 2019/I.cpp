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

#define INF 0x33ffffff
#define INFLL 0x3fffffffffffffff

#define mod %1000000007
#define MAXN 410

struct V{
	int A,B,K,id;
};

bool cmp(const V &a, const V &b){
	return a.K < b.K;
}

vector<V> cold;
vector<V> hot;
vector<pii> planeta;
vector<int> sol;
vector<int> cor;
vector<int> cor2;

ll N,R,Q;

void floyd(vector<vector<int>> adj){

	int cont = 0;
	int pos;
	
	for(int k=0; k<N;k++){
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				int aux = planeta[i].se;
				int aux2 = planeta[j].se;
				int aux3 = planeta[k].se;

				adj[ aux ][ aux2 ] = min(adj[ aux ][ aux2 ] , adj[aux][aux3] + adj[aux3][aux2]);
			}
		}

		if(cold[cont].K -1 < sz(cor)){
			pos = cor[cold[cont].K -1];
		}else{
			pos = N;
		}
		
		while(cont < sz(cold) && pos == k + 1){

			int a = cold[cont].A;
			int b = cold[cont].B;

			int index = cold[cont].id;

			if(adj[a][b] == INF){
				sol[index] = -1;
			}else{
				sol[index] = adj[a][b];
			}

			cont++;

			if(cont < sz(cold)){

				if(cold[cont].K -1 < sz(cor)){
					pos = cor[cold[cont].K - 1];		
				}else{
					pos = N;
				}
			}
		}

		if(cont >= sz(cold)) return;
	}
}

void floyd2(vector<vector<int>> adj){

	int cont = 0;
	int pos;

	for(int k=N-1; k>=0;k--){
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				int aux = planeta[i].se;
				int aux2 = planeta[j].se;
				int aux3 = planeta[k].se;

				adj[ aux ][ aux2 ] = min(adj[ aux ][ aux2 ] , adj[aux][aux3] + adj[aux3][aux2]);
			}
		}

		if( hot[cont].K -1 < sz(cor2)){
			pos = cor2[hot[cont].K -1];
		}else{
			pos = N;
		}

		while(cont < sz(hot) && pos == N - k){
			
			int a = hot[cont].A;
			int b = hot[cont].B;
			
			int index = hot[cont].id;

			if(adj[a][b] == INF){
				sol[index] = -1;
			}else{
				sol[index] = adj[a][b];
			}
			
			cont++;

			if(cont < sz(hot)){

				if(hot[cont].K -1 < sz(cor2)){
					pos = cor2[hot[cont].K - 1];		
				}else{
					pos = N;
				}
			}
			
		}

		if(cont >= sz(hot)) return;
	}

}

void temperatura(){

	FOR(i,N-1){
		if(planeta[i].fi != planeta[i+1].fi){
			cor.push_back(i+1);
		}
	}
	cor.pb(N);

	for(int i=N-1;i>0;i--){
		if(planeta[i].fi != planeta[i-1].fi){
			cor2.push_back( N-i );
		}
	}
	cor2.pb(N);
}

void solve(vector<vector<int>> &adj){

	sort(all(planeta));

	temperatura();

	sort(all(cold), cmp);
	sort(all(hot), cmp);

	if(sz(cold)){
		floyd(adj);
	}

	if(sz(hot)){
		floyd2(adj);
	}

	FOR(i,Q){
		cout << sol[i] << "\n";
	}
}

int main(){

	cin >> N >> R; 

	planeta.resize(N);

	FOR(i,N){
		cin >> planeta[i].fi;
		planeta[i].se = i;
	}

	vector<vector<int>> adj(N ,vector<int>(N,INF));

	int a,b,c,d;

	FOR(i,R){
		cin >> a >> b >> c;
		
		adj[a-1][b-1] = c;
		adj[b-1][a-1] = c;
	}

	cin >> Q;

	sol.resize(Q);

	FOR(i,Q){
		cin >> a >> b >> c >> d;

		V e;

		e.A = a-1;
		e.B = b-1;
		e.K = c;
		e.id = i;

		if(d)
			hot.push_back(e);
		else
			cold.push_back(e);
	}

	solve(adj);

	return 0;
}