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
#define MAXN 40

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;

ll dp[MAXN][MAXN];
ll comb(int n, int k){

    if(k > n) return 0;

    if(k == 0 || n == k) return 1;

    if(dp[n][k] == -1) return dp[n][k] = comb(n-1,k-1) + comb(n-1,k);

    return dp[n][k];
}

void solve(){

    ms(dp, -1);

    ll ans = 0;

    for(int i=2;i<=N;i++){
        ans += comb(N,i);
    }

    cout << ans << endl;

}

int main(){

	optimize;
	
	cin >> N;
		
	solve();

	return 0;
}