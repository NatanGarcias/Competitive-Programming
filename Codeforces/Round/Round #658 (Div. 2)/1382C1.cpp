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

void reverse(string & str){
	for(int i=0;i<str.size()/2;i++) swap(str[i], str[str.size()-i-1]);
}

void inverse(string & str){
	for(int i=0;i<str.size();i++) {
		str[i] ^= 1;
	}
}
 
void solve(){

	vector<int> ans;

	while(!s.empty()){

		while(!s.empty() && s.back() == s2.back()){
			s.pop_back();
			s2.pop_back();
		}
	
		int n = s.size();

		if(s.empty()) break;

		if(*s.begin() == s2.back()){
			s[0] ^= 1;
			reverse(s);
			inverse(s);

			ans.pb(1);
			ans.pb(n);
		}
		else{
			reverse(s);
			inverse(s);
			ans.pb(n);
		}

	}
	
	assert(ans.size() <= 2*N);

	cout << ans.size();

	for(int i=0;i<ans.size();i++){
		cout << " " << ans[i];
	}
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