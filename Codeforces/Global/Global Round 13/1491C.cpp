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
#define MAXN 55050

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
ll A[MAXN];

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

void solve(){

	ll ans = 0;

	UF uf(N+1);

	for(int i=1;i<=N;i++) if(A[i] == 1) uf.unir(i, i+1);

	for(int i=1;i<N;i++){
		if(A[i] == 1) continue;

		if(A[i] + i > N){
			ans += (A[i] + i) - N;
			A[i] = N - i;

			if(A[i] == 1) {
				uf.unir(i, i+1);
				continue;
			}
		}

		for(int j = i + 2 ; j <= min(N,A[i] + i) ; j++){
			ans++;

			int u = uf.find(j);

			while(u <= N){
				A[u]--;
				
				if(A[u] == 1)	uf.unir(u,u+1);	
				
				if(u + A[u] + 1 <= N) 	u = uf.find(u + A[u] + 1);
				else 					u = N+1;
			}
		}

		A[i] = 1;
		uf.unir(i, i+1);
	}

	if(A[N] != 1){
		ans += A[N] - 1LL;
		A[N] = 1;
	}

	cout << ans << endl;
}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
		cin >> N;

		for(int i=1;i<=N;i++) cin >> A[i];
		
		solve();
    }

	return 0;
}