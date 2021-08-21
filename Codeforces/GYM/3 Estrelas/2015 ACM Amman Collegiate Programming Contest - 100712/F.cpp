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

vector<tuple<int,int,int>> edge;

struct UF{
    vector<int> parent;

    UF(int n){
        parent.resize(n);
        iota(all(parent), 0);
    }

    int find(int u){
        if(u == parent[u]) return u;
        return find(parent[u]);
    }

    bool sameSet(int u, int v){
        return find(u) == find(v);
    }

    void unir(int u, int v){
        u = find(u);
        v = find(v);

        if(u == v) return;
        parent[u] = v;
    }
};

void solve(){

    sort(all(edge));

    int ans = 0;

    UF uf(N);

    for(int i = 0; i < M; i++){
        int w = get<0>(edge[i]);
        int u = get<1>(edge[i]);
        int v = get<2>(edge[i]);

        if(!uf.sameSet(u, v)){
            uf.unir(u, v);
            ans = max(ans, w);
        }
    }

    cout << ans << endl;
}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
		cin >> N >> M;
    
        for(int i = 0, u, v, w ; i < M ; i++) {
            cin >> u >> v >> w;

            edge.emplace_back(w, u - 1, v - 1);
        }

		solve();

        edge.clear();
    }

	return 0;
}