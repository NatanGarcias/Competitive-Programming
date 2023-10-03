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
#define MAXN 110
#define TM 1000000

ll T,N,M;
vector<pii> tempo;		// tempo que a informação chegou no vertice
vector<pii> pos;		// pos que a informação chegou no vertice
vector<int> vertices; 	// tempo que chequei em cada vertice
vector<int> edge; 		// peso da aresta 
vector<set<int>> adj;	// list de adj
map<pii,int> mapa;		// mapa das arestas

void busca(int v){

	int cont = 1, ptr = 0, ptr2 = 0;

	set<int> abertos;

	abertos.insert(v);

	vertices[v] = 0;

	int tempG = 0;

	while(ptr < sz(pos) || ptr2 < sz(tempo)){
		if(ptr < sz(pos) && pos[ptr].fi == cont){
			int p = ptr;

			while(ptr < sz(pos) && pos[ptr].fi == cont) ptr++;	

			vector<pii> esc;
			
			FOR(k,p,ptr){
				for(auto i : abertos){
					auto it = adj[i].find( pos[k].se );

					if(it != adj[i].end()){
						tempG = max(tempG, vertices[i]);
						esc.pb(pii(i, pos[k].se));

						adj[i].erase(it);

						if(adj[i].empty()) abertos.erase(i);
						
						break;
					}
				}
			}
			tempG++;

			for(auto i : esc){
				int t = tempG - vertices[i.fi];

				if(!adj[i.se].empty()) abertos.insert(i.se);
				
				edge[ mapa[ pii(i.fi,i.se) ] ] = t;
				
				vertices[i.se] = tempG;
			}
			cont += ptr-p;
		}else if(ptr2 < sz(tempo)){
			int p = ptr2;

			int aux = tempo[ptr2].fi;

			while(ptr2 < sz(tempo) && tempo[ptr2].fi == aux) ptr2++;	

			vector<pii> esc;
			
			FOR(k,p,ptr2){
				for(auto i : abertos){
					auto it = adj[i].find( tempo[k].se );

					if(it != adj[i].end() && aux > vertices[i]){
						esc.pb(pii(i, tempo[k].se));

						adj[i].erase(it);

						if(adj[i].empty()) abertos.erase(i);
						
						break;
					}
				}
			}

			tempG = aux;

			for(auto i : esc){
				int t = tempG - vertices[i.fi];

				if(!adj[i.se].empty()) abertos.insert(i.se);
				
				edge[ mapa[ pii(i.fi,i.se) ] ] = t;
				
				vertices[i.se] = tempG;
			}
			cont += ptr2-p;
		}
	}
}

void solve(int caso){

	if(!tempo.empty()) 	sort(all(tempo));
	if(!pos.empty())	sort(all(pos));
	
	busca(0);

	FOR(i,0,M) if(edge[i] < 0) edge[i] = TM;

	cout << "Case #" << caso << ':';
	FOR(i,0,M) cout << " " << edge[i];
	cout << endl;
}

int main(){

	cin >> T;

    FOR(i,1,T+1){
		cin >> N >> M;

		tempo.clear();
		pos.clear();

		FOR(i,0,N-1){
			int a;
			cin >> a;

			if(a < 0){
				pii aux(-a,i+1);
				pos.pb(aux);
			}else{
				pii aux(a,i+1);
				tempo.pb(aux);
			}
		}

		adj.clear();
		adj.resize(N);

		vertices.clear();
		vertices.assign(N,-1);
		
		edge.clear();
		edge.assign(M,-1);

		mapa.clear();
		
		FOR(i,0,M){
			int a,b;
			cin >> a >> b; a--; b--;

			adj[a].insert(b);
			adj[b].insert(a);

			mapa[ pii(a,b) ] = i;
			mapa[ pii(b,a) ] = i;
		}
		solve(i);
    }
	return 0;
}