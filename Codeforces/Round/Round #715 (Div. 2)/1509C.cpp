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
#define MAXN 2020

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
ll A[MAXN];
ll dp[MAXN][MAXN];

ll solve(int i, int j){

	if(i == 0 && j == N-1) return 0;

	if(dp[i][j] != -1) return dp[i][j];

	ll ans = INFLL;

	if(j != N-1) {
		ans = min(ans, solve(i,j+1) + A[j+1] - A[i]);
	}
	if(i){
		ans = min(ans, solve(i-1,j) + A[j] - A[i-1]);
	}

	return dp[i][j] = ans;
}

void solve(){

	sort(A,A+N);

	ll ans = INFLL;

	ms(dp, -1);

	for(int i=0;i<N;i++) {
		ll aux = solve(i,i);
		
		ans = min(ans, aux);
	}

	cout << ans << endl;
}

int main(){

	optimize;
	
	cin >> N;
	
	for(int i=0;i<N;i++) cin >> A[i];

	solve();

	return 0;
}