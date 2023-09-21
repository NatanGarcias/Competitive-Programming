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
#define MAXN 310

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
ll dp[MAXN][MAXN][MAXN];
ll suf[MAXN][MAXN][MAXN];
ll A[MAXN], P[MAXN], F[MAXN];

ll solve(int i, int j, int k) {

    if(i == N) {
        if(j == k) return 0;
        return INFLL;
    }

    ll &ans = dp[i][j][k];
    if(ans != -1) return ans;

    ans = INFLL;
    int d = A[i + 1] - A[i];

    if(k != M) solve(i, j, k + 1);

    // Não peguei esse posto
    if(j >= d && k + d <= M) ans = min(ans, solve(i + 1, j - d, k + d));

    if(i) {
        // Peguei na ida
        // Abasteço o carro primeiro até o limite H e depois retiro a distância que vou percorrer
        ll nextJ = min(M, j + F[i]);
        if(nextJ >= d && k + d <= M) {
            ans = min(ans, solve(i + 1, nextJ - d, k + d) + P[i]);
        }

        // Peguei na volta - 2 opções
        if(j >= d && k >= F[i] && k - F[i] + d <= M) {
            solve(i + 1, j - d, k + d - F[i]);
            
            if(k == M)  ans = min(ans, suf[i + 1][j - d][k + d - F[i]] + P[i]);
            else        ans = min(ans, solve(i + 1, j - d, k + d - F[i]) + P[i]);
        }
    }

    suf[i][j][k] = min(ans, suf[i][j][k + 1]);
    return ans;    
}

void solve() {

	cin >> N >> M;
	
    for(int i = 1; i <= N; i++) cin >> A[i];
    for(int i = 1; i < N; i++) cin >> P[i] >> F[i];

    ll ans = INFLL;

    ms(suf, 0x3f);
    ms(dp, -1);

    for(int i = 0; i <= M; i++) {
        ans = min(ans, solve(0, M, i));
    }

    if(ans == INFLL) ans = -1;

    cout << ans << endl;
}

int main() {

	optimize;
	
	T = 1;
	
	//cin >> T;

    while(T--) {
		solve();
    }

	return 0;
}
