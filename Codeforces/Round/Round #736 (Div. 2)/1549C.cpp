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

vector<set<int>> adjOut;

void solve(){

	int cnt = 0;

	cin >> K;

	for(int i = 0; i < N; i++){
		if(adjOut[i].empty()) cnt++;
	}

	for(int i = 0, t, u, v; i < K; i++) {
		cin >> t;

		if(t == 1 || t == 2){
			cin >> u >> v;
			
			u--, v--;

			if(u > v) swap(u,v);

			if(t == 1) {
				if(adjOut[u].empty()) cnt--;
				adjOut[u].insert(v);
			}
			else if(t == 2){
				adjOut[u].erase(adjOut[u].find(v));
				if(adjOut[u].empty()) cnt++;
			}
		}
		else{
			cout << cnt << endl;
		}
	}
}

int main(){

	optimize;
	
	cin >> N >> M;
	
	adjOut.resize(N);

	for(int i = 0, u ,v; i < M ; i++){
		cin >> u >> v;

		u--, v--;

		if(u > v) swap(u,v);

		adjOut[u].insert(v);
	}
	
	solve();

	return 0;
}