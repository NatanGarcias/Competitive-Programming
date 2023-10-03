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
#define MAXN 1010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;

void solve() {
	cin >> N >> M;

    string s;

    cin >> s;

    set<int> a;

    for(int i = 1; i <= N; i++) if( (s[i - 1] == '(') != (i & 1) ) a.insert(i);

    for(int i = 0, u; i < M; i++) {
        cin >> u;

        if(a.find(u) == a.end()) a.insert(u);
        else a.erase(u);
        
        if(N & 1) cout << "NO\n";
        else if(!a.empty() && ( ( (*a.begin()) & 1) || (*a.rbegin() % 2 == 0) ) ) cout << "NO\n";
        else cout << "YES\n";
    }
}

int main() {

	optimize;
	
	T = 1;
	
    while(T--) {
		solve();
    }

	return 0;
}
