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
string s;
ll fat[MAXN];

void pre() {

    fat[0] = fat[1] = 1;

    for(ll i = 2; i < MAXN; i++) {
        fat[i] = fat[i - 1] * i;
        fat[i] %= mod;
    }
}

ll f(vector<ll> &a) {

    ll ans = 1, n = 0;
    
    for(int i = 0; i < a.size(); i++) {
        ans *= a[i];
        n += (a[i] - 1);
        ans %= mod;
    }

    ans = fat[n] * ans;
    ans %= mod;

    return ans;
}

void solve() {

    string s;

    cin >> s;

    N = s.size();

    vector<ll> rep;

    int sz = 0, t = 0;
    ll rem = 0;

    for(int i = 0; i < N; i++) {
        if(s[i] == '0') {
            if(t == 0) {
                sz++;
            }
            else {
                if(sz > 1) {
                    rep.push_back(sz);
                    rem += sz - 1;
                }
                sz = 1;
                t = 0;
            }
        }
        else {
            if(t == 1) {
                sz++;
            }
            else {
                if(sz > 1) {
                    rep.push_back(sz);
                    rem += sz - 1;
                }
                sz = 1;
                t = 1;            
            }
        }
    }

    if(sz > 1) {
        if(t == 1) rep.push_back(sz);
        else       rep.push_back(sz);

        rem += sz - 1;
    }

    ll ans = f(rep);

    cout << rem << " " << ans << endl;
}

int main() {

	optimize;
	
    pre();

	T = 1;
    
	cin >> T;

    while(T--) {
		solve();
    }

	return 0;
}
