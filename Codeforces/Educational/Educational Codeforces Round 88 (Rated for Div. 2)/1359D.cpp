#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld; 

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

#define pii pair<int,int>
#define fi first 
#define se second 
#define pb push_back

#define sz(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define FOR(x,a,n) for(int x= (int)(a);(x) < int(n);(x)++)
#define ms(x,a) memset(x,a,sizeof(x))

#define PI 3.141592653589793238462643383279502884
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007
#define MAXN 100010

ll T,N,M,K;

int v[MAXN];
int dp[MAXN][32][2];

int solve(int i, int j, int flag){

	if(i == N && flag) return 0;
	if(i == N && !flag) return -INF;

	if(dp[i][j][flag] != -1) return dp[i][j][flag];

	if(v[i] == j && !flag) return dp[i][j][flag] = max(0,solve(i+1,j,1));

	if(v[i] > j) return dp[i][j][flag] = -INF;

	return dp[i][j][flag] = v[i] + max( (flag ? 0 : -INF), solve(i+1,j,flag)); 
}

void solve(){

	int ans = 0;

	ms(dp,-1);

	FOR(i,0,N){
		FOR(j,1,31){
			ans = max(ans, solve(i,j,0));
		}
	}

	cout << ans << endl;
}

int main(){

	cin >> N;
	
	FOR(i,0,N) cin >> v[i];

	solve();

	return 0;
}