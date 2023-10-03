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
	vector<int> parent, rank;

	UF(int n){
		parent.assign(n+1,0);
		rank.resize(n+1);
		iota(all(parent), 0);
	}	

	int find(int u){
		if(u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}

	bool sameSet(int u, int v){
		return find(u) == find(v);
	}

	void unir(int u, int v){
		u = find(u);
		v = find(v);

		if(u != v){
			if(rank[u] < rank[v]) swap(u,v);
			if(rank[u] == rank[v]) rank[u]++;
			
			parent[v] = u;
		}
	}
};

void solve(){

	UF uf(N);

	for(int i=0;i<M;i++){
		string s;
		int a,b;

		cin >> s >> a >> b;

		a--, b--;

		if(s[0] == 'u') uf.unir(a,b);
		else {
			int ans = uf.sameSet(a,b);

			if(ans) cout << "YES\n";
			else 	cout << "NO\n";
		}
	}
}

int main(){

	optimize;
	
	cin >> N >> M;

	solve();

	return 0;
}