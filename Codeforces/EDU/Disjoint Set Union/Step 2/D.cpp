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
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;

struct UF{
	vector<int> parent, dist;

	UF(int n){
		parent.assign(n+1,0);
        dist.assign(n+1,0);
		iota(all(parent), 0);
	}	

	int find(int u){
		if(u == parent[u]) return u;

        int aux = find(parent[u]);

        if(parent[u] != parent[aux]) dist[u] += dist[ parent[u] ];

		return parent[u] = aux;
	}

	bool sameSet(int u, int v){
		return find(u) == find(v);
	}

	void unir(int u, int v){
		if(u != v) {
            parent[u] = v;
            dist[u] += dist[v] + 1;
        }
	}
};

void solve(){

	UF uf(N);
    
	for(int i=0;i<M;i++){
		int a,b,c;

		cin >> a;

        if(a == 1){
            cin >> b >> c;

            uf.unir(b,c);
        }
        else{
            cin >> b;

            int ans = uf.find(b);
            ans = uf.dist[b];

            cout << ans << endl;
        }
	}
}

int main(){

	optimize;
	
	cin >> N >> M;

	solve();

	return 0;
}