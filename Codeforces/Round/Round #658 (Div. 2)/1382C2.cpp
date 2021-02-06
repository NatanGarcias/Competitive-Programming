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

#define sz(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
string s,s2;

vector<int> ans[2];

void solve(string &str, bool p){

    int n = str.size();
    
    for(int i=0;i<n-1;i++){
        if(str[i+1] != str[i]) ans[p].pb(i+1);
    }
}

void solve(){
	
    ans[0].clear();
    ans[1].clear();

    solve(s,0);
    solve(s2,1);

    if(s.back() != s2.back()) ans[0].pb(N);
    
    cout << ans[0].size() + ans[1].size();
	for(int i = 0 ; i < ans[0].size() ; i++) cout << " " << ans[0][i];

    for(int i = ans[1].size()-1 ; i >= 0 ; i--) cout << " " << ans[1][i];
	cout << endl;
}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
		cin >> N;

		cin >> s >> s2;

		solve();
    }

	return 0;
}