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
ll A[MAXN];

bool f(int x) {

    int cnt = 1;
    int pos = A[0];

    for(int i = 1; i < N; i++) {
        if(A[i] >= pos + x) {
            cnt++;
            pos = A[i];
        }
    }

    return cnt >= M;
}

ll bb() {
    ll l = 0, r = INF;

    while(l < r) {
        ll m = (l + r + 1) / 2 ;

        if( f(m) )  l = m;
        else        r = m - 1;
    }

    return l;
}

void solve() {

    cin >> N >> M;

    for(int i = 0 ; i < N; i++) {
        cin >> A[i];
    }

    sort(A,A+N);

    cout << bb() << endl;
}

int main() {

	optimize;
	
	cin >> T;

    while(T--) {
		solve();
    }

	return 0;
}