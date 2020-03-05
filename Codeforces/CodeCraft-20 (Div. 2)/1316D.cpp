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

#define MAXN 1010

int N;

pii v[MAXN][MAXN];
int valor[MAXN][MAXN];

vector<pii> X;
vector<pii> blocked;
vector<bool> visX;
vector<pii> Loop;

bool validPosition(int x, int y){

	if(x >= 0 && y >= 0 && x < N && y < N){
		return true;
	}
	return false;
}

bool validLoop(pii &A){

	for(int i=-1;i<=1;i+=2){
		if(validPosition(A.fi+i,A.se)){
			if(valor[A.fi+i][A.se] == -1){
				return true;
			}
		}
	}

	for(int i=-1;i<=1;i+=2){
		if(validPosition(A.fi,A.se+i)){
			if(valor[A.fi][A.se+i] == -1){
				return true;
			}
		}
	}

	return false;
}

int bfs(int a, int b){

	int ans = 1;

	queue<pii> fila;

	fila.push({a,b});
	
	while(!fila.empty()){
		pii u = fila.front();
		fila.pop();

		if(validPosition(u.fi+1,u.se)){

			if(valor[u.fi+1][u.se] == 0 && v[u.fi+1][u.se].fi == a && v[u.fi+1][u.se].se == b){
				ans += 1;
				valor[u.fi+1][u.se] = 85;
				fila.push({u.fi+1,u.se});
			}
		}

		if(validPosition(u.fi-1,u.se)){

			if(valor[u.fi-1][u.se] == 0 && v[u.fi-1][u.se].fi == a && v[u.fi-1][u.se].se == b){
				ans += 1;
				valor[u.fi-1][u.se] = 68;
				fila.push({u.fi-1,u.se});
			}	
		}

		if(validPosition(u.fi,u.se-1)){

			if(valor[u.fi][u.se-1] == 0 && v[u.fi][u.se-1].fi == a && v[u.fi][u.se-1].se == b){
				ans += 1;
				valor[u.fi][u.se-1] = 82;
				fila.push({u.fi,u.se-1});
			}
		}

		if(validPosition(u.fi,u.se+1)){

			if(valor[u.fi][u.se+1] == 0 && v[u.fi][u.se+1].fi == a && v[u.fi][u.se+1].se == b){
				ans += 1;
				valor[u.fi][u.se+1] = 76;
				fila.push({u.fi,u.se+1});
			}
		}
	}

	return ans;
}

bool validX(){

	int cont = 0;

	for(int i=0;i<sz(blocked);i++){
		cont+= bfs(blocked[i].fi,blocked[i].se);
	}

	if(cont == sz(X)) return true;
	return false;
}


void bfsLoop(int a, int b){

	queue<pair<pii,char>> fila;

	fila.push({make_pair(a,b),'X'});

	while(!fila.empty()){
		pii u = fila.front().fi;
		char k = fila.front().se;

		fila.pop();

		bool mudei = false;

		if(validPosition(u.fi+1,u.se)){
			if(valor[u.fi+1][u.se] == -1){
				mudei = true;
				valor[u.fi][u.se] = 68;
				fila.push({make_pair(u.fi+1,u.se),'D'});
			}
		}
		if(!mudei){
			if(validPosition(u.fi-1,u.se)){
				if(valor[u.fi-1][u.se] == -1){
					mudei = true;
					valor[u.fi][u.se] = 85;
					fila.push({make_pair(u.fi-1,u.se),'U'});
				}
			}
		}

		if(!mudei){
			if(validPosition(u.fi,u.se-1)){
				if(valor[u.fi][u.se-1] == -1){
					mudei = true;
					valor[u.fi][u.se] = 76;
					fila.push({make_pair(u.fi,u.se-1),'L'});
				}
			}
		}

		if(!mudei){
			if(validPosition(u.fi,u.se+1)){
				if(valor[u.fi][u.se+1] == -1){
					mudei = true;
					valor[u.fi][u.se] = 82;
					fila.push({make_pair(u.fi,u.se+1),'R'});
				}
			}
		}

		if(!mudei){
			if(k == 76){
				valor[u.fi][u.se] = 82;
			}else if(k == 82){
				valor[u.fi][u.se] = 76;
			}else if(k == 68){
				valor[u.fi][u.se] = 85;
			}else if(k == 85){
				valor[u.fi][u.se] = 68;
			}else if(k == 88){
				if(validPosition(u.fi-1,u.se) && v[u.fi-1][u.se].fi < 0){
					valor[u.fi][u.se] = 85;
				}else if(validPosition(u.fi+1,u.se) && v[u.fi+1][u.se].fi < 0){
					valor[u.fi][u.se] = 68;
				}else if(validPosition(u.fi,u.se-1) && v[u.fi][u.se-1].fi < 0){
					valor[u.fi][u.se] = 76;
				}else if(validPosition(u.fi,u.se+1) && v[u.fi][u.se+1].fi < 0){
					valor[u.fi][u.se] = 82;
				}
			}
		}
	}

}

void bfsLoop(){

	FOR(i,sz(Loop)){
		if(valor[Loop[i].fi][Loop[i].se] == -1){
			bfsLoop(Loop[i].fi,Loop[i].se);
		}
	}
}

void imprimi(){

	FOR(i,N){
		FOR(j,N-1){
			cout << (char)valor[i][j]; 
		}
		cout << (char)valor[i][N-1] << endl; 
	}
}

void solve(){
		
	FOR(i,sz(Loop)){
		if(!validLoop(Loop[i])){
			cout << "INVALID\n";
			return;
		}
	}

	if(!validX()){
		cout << "INVALID\n";
		return;
	}

	cout << "VALID\n";
	bfsLoop();

	imprimi();
}

int main(){

	optimize;
	
	cin >> N;

	int a,b;

	FOR(i,N){
		FOR(j,N){
			cin >> a >> b;

			a--;b--;

			pii c(a,b);

			if(a >= 0){
				X.push_back(c);
				
				if(a== i && b==j){
					valor[i][j] = 88;
					blocked.pb({i,j});
				}else{
					valor[i][j] = 0;
				}
			}
			else{
				Loop.push_back({i,j});
				valor[i][j] = -1;
			}

			v[i][j] = c;
		}
	}

	solve();

	return 0;
}