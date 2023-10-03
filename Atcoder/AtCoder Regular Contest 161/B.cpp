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

    if(N < 7) {
        cout << -1 << endl;
        return;
    }

    if(__builtin_popcountll(N) == 1) {
        N--;
    }
    else if(__builtin_popcountll(N) == 2) {
        ll desc = 0;

        if( (N & (1LL << 0)) || (N & (1LL << 1)) ) {
            desc += (N & (1LL << 0));
            desc += (N & (1LL << 1));

            desc += 1;
        }
        else {
            desc = 1;
        }

        N -= desc;
    }
    
    ll i = 0;
    while(__builtin_popcountll(N) > 3) {
        if(N & (1LL << i)) {
            N^= (1LL << i);
        }
        i++;
    }
    
    cout << N << endl;
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
