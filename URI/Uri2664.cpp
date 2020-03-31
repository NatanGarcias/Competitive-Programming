#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld; 

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define endl "\n"
#define space " " 

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
#define MAXT 50

int T,N,M,R;
ll dp[MAXN][MAXT];
bool ok[MAXN][MAXT];

ll solve(int pos, int tempo){

	if(!ok[pos][tempo]){
		if(pos == N){
			ok[pos][tempo] = true;
			dp[pos][tempo] = solve(pos + 1,tempo-1);
		}else if (pos == M){
			ok[pos][tempo] = true;
			dp[pos][tempo] = solve(pos - 1,tempo-1);		
		}else{
			ok[pos][tempo] = true;
			dp[pos][tempo] = ( (solve(pos-1,tempo-1)  + solve(pos+1,tempo-1))  % mod);			
		}
	}

	return dp[pos][tempo];
}

void solve(){

	ll ans = 0;

	T--;
	N--;
	M--;

	FOR(i,N,M+1){
		ok[i][0] = true;
		dp[i][0] = 1;
	}

	FOR(i,N,M+1){
		ll aux = solve(i,T);
		ans = (ans + aux) % mod;
	}

	cout << ans << endl;
}

int main(){

	cin >> T >> N >> M;

	solve();

	return 0;
}