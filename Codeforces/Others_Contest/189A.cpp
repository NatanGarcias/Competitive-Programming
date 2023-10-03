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
#define MAXN 6000

ll T,N,M,K,A,B,C;
int dp[MAXN];

int solve(int i){

    if(i > N) return -INF;
    if(i == N) return 0;

    if(dp[i] == -1){
        int ans = -INF;

        ans = max(ans, solve(i+A) +1);
        ans = max(ans, solve(i+B) +1);
        ans = max(ans, solve(i+C) +1);

        dp[i] = ans;
    }

    return dp[i];

}

void solve(){

    ms(dp,-1);

    int ans = solve(0);

    cout << ans << endl;    
}

int main(){

    cin >> N >> A >> B >> C;

    solve();

	return 0;
}