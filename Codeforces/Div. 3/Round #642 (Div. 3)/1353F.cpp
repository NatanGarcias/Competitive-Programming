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
#define MAXN 110

ll T,N,M,K;
ll v[MAXN][MAXN];
ll dp[MAXN][MAXN];

ll solve(int i, int j, ll valor){

    if(v[i][j] < valor) return INFLL;

    if(i == N-1 && j == M-1) return dp[i][j] = v[i][j] - valor;

    if(dp[i][j] == -1){

        ll ans = INFLL;

        if(j < M-1) ans = min(ans, v[i][j] - valor  + solve(i,j+1,valor + 1LL));
        if(i < N-1) ans = min(ans, v[i][j] - valor  + solve(i+1,j,valor + 1LL));
        
        dp[i][j] = ans;
    }

    return dp[i][j];
}

void solve(){

    ll ans = INFLL;

    FOR(i,0,N){
    	FOR(j,0,M){
            ms(dp,-1);
            ll aux = v[i][j] - i - j;
            ans = min(ans, solve(0,0, aux));
    	}
    }

    cout << ans << endl;
}

int main(){

	cin >> T;

    while(T--){
		cin >> N >> M;

        FOR(i,0,N) FOR(j,0,M) cin >> v[i][j];
		
		solve();
    }

	return 0;
}