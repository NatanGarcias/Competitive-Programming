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

#define mod 1000000007
#define MAXN 100010
#define MAXL 200010

ll T,N,M,K;
int v[MAXN];

vector<ll> primos;
bool nums[MAXL];

void crivo(ll limite){
	
	ll tam_crivo = limite+1;

	for(ll i=2;i<= tam_crivo;i++){
		if(!nums[i]){
			for(ll j = i*i;	j<=tam_crivo;j+=i) nums[j] = true;
			primos.pb(i);
		}
	}
}

void solve(){

	crivo(200000);

	ll ans = 1;
	for(int i=0;i<sz(primos);i++){
		int differ = 0;

		for(int j=0;j<N;j++){
			if( v[j]%primos[i] ) differ++;
			else v[j] /= primos[i];

			if(differ >= 2) break;
		}

		if(differ <= 1) {
			ans *= primos[i];
			--i;
		}
	}

	cout << ans << endl;
}

int main(){

	cin >> N;

	FOR(i,0,N) cin >> v[i];
	
	solve();

	return 0;
}