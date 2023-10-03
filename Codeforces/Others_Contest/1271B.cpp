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
string s;

void arruma(vector<int> &ans) {

    for(int i = 0; i < N - 1; i++) {
        if(s[i] != s[N-1]) {
            ans.pb(i + 1);
            s[i] = s[N-1];

            if(s[i + 1] == 'B') s[i + 1] = 'W';
            else                s[i + 1] = 'B';
        }
    }
}

void solve() {

    int b = 0, w = 0;

    for(auto &i : s){
        if(i == 'B')    b++;
        else            w++;
    }

    if(b & 1 && w & 1) {
        cout << -1 << endl;
        return;
    }

    vector<int> ans;

    arruma(ans);
    arruma(ans);
    arruma(ans);
    
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << " \n"[i == ans.size()-1];
}

int main() {

	optimize;
	
    cin >> N >> s;

    solve();
    
	return 0;
}