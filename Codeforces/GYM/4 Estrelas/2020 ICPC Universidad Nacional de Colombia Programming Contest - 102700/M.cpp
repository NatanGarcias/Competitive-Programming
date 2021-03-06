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
#define FOR(x,a,n) for(int x= (int)(a);(x) < int(n);(x)++)
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;

string s,s2;
vector<set<int>> l;

int getchar(char k){
	return (int)(k - 'a');
}

void pre(){

	l.resize(26);

	for(int i=0;i<s.size();i++){
		l[ getchar(s[i]) ].insert(i);
	}
}

void solve(){

	string ans;
	int ptr = -1;

	for(int i=0;i<s2.size();i++){
		int p = getchar(s2[i]);

		auto it = l[p].upper_bound(ptr);
		
		if(it == l[p].end()){
			break;
		}
		else{
			ans.push_back(s2[i]);
			ptr = (*it);
		}
	}

	if(ans.empty()) cout << "IMPOSSIBLE\n";
	else cout << ans << "\n";
}

int main(){

	optimize;
	
	cin >> s;

	pre();

	cin >> T;

    while(T--){
		cin >> s2;

		solve();
    }

	return 0;
}