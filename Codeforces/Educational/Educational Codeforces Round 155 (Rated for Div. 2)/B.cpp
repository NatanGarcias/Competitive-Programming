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
#define MAXN 300010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
ll A[MAXN], B[MAXN];

void solve() {

	cin >> N;

    ll ans = 0;

    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];

    ll m1 = INF, m2 = INF;

    for(int i = 0; i < N; i++) m1 = min(m1, A[i]);
    for(int i = 0; i < N; i++) m2 = min(m2, B[i]);

    ll sum1 = 0, sum2 = 0;

    for(int i = 0; i < N; i++) sum1 += A[i];
    for(int i = 0; i < N; i++) sum2 += B[i];

    sum1 += m2 * N;
    sum2 += m1 * N;

    ans = min(sum1, sum2);

    cout << ans << endl;

}

int main() {

	optimize;
	
	T = 1;
	
	cin >> T;

    while(T--) {
		solve();
    }

	return 0;
}
