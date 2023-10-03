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

#define sz(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define FOR(x,a,n) for(int x= (int)(a);(x) < int(n);(x)++)
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXM 5010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
int v[MAXM];
int dp[MAXM][MAXM];
int pre[MAXM][MAXM];

int solve(int i, int j){

	if(i < 0) return 0;

	if(dp[i][j] == -1){
		int ans = INF;

		ans = 1 + solve(i-1,j);

		if(v[i] <= j) ans = min(ans, solve(i-1,min(v[i],j)));

		dp[i][j] = ans;
	}

	return dp[i][j];
}

void solve(){

	ms(dp,-1);

	int ans = solve(N-1,M);

	cout << ans << endl;
}

int main(){

	cin >> N >> M;
	
	FOR(i,0,N){
		ld a, lixo;

		cin >> a >> lixo;

		v[i] = a;
	}	
	
	solve();
    
	return 0;
}