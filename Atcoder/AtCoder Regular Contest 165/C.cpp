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
	vector<ll> parent, rank;
    vector<pii> val;

	UF(int n){
		parent.assign(n+1, 0);
		rank.assign(n+1, 1);
        val.assign(n+1, make_pair(-1, -1));
		iota(all(parent), 0);
	}	

	int find(int u){
		if(u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}

	bool sameSet(int u, int v){
		return find(u) == find(v);
	}

    void upd(int u, int w) {
        if(val[u].first == -1) val[u].first = w;
        else if(val[u].second == -1) val[u].second = w;
    }

    bool unir(int u, int v) {
        u = find(u);
        v = find(v);

        if(u != v){
            if(rank[u] < rank[v]) swap(u,v);
            rank[u]++;
            parent[v] = u;
        }

        return false;
    }

	bool add(int u, int v, int w){
        upd(u, w);
        upd(v, w);

        unir(2 * u, 2 * v + 1);
        unir(2 * v, 2 * u + 1);

        if(sameSet(2 * u, 2 * u + 1)) return true;
        if(sameSet(2 * v, 2 * v + 1)) return true;
        
        return false;
    }

    ll getAns() {
        ll ans = INFLL;
        for(auto [u, v] : val) if(u != -1 && v != -1) ans = min(ans, u + v);

        return ans;
    }
};

vector<tuple<ll, ll, ll>> edge;

void solve() {

	cin >> N >> M;

    for(int i = 0; i < M; i++) {
        ll u, v, w;

        cin >> u >> v >> w;
        
        u--, v--;

        edge.emplace_back(w, u, v);
    }

    sort(edge.begin(), edge.end());

    UF uf(2 * N);

    ll ans = INFLL;

    for(auto [w, u ,v] : edge) {
        if(uf.add(u, v, w)) {
            ans = min(ans, w);
            break;
        }
    }

    ans = min(ans, uf.getAns());

    cout << ans << endl;
}

int main() {

	optimize;
	
	T = 1;
	
	//cin >> T;

    while(T--) {
		solve();
    }

	return 0;
}
