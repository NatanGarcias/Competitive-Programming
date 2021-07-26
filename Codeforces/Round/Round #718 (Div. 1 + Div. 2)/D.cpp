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
#define MAXN 550
#define MAXM 15
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;

int h[MAXN][MAXN], v[MAXN][MAXN];
int ans[MAXN][MAXN];

int dp[MAXN][MAXN][MAXM];

int solve(int i, int j, int k){

    int ans = INF;

    if(i > 0)   ans = min(ans, 2 * v[i-1][j] + dp[i-1][j][k-1]);
    if(i < N-1) ans = min(ans, 2 * v[i][j] + dp[i+1][j][k-1]);
    if(j > 0)   ans = min(ans, 2 * h[i][j-1] + dp[i][j-1][k-1]);
    if(j < M-1) ans = min(ans, 2 * h[i][j] + dp[i][j+1][k-1]);
    
    return dp[i][j][k] = ans;
}

void solve(){

    if(K&1){
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                cout << -1 << " \n"[j==M-1];
            }
        }
        return;
    }

    K /= 2;

    for(int k=1;k<=K;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                dp[i][j][k] = solve(i,j,k);

                if(k == K) ans[i][j] = dp[i][j][k];
            }
        }
    }

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cout << ans[i][j] << " \n"[j==M-1];
        }
    }
}

int main(){

	optimize;

	cin >> N >> M >> K;

    for(int i=0;i<N;i++) for(int j=0;j<M-1;j++) cin >> h[i][j];
    for(int i=0;i<N-1;i++) for(int j=0;j<M;j++) cin >> v[i][j];

	solve();
    
	return 0;
}