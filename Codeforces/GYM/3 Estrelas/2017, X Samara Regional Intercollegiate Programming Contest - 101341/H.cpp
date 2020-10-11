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
#define MAXN 1010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
int v[MAXN][MAXN], a[MAXN][MAXN], b[MAXN][MAXN], c[MAXN][MAXN], d[MAXN][MAXN];

void solve(){

	// Esq  - > Dir , Cima - > Baixo 
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(!i && !j) 	a[i][j] = v[i][j];
			else if(!i) 	a[i][j] = max(v[i][j], a[i][j-1]);
			else if(!j)		a[i][j] = max(v[i][j], a[i-1][j]);
			else 			a[i][j] = max(v[i][j], max( a[i][j-1], a[i-1][j]));
		}
	}

	// Esq  - > Dir , Baixo - > Cima 
	for(int i=N-1;i>=0;i--){
		for(int j=0;j<M;j++){
			if(i == N-1 && !j) 	c[i][j] = v[i][j];
			else if(i == N-1) 	c[i][j] = max(v[i][j], c[i][j-1]);
			else if(!j)			c[i][j] = max(v[i][j], c[i+1][j]);
			else 				c[i][j] = max(v[i][j], max( c[i][j-1], c[i+1][j]));
		}
	}


	// Dir  - > Esq , Cima - > Baixo 
	for(int i=0;i<N;i++){
		for(int j=M-1;j>=0;j--){
			if(!i && j == M-1) 	b[i][j] = v[i][j];
			else if(!i) 		b[i][j] = max(v[i][j], b[i][j+1]);
			else if(j == M-1)	b[i][j] = max(v[i][j], b[i-1][j]);
			else 				b[i][j] = max(v[i][j], max( b[i][j+1], b[i-1][j]));
		}
	}

	// Dir  - > Esq , Baixo - > Cima 
	for(int i=N-1;i>=0;i--){
		for(int j=M-1;j>=0;j--){
			if(i == N-1 && j == M-1) 	d[i][j] = v[i][j];
			else if(i == N-1) 			d[i][j] = max(v[i][j], d[i][j+1]);
			else if(j == M-1)			d[i][j] = max(v[i][j], d[i+1][j]);
			else 						d[i][j] = max(v[i][j], max( d[i][j+1], d[i+1][j]));
		}
	}

	int menor = INF;
	pii pos;

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(!i && !j){
				int aux = d[1][1];
				if(aux < menor){
					menor = aux;
					pos = pii(i,j);
				}
			}
			else if(!i && j == M-1){
				int aux = c[1][M-2];
				if(aux < menor){
					menor = aux;
					pos = pii(i,j);
				}
			}
			else if(i == N-1 && !j){
				int aux = b[N-2][1];
				if(aux < menor){
					menor = aux;
					pos = pii(i,j);
				}
			}
			else if(i == N-1 && j == M-1){
				int aux = a[N-2][M-2];
				if(aux < menor){
					menor = aux;
					pos = pii(i,j);
				}
			}
			else if(!i){
				int aux = max(d[1][j+1], c[1][j-1]);
				if(aux < menor){
					menor = aux;
					pos = pii(i,j);
				}
			}
			else if(i == N-1){
				int aux = max(a[N-2][j-1], b[N-2][j+1]);
				if(aux < menor){
					menor = aux;
					pos = pii(i,j);
				}
			}
			else if(!j){
				int aux = max(b[i-1][j+1], d[i+1][j+1]);
				if(aux < menor){
					menor = aux;
					pos = pii(i,j);
				}
			}
			else if(j == M-1){
				int aux = max(a[i-1][j-1], c[i+1][j-1]);
				if(aux < menor){
					menor = aux;
					pos = pii(i,j);
				}
			}
			else{
				int aux = max(a[i-1][j-1], max(b[i-1][j+1] , max(c[i+1][j-1] , d[i+1][j+1]) ) ) ;
				if(aux < menor){
					menor = aux;
					pos = pii(i,j);
				}
			}
		}
	}

	cout << pos.fi+1 << " " << pos.se+1 << endl;
}

int main(){

	optimize;
	
	cin >> N >> M;
	
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin >> v[i][j];
		}
	}

	solve();
    
	return 0;
}