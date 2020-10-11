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
#define MAXN 2000010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
ll fat[MAXN];

void pre(){
	fat[0] = 1;
	for(ll i=1;i<=2000002;i++) fat[i] = (fat[i-1] * i) % mod;
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

ll comb(int n, int m){
	ll cima = fat[n+m] %mod;
	ll baixo = (fat[m] * fat[n+m -m]) %mod;

	baixo = fastExpo(baixo, mod-2);
	return (cima * baixo) % mod;
}

void solve(){
	N--;
	M--;

	if(M > N) swap(N,M);
	cout << comb(N,M) << endl;
}

int main(){

	pre();

	cin >> T;

	while(T--){
		cin >> N >> M;	
		
		solve();
	}

	return 0;
}