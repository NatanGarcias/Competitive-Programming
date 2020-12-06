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
#define MAXM 100000

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
string s;

void solve(){

	vector<int> neg(s.size()+5,0);

	int acum = 0;

	for(int i=1;i<=s.size();i++){
		if(s[i-1] == '+'){
			acum++;

		}else{
			acum--;

			if(acum < 0 && !neg[-acum]) neg[-acum] = i;
		}
	}

	int cnt = 1;
	ll ans = 0;

	while(true){
		
		if(neg[cnt]){
			ans += neg[cnt];

			cnt++;
		}
		else{
			ans += s.size();
			break;
		}
	}

	cout << ans << endl;
}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
		cin >> s;

		solve();
    }

	return 0;
}