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
#define MAXN 2010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
int cnt, cnt2;
pii A[MAXN], B[MAXN];
ll dp[MAXN][MAXN];

ll solve(int i, int k){

    if(i == cnt) return 1;

    if(~dp[i][k]) return dp[i][k];

    ll ans = max( (ll) A[i].fi + 1, solve(i+1,k) + A[i].fi - A[i].se );

    if(k != K) ans = min(ans, solve(i+1,k+1) );

    return dp[i][k] = ans;
}

void solve(){

    sort(B,B + cnt2);

    for(int i=0;i<cnt2;i++) {
        if(M > B[i].fi) M = M + B[i].se - B[i].fi;
        else K--;   
    }

    if(K < 0){
        cout << "N\n";
        return;
    }

    for(int i=0;i<=cnt;i++){
        for(int j=0;j<=K;j++){
            dp[i][j] = -1;
        }
    }

    sort(A,A+cnt);
    reverse(A,A+cnt);

    for(int i=0;i<cnt;i++) swap(A[i].fi, A[i].se);

    ll ans = solve(0,0);

    if(ans <= M) cout << "Y\n";
    else cout << "N\n";
}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
		cin >> N >> M >> K;

        cnt = 0;
        cnt2 = 0;

        for(int i=0,u,v;i<N;i++){
            cin >> u >> v;

            if(v >= u) B[cnt2].fi = u, B[cnt2].se = v, cnt2++;
            else A[cnt].fi = v, A[cnt].se = u, cnt++;
        }

		solve();
    }

	return 0;
}