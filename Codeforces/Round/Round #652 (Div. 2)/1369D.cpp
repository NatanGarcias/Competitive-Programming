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
#define MAXN 2000100

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;

ll dp[MAXN], dp2[MAXN], dp3[MAXN], sum[MAXN];

void preCalc(){

    //1
    dp[1] = 1;

    //2
    dp2[2] = dp[1];
    dp[2] = dp[1] + 2 * dp2[1];

    //3
    dp[3] = dp[2] + 2 * dp2[2];
    dp2[3] = dp[2];
    dp3[3] = dp2[2]; 

    for(int i=3;i<=MAXN - 5;i++){
        dp[i] = (dp[i-1] + (2 * dp2[i-1]) % mod ) % mod;
        dp2[i] = dp[i-1];
        dp3[i] = dp2[i-1]; 
    }

    for(int i=3;i<=MAXN - 5;i++){
        sum[i] = sum[i-3] + ( ( dp3[i] * 4 ) % mod);
        sum[i] %= mod;
    }
}

void solve(){
    cout << sum[N] << endl;
}

int main(){

	optimize;
	
	cin >> T;

    preCalc();

    while(T--){
		cin >> N;
		
		solve();
    }

	return 0;
}