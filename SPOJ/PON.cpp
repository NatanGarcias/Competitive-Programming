#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N,M,K;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll a, ll b){
	return uniform_int_distribution<ll>(a, b)(rng);
}

ll mod_mul(ll a, ll b, ll mod){ 
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

void solve(){
	if(is_probably_prime(N,40)) 	cout << "YES\n";
	else 			cout << "NO\n";
}

int main(){

	cin >> K;

    while(K--){
		cin >> N;
		
		solve();
    }

	return 0;
}