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

		if(parent[u] != aux) dist[u] =  (dist[u] + dist[ parent[u] ]) % 2;

		return parent[u] = aux;
	}

    bool bt(int u, int v){
        find(u);
        find(v);

        return dist[u] == dist[v];
    }
	bool sameSet(int u, int v){
		return find(u) == find(v);
	}

	void unir(int u, int v){
		int u2 = find(u);
        int v2 = find(v);

        parent[v2] = u2;
        dist[v2] = (dist[v] + dist[u] + 1) % 2;
	}
};

void solve(){

	UF uf(N);
    
	for(int i=0;i<M;i++){
		int a,b;

		cin >> a >> b;

        if(!uf.sameSet(a,b)){
            uf.unir(a,b);
        }
        else{
            if(uf.bt(a,b)){
                cout << i+1 << endl;
                return;
            }
        }
	}

    cout << -1 << endl;
}

int main(){

	optimize;
	
	cin >> N >> M;

	solve();

	return 0;
}