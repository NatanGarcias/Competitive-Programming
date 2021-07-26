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

#define all(x) x.begin(),x.end()
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 1010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;

struct UF{
	vector<int> parent;

	UF(int n){
		parent.assign(n+1,0);
		iota(all(parent), 0);
	}	

	int find(int u){
		if(u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}

	void unir(int u, int v){
		u = find(u);
		v = find(v);

		if(u != v){
			parent[u] = v;
		}
	}
};

vector<tuple<int,int,int>> e;
vector<pii> edge;

int valor[MAXN], c;

void solve(){

    sort(all(e));

    UF uf(MAXN);

    c = N;

    for(int i=0;i<e.size();i++){

        int value = get<0>(e[i]);
        int u = get<1>(e[i]);
        int v = get<2>(e[i]);

        u = uf.find(u);
        v = uf.find(v);

        if(u == v) continue;

        if( valor[ uf.find(u) ] != value && valor[ uf.find(v) ] != value){
            c++;

            valor[c] = value;

            edge.pb( pii(u , c) );
            edge.pb( pii(v , c) );

            uf.unir(u, c);
            uf.unir(v, c);

        }
        else if(valor[ uf.find(u) ] != value){
            edge.pb( pii(u , v) );
            uf.unir(u, v);
        }
        else if(valor[ uf.find(v) ] != value){
            swap(v,u);
            edge.pb( pii(u , v) );
            uf.unir(u, v);
        }
    }
    
    cout << c << endl;

    cout << valor[1];
    for(int i=2;i<=c;i++)    cout << " " << valor[i];
    cout << endl;

    cout << uf.find(1) << endl;
    for(int i=0;i<edge.size();i++)  cout << edge[i].fi << " " << edge[i].se << endl;
}

int main(){

	optimize;
	
	cin >> N;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int a;
            
            cin >> a;

            e.pb(make_tuple(a,i + 1,j + 1));

            if(i == j) valor[i + 1] = a;
        }
    }

	solve();

	return 0;
}