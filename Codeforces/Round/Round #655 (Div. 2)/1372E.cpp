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
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 110

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
int dp[MAXN][MAXN], lft[MAXN][MAXN], rgh[MAXN][MAXN];

int solve(int i, int j){

	if(i > j) return 0;

	if(~dp[i][j]) return dp[i][j];

	int ans = 0;

	for(int k=i;k<=j;k++){
		
		int aux = 0;
		for(int l=0;l<N;l++) if(lft[l][k] >= i && rgh[l][k] <= j) aux++;

		ans = max(ans, solve(i,k-1) + aux*aux + solve(k+1,j) );
	}

	return dp[i][j] = ans;
}

void solve(){

	ms(dp, -1);

	int ans = solve(0, M-1);

	cout << ans << endl;
}

int main(){

	optimize;
	
	cin >> N >> M;

	for(int i=0;i<N;i++){
		int a;

		cin >> a;

		for(int j=0;j<a;j++){
			int b,c;

			cin >> b >> c;

			b--, c--;

			for(int k=b;k<=c;k++){
				lft[i][k] = b;
				rgh[i][k] = c;
			}
		}
	}

	solve();

	return 0;
}