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

unordered_map<ll, ll> dp;
set<ll> nums;

// P = 1, S = 2, R = 3;

ll solve(ll i){

	if(dp.find(i) != dp.end()){
		return dp[i];
	}

	ll ans = 0;
	ll p = *nums.upper_bound(-i);

	ans = solve(i + p);

	if(ans == 1) ans = 2;
	else if(ans == 2) ans = 3;
	else if(ans == 3) ans = 1;

	return dp[i] = ans;
}

void pre(){
	ll aux = 3LL;

	while(aux < (ll) 1e13){
		nums.insert(-aux);
		aux *= 3LL;
	}

	dp[1] = 3;
	dp[2] = 1;
	dp[3] = 2;
}

void solve(){
	
	int aux = solve(N);

	if(aux == 1) cout << "S\n";
	if(aux == 2) cout << "R\n";
	if(aux == 3) cout << "P\n";
}

int main(){

	optimize;

	pre();

    while(cin >> N && N){
		solve();
    }

	return 0;
}