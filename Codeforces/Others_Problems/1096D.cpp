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
#define MAXN 200010
#define MAXM 5

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
ll v[MAXN];
ll dp[MAXN][MAXM];
string s;

int let(char k){

	if(k == 'h') return 0;
	if(k == 'a') return 1;
	if(k == 'r') return 2;
	if(k == 'd') return 3;
	return -1;
}

ll solve(int i, int j){

	if(j == 4) return INFLL;
	if(i == N) return 0;

	if(dp[i][j] == -1){
		
		if(let(s[i]) != j) dp[i][j] = solve(i+1,j);

		else dp[i][j] = min(solve(i+1,j+1) , v[i] + solve(i+1,j));
	}

	return dp[i][j];
}

void solve(){

	ms(dp, -1);

	ll ans = solve(0,0);

	cout << ans << endl;
}

int main(){

	cin >> N;

	cin >> s;

	FOR(i,0,N) cin >> v[i];
	
	solve();
    
	return 0;
}