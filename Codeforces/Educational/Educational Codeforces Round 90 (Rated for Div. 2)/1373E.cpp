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
ll T,N,M,K;

ll prefix(ll x){
	if(x < 9) return x;

	//Primeiro número não pode ser 9
	ll p = 1, ans = 8;
	x -= 8;

	//Acho o prefixo do número
	while(x){
		p *= 10;
		ans += p*min(x, 9LL);
		x -= min(9LL, x);
	}

	return ans;
}

void solve(){

	ll ans = INFLL, s, p = 1;

	for(ll i=0;i<17;i++){
		p *= 10LL;

		for(ll j=0;j<10;j++){
			M = N;
			s = 0;

			ll m = min(K+1, 10LL - j);

			for(ll k=0;k<=K;k++){
				s += (j+k)%10LL;
			}

			// M -= (f(x+1) - f(x)) - (f(x+2) - f(x)) ...
			// M -= Sequencia de 9 nos números
			// M -= Quantidade de números acima do prefixo escolhido
			M -= s;
			M -= i*9LL*m;
			M -= (K+1 - m);

			if(M >= 0 && !(M%(K+1))){
				ans = min(ans, prefix(M/(K+1LL)) * p + p - 10LL + j);
			}
		}
	}

	if(ans == INFLL) 	cout << -1 << endl;
	else 				cout << ans << endl;
}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
		cin >> N >> K;
		
		solve();
    }

	return 0;
}