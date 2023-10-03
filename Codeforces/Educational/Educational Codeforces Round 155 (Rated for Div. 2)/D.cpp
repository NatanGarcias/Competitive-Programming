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

#define mod 998244353LL
#define MAXN 300010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
ll A[MAXN];

void solve() {

	cin >> N;

    for(ll i = 0; i < N; i++) cin >> A[i];

    ll ans = 0;

    for(ll i = 0; i < 31; i++) {
        vector<ll> m(2, 0), l(2, 0);
        ll sum = 0, l1 = 0, l2 = 0, x = 0;

        m[0] = 1;

        for(ll j = 0; j < N; j++) {
            
            ll lig = 0, curr = 0;
            if(A[j] & (1LL << i)) lig = 1;
            
            x ^= lig;

            m[x]++;
            l[x] += j + 1;
            curr = (j + 1) * m[x ^ 1] - l[x ^ 1];
            curr %= mod; 
            
            sum += curr;
            sum %= mod;
        }
        ans += sum * (1LL << i);
        ans %= mod;
        
        cerr << "ans: " << ans << endl;
        cerr << endl;
    }

    cout << ans << endl;
}

int main() {

	optimize;
	
	T = 1;
	
	// cin >> T;

    while(T--) {
		solve();
    }

	return 0;
}
