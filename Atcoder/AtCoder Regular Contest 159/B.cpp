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
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;

void solve() {

	cin >> N >> M;
    
    ll ans = 0;

    while(N && M) {
        ll g = __gcd(N, M);

        if(g > 1) {
            ans += 1;
            N = N / g - 1;
            M = M / g - 1;  
            continue;
        }

        if(N < M) swap(N, M);

        ll d = N - M;
        ll b = 0;

        for(ll i = 1; i * i <= d; i++) {
            if(d % i != 0) continue;

            // para todos os divisores de i
            ll x = d / i;

            // maior valor de x < N que tenha o gcd diferente de 1 com d
            // dado que N > M e N = M + d
            // gcd(N, M) = gcd(d, M)

            if((M / i) * i < M)   b = max(b, (M / i) * i); 
            if((M / x) * x < M)   b = max(b, (M / x) * x);
        }

        ans += M - b;
        N = b + d;
        M = b;
    }

    cout << ans << endl;
}

int main() {

	optimize;
	
	T = 1;

    while(T--) {
		solve();
    }

	return 0;
}
