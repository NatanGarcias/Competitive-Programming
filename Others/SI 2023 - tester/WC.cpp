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
int dp[MAXN][MAXN];
int A[MAXN], B[MAXN];

int solve(int i, int t) {

	if(t < 0) return -INF;
	
	if(i == N) return 0;
	
	if(dp[i][t]) return dp[i][t];
	
	int ans = 0;

	ans = max(ans, solve(i + 1, t));
	ans = max(ans, solve(i + 1, t - A[i]) + B[i]);

	return dp[i][t] = ans;
}

void solve() {

    cin >> N >> M;

	for(int i = 0; i < N; i++) cin >> A[i] >> B[i];

	int ans = solve(0, M);

    cout << ans << endl;
}

int main() {

	//optimize;
	
	T = 1;
	
	//cin >> T;

    while(T--) {
		solve();
    }

	return 0;
}
