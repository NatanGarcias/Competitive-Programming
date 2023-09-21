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
#define MAXN 38

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;

void solve() {

	cin >> N >> M;
    
    vector<ll> nums, pot, q;

    ll u = 1;

    for(int i = 0; i <= MAXN; i++) {
        nums.push_back(u);
        u *= 3;
    }

    u = N;
     
    for(int i = MAXN; i >= 0; i--) {
        ll v = nums[i];
        
        pot.push_back(0);
        
        while(u >= v) {
            u -= v;
            pot.back()++;
            M--;
        }
    }

    for(int i = MAXN; i >= 0; i--) {
        for(int j = 0; j <= i; j++) {
            ll v = nums[i - j];

            for(int k = pot[MAXN - i]; k > 0; k--) {
                if(M >= v * k - k) {
                    pot[MAXN - i] -= k;
                    pot[MAXN - i + (i - j)] += k * v;
                    M = M - k * v + k;
                    break;
                }
            }
        }
    }

    // cerr << pot << endl;
    
    if(M)   cout << "No\n";
    else    cout << "Yes\n";
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
