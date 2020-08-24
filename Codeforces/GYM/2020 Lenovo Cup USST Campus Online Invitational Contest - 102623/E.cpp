#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;

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
#define INFLL 0x3f3f3f3f3f3f3f3fLL

#define mod 998244353LL

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
string s;

const int n = 8;
const int m = 40320;
int p[n][n];
ll c[n][n];
ll custo[m], dist[m];
bool vis[m];
vector<int> perm[m];

int getint(char k) { return int(k - '1'); } 

struct Hash{
	size_t operator()(const vector<int> &a) const{
		size_t aux = 0, valor = 1;

		for(auto i : a){
			aux += i * valor;
			valor *= 8;
		}

		return aux;
	}
};

unordered_map<vector<int>, int, Hash> mapa;
vector<vector<pii>> adj;

void arestas(){

	int pos = 0;
	vector<int> nums = {0,1,2,3,4,5,6,7}; 

	do{
		perm[pos++] = nums;	 
	}while(next_permutation(all(nums)));

	// Cada permutação é um vértice 
	FOR(i,0,m) mapa[ perm[i] ] = i;

	FOR(k,0,m){
	// Cada troca (swap) na permutção é uma aresta		
		vector<int> aux = perm[k];

		int aux2 = mapa[ perm[k] ] ;
		
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){		

				swap(aux[i], aux[j]);
				
				adj[ aux2 ].pb( pii( mapa[aux] , c[ aux[i] ][ aux[j] ]) );

				swap(aux[i], aux[j]);
			}
		}
	}

}

void inversao(){

	ll inv[n][n];
	ll freq[n];

	ms(inv, 0);
	ms(freq, 0);

	//inv[a][b] = quantidade de números b que vem que vem depois de a na string 

	FOR(i,0,N){
		int k = getint(s[i]);

		FOR(j,0,n) inv[j][k] += freq[j];

		freq[k]++;
	}

	// custo vai ser igual a quantidade de inversoes do numero j com o k vezes o preço da inversão
	// custo[i] é o custo para ir da string dada no mapeamento i para um string que para estar ordenada
	// só precisaria trocar os numeros x com y
	FOR(i,0,m)
		FOR(j,0,n)
			FOR(k,0,n)
				custo[i] += p[ perm[i][j] ][ perm[i][k] ] * inv[j][k];
	
}

void dijkstra(){
	
	FOR(i,0,m) dist[i] = INFLL;

	dist[0] = 0;

	set<pii>pq;

	pq.insert(pii(0,0));

	while(!pq.empty()){
		ll u = pq.begin()->se;
		pq.erase(pq.begin());

		for(auto i : adj[u]){
			ll w = i.fi;
			ll p = i.se;
			
			ll aux = dist[u] + p;
			if(dist[w] > aux){

				pq.erase(pii(dist[w], w));
				
				dist[w] = aux;
				
				pq.insert(pii(aux, w));
			}				
		}
	}
}

void solve(){

	adj.resize(m);

	arestas();
	inversao();
	dijkstra();

	ll ans = INFLL;

	FOR(i,0,m) if(dist[i] != INFLL) ans = min(ans, custo[i] + dist[i]);

	cout << ans << endl;
}

int main(){

	optimize;
	
	cin >> N >> s;

	FOR(i,0,n) FOR(j,0,n) cin >> p[i][j];

	FOR(i,0,n) FOR(j,0,n) cin >> c[i][j];

	solve();
    
	return 0;
}	