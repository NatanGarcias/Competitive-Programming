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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
ll v[MAXN];
ll dp[MAXN];

ll solve(int i){

	if(dp[i] == -1){
		ll aux = 1;

		if(i > 0 && v[i] > v[i-1]) aux = max(aux, solve(i-1) + 1LL);
		if(i < N-1 && v[i] > v[i+1]) aux = max(aux, solve(i+1) + 1LL);

		dp[i] = aux;
	}

	return dp[i];
}

void solve(){

	ms(dp, -1);

	if(N == 1){
		cout << 1 << endl;
		return;
	}

	FOR(i,0,N){
		if(!i){
			if(v[i] >= v[i+1]) solve(i);
		}else if(i == N-1){
			if(v[i] >= v[i-1]) solve(i);
		}else{
			if(v[i] >= v[i-1] &&  v[i] >= v[i+1]) solve(i);
		}
	}

	ll ans = 0;
	FOR(i,0,N) ans += dp[i];

	cout << ans << endl;
}

int main(){

	cin >> N;

	FOR(i,0,N) cin >> v[i];
	
	solve();

	return 0;
}