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

#define MAXN 2000100

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;

bool p[MAXN];
vector<ll> primos;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll a, ll b){
	return uniform_int_distribution<ll>(a, b)(rng);
}

ll mod_mul(ll a, ll b, ll mod){ 
	//return (a*b)%mod; 
	ll cur_mod = a;
	ll ans = 0;
	for (int i=0; i<63; i++){
		if ((b>>i)&1) ans = (ans + cur_mod)%mod;
		cur_mod = (2*cur_mod) % mod;
	}
	return ans;
}

ll fexp(ll a, ll e, ll mod){
	if (e == 0) return 1;
	ll p = fexp(a, e/2, mod);
	p = mod_mul(p, p, mod);
	if (e%2 == 1) 
		p = mod_mul(p, a, mod);
	return p;
}

bool miller_rabin (ll p, ll a){

	ll q = p-1, k=0;
	while(q % 2 == 0){
		q /= 2;
		k++;
	}

	ll cur = fexp(a, q, p);
	if (cur == 1 or cur == p-1) return true;

	for (int i=0; i<k; i++){
		if (cur == p-1) return true;
		if (cur == 1) return false;
		cur = mod_mul(cur, cur, p);
	}

	return false;
}

bool is_probably_prime(ll p, int k){
	if (p == 0 or p == 1) return false;
	if (p == 2 or p == 3) return true;
	if (p%2 == 0) return false;

	for (int i=0; i<k; i++) {
		if (!miller_rabin(p, rnd(1, p-1))) return false;
	}

	return true;
}

void crivo(){

    for(ll i=2;i<MAXN;i++){
        if(p[i]) continue;

        primos.pb(i);

        for(ll j = i*i;j< MAXN;j+=i) p[j] = true;
    }
}

bool squar(ll x){
    ll aux = sqrt(x);

    return (aux * aux == x);
}

void solve(){

    ll ans = 1LL;

    for(int i=0;i<primos.size();i++){
        ll alfa = 0;

        while( !(N%primos[i]) ){
            N /= primos[i];
            alfa++;
        }

        ans *= (alfa + 1LL);
    }
    
    if(N == 1) cout << ans << endl;
    else if( is_probably_prime(N,40) ){
        cout << ans*2LL << endl;
    }
    else if( squar(N) ){
        cout << ans*3LL << endl;
    }
    else{
        cout << ans*4LL << endl;
    }

}

int main(){

	optimize;
    
    crivo();

    cin >> N;
		
	solve();
    
	return 0;
}