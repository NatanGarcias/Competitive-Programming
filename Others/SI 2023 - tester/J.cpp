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

    cin >> N;

    ll ans = 0;

    vector<ll> A(N), B(N);
    int ok = true;

    for(int i = 0; i < N; i++) {
        cin >> A[i];
        ans += A[i];

        if(i && A[i] != A[i - 1]) ok = false;
    }

    while(!ok) {
        ok = true;

        for(int i = 0; i < N; i++) {
            int u = i;
            int v = (i + 1) % N;
            B[i] = abs(A[u] - A[v]);
            ans += B[i];
            if(i && B[i] != B[i - 1]) ok = false;
        }

        A = B;
    }

    cout << ans << endl;
}

int main() {

	//optimize;
	
	T = 1;
	
	//cin >> T;

    while(T--) {
		solve();
    }

	return 0;
}
