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
#define MAXN 2010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
int A[2 * MAXN], B[2 * MAXN], dp[2 * MAXN][MAXN];

bool solve(int i, int j, vector<int> &tam){

    if(j >= N) return j == N;

    if(i == tam.size()) return false;

    if(~dp[i][j]) return dp[i][j];

    dp[i][j] = max( solve(i+1,j + tam[i], tam), solve(i+1,j, tam) );

    return dp[i][j];
}

void solve(){

    B[0] = A[0];
    for(int i=1;i<2*N;i++){
        B[i] = max(A[i], B[i-1]);
    }

    vector<int> tam;
    int cnt = 0;

    for(int i=2*N-1;i>=0;i--){
        ++cnt;

        if(B[i] == A[i]){
            tam.pb(cnt);
            cnt = 0;
        }
    }

    if(cnt) tam.pb(cnt);

    sort(all(tam));

    for(int i=0;i<2*N;i++){
        for(int j=0;j<N;j++){
            dp[i][j] = -1;
        }
    }

    bool ans = solve(0, 0, tam);

    if(ans) cout << "YES\n";
    else    cout << "NO\n";

}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
		cin >> N;

        for(int i=0;i<2*N;i++) cin >> A[i];
		
		solve();
    }

	return 0;
}