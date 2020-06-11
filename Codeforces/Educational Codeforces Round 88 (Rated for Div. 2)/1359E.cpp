#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld; 

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

#define pii pair<int,int>
#define fi first 
#define se second 
#define pb push_back

#define sz(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define FOR(x,a,n) for(int x= (int)(a);(x) < int(n);(x)++)
#define ms(x,a) memset(x,a,sizeof(x))

#define PI 3.141592653589793238462643383279502884
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 998244353
#define MAXN 500010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
ll fat[MAXN];

void pre(){
	fat[0] = 1;
	for(ll i = 1; i <MAXN -2; i++) fat[i] = (i * fat[i-1]) % mod; 
}

ll fastExpo(ll a, ll n) {
	ll ret = 1;
	ll b = a;
  	while (n) {
    	if (n & 1)
     	 	ret = (ret * b) %mod;
    	b = (b * b) %mod;
    	n >>= 1;
  	}
  	return (ll)ret;
}

void solve(){

	if(M > N){
		cout << 0 << endl;
		return;
	}

	if(M == N){
		cout << 1 << endl;
		return;
	}

	ll ans = 0;

	for(int i=1;i<= N/M; i++){
		ll qt = N/i;
		qt--;

		ll cima = fat[qt]; 
		ll baixo = (fat[M-1] * fat[ qt - (M-1) ]) % mod;

		baixo = fastExpo(baixo, mod-2) %mod;
		
		ans = (ans + ((cima*baixo) %mod)) %mod; 
	}

	cout << ans << endl;
}

int main(){
	
	pre();

	cin >> N >> M;
		
	solve();

	return 0;
}