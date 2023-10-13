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

#define mod 998244353LL
#define MAXN 10100

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
ll A[MAXN], dp[MAXN];

ll fastExp(ll a, ll n) {
	ll ret = 1;
	ll b = a;
  	while (n) {
    	if (n & 1)
     	 	ret = (ret * b) % mod;
    	b = (b * b) % mod;
    	n >>= 1; 
  	}
  	return (ll)ret;
}

void solve() {

	cin >> N >> M;
	
	for(int i = 0; i < N; i++) cin >> A[i];

	ll inv = fastExp(N, mod - 2);

	ll ans = 0;

	dp[0] = 1;

	for(int i = 0; i <= M; i++) {
		for(int j = 0; j < N; j++) {

			int k = i + A[j];

			if(k > M) continue;

			ll val = (dp[i] * inv) % mod;
			dp[k] = (dp[k] + val) % mod;
		}
	}

	for(int i = max(0LL, M + 1 - A[0]); i <= M; i++) {
		ans += (dp[i] * inv) % mod;
		ans %= mod;
	}

	cout << ans << endl;
}

int main() {

	optimize;
	
	T = 1;
	
    while(T--) {
		solve();
    }

	return 0;
}
