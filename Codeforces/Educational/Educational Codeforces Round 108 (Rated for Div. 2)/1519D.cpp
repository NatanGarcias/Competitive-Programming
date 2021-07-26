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
#define MAXN 5010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;

ll A[MAXN], B[MAXN];
ll dp[MAXN][MAXN];

ll solve(int i, int j){

    if(j < i) return -INFLL;
    if(i == j) return dp[i][j] = 0;
    if(dp[i][j] + 1) return dp[i][j];

    ll ans = 0;

    if(i == j-1){
        ans = (A[i] * B[j] + B[i] * A[j]) - (A[i] * B[i] + B[j] * A[j]);
    }
    else{
        ans = (A[i] * B[j] + B[i] * A[j]) - (A[i] * B[i] + B[j] * A[j]) + solve(i+1,j-1);
    }

    return dp[i][j] = ans;
}

void solve(){

    ms(dp,-1);

    ll sum = 0, ans = 0;

    for(int i=0;i<N;i++) sum += A[i]*B[i];

    for(int i=0;i<N;i++) for(int j=0;j<N;j++) if(j >= i) ans = max(ans, sum + solve(i,j) );

    cout << ans << endl;
}

int main(){

	optimize;
	
	cin >> N;

    for(int i=0;i<N;i++) cin >> A[i];
    for(int i=0;i<N;i++) cin >> B[i];

	solve();
    
	return 0;
}