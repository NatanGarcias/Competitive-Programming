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

void solve(){

	string ans;

	N = s.size();
	
	for(int i=0;i<N;i++){

		if(i < N-2 && (s[i+1] != s[i]) && (s[i+2] != s[i+1]) && (s[i+2] != s[i]) ){
			ans.pb('C');
			i+= 2;
			continue;
		}
		if(s[i] == 'R')			ans.pb('S');
		else if(s[i] == 'B')	ans.pb('K');
		else if(s[i] == 'L')	ans.pb('H');
	}

	cout << ans << endl;
}

int main(){

	optimize;
	
	cin >> s;

	solve();
    
	return 0;
}