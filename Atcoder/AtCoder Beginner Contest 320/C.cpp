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

    string s[3];
    map<char, vector<int>> m[3];

    for(int i = 0; i < 3; i++) cin >> s[i];

    for(int i = 0 ; i < 3; i++) {
        for(int j = 0; j < N * 3; j++) {
            m[i][ s[i][j%N] ].push_back(j);
        }
    }

    int ans = INF;

    for(auto [k, a]: m[0]) {

        auto b = m[1][k];
        auto c = m[2][k];
        
        // cerr << k << ": " << a << " " << b << " " << c << endl;
        
        for(int t1: a) {
            for(int t2: b) {    
                for(int t3: c) {
                    if(t1 != t2 && t1 != t3 && t2 != t3) {
                        int curr = max(t1, t2);
                        curr = max(curr, t3);

                        ans = min(ans, curr);   
                    }
                }
            }            
        }
    }

    if(ans == INF) ans = -1;

    cout << ans << endl;
}

int main() {

	optimize;
	
	T = 1;
	
	//cin >> T;

    while(T--) {
		solve();
    }

	return 0;
}
