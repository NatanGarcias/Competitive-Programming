#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;

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
ll A[6];
ll ans = 0;

struct POS{
    ll tIX, tIY;
    ll cX, cY;
    ll tFX, tFY;

    POS(ll _tIX, ll _tIY, ll _cX, ll _cY, ll _tFX, ll _tFY) {
        tIX = _tIX;
        tIY = _tIY;
        cX = _cX;
        cY = _cY;
        tFX = _tFX;
        tFY = _tFY;
    }

    void print() {
        cout << "taka precisa ir para: " << pii(tIX, tIY) << endl;
        cout << "cargo está em: " << pii(cX, cY) << endl;
        cout << "taka termina em: " << pii(tFX, tFY) << endl;
    } 
};

ll dist(ll x, ll y, ll x2, ll y2) {
    if(x == x2 && y == y2) return 0;

    ll add = 0;

    if(x == x2) {
        if(y <= A[3] && A[3] < y2) add = 2;
        if(y >= A[3] && A[3] > y2) add = 2; 

        return abs(y - y2) + add;
    }

    if(y == y2) {
        if(x <= A[2] && A[2] < x2) add = 2;
        if(x >= A[2] && A[2] > x2) add = 2; 

        return abs(x - x2) + add;
    }

    return abs(x - x2) + abs(y - y2);
}

vector<POS> f() {
    vector<POS> pos;

    if(A[2] < A[4])         pos.emplace_back(A[2] - 1, A[3], A[4], A[3], A[4] - 1, A[3]);
    else if(A[2] > A[4])    pos.emplace_back(A[2] + 1, A[3], A[4], A[3], A[4] + 1, A[3]);

    if(A[3] < A[5])         pos.emplace_back(A[2], A[3] - 1, A[2], A[5], A[2], A[5] - 1);
    else if(A[3] > A[5])    pos.emplace_back(A[2], A[3] + 1, A[2], A[5], A[2], A[5] + 1);

    return pos;
}

void solve() {

    for(int i = 0; i < 6; i++) cin >> A[i];

    auto a = f();

    if(a.size() == 2) {
        ll d1 = dist(A[0], A[1], a[0].tIX, a[0].tIY);
        ll d2 = dist(A[0], A[1], a[1].tIX, a[1].tIY); 

        // a[0].print();
        // a[1].print();

        if(d1 < d2) {
            ans += d1;
            ans += abs(A[2] - A[4]);

            A[2] = a[0].cX;
            A[3] = a[0].cY;

            A[0] = a[0].tFX;
            A[1] = a[0].tFY;
        }
        else {
            ans += d2;
            ans += abs(A[3] - A[5]);

            A[2] = a[1].cX;
            A[3] = a[1].cY;

            A[0] = a[1].tFX;
            A[1] = a[1].tFY;
        }

        a = f();
    }
    // cerr << "P1: " << ans << endl;

    if(a.size() == 1) {
        ll d = dist(A[0], A[1], a[0].tIX, a[0].tIY);

        ans += d;

        if(A[2] != A[4]) ans += abs(A[2] - A[4]);
        else             ans += abs(A[3] - A[5]);
    }
    // cerr << "P2: " << ans << endl;

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
