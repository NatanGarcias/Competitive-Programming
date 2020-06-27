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
#define MAXM 1000010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
string s,s2;

void solve(){

	int cont = 0;

	FOR(i,0,N){
		if(s[i] == '1') cont++;
		if(s2[i] == '1') cont--;
	}
	if(cont){
		cout << -1 << endl;
		return;
	}

	int p = 0, q = 0, ans = 0;

	FOR(i,0,N){
		if(s[i] == s2[i]) continue;
		if(s[i] == '1'){
			if(p) p--;
			else ans++;
			q++;
		}else{
			if(q) q--;
			else ans++;
			p++;
		}
	}

	cout << ans << endl;
}

int main(){

	cin >> N >> s >> s2;

    solve();

	return 0;
}