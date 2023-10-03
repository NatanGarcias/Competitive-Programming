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

void solve(int caso) {

	int m[3][4], v[4];

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++) {
            cin >> m[i][j];
        }
    }

    for(int j = 0; j < 4; j++) {
        v[j] = 1000000;        
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++) {
            v[j] = min(v[j], m[i][j]);
        }
    }

    int n = 1000000;

    for(int j = 0; j < 4; j++) {
        if(v[j] >= n) {
            v[j] = n;
            n = 0;
        }
        else {
            n -= v[j];
        }
    }

    cout << "Case #" << caso << ": ";
    if(n == 0) {
        cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << "\n";
    }
    else {
        cout << "IMPOSSIBLE\n";
    }
}

int main() {

	optimize;
	
	cin >> T;

    for(int i = 1; i <= T; i++) {
        solve(i);
    }

	return 0;
}