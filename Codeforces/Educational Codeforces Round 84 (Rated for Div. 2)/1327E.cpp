#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld; 

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define endl "\n"
#define space " " 

#define pii pair<int,int>
#define fi first 
#define se second 
#define pb push_back
#define sz(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define ms(x) memset(x,0,sizeof(x))
#define ms2(x) memset(x,-1,sizeof(x))
#define PI 3.141592653589793238462643383279502884
#define FOR(x,a,n) for(int x=a;(x) < int(n);(x)++)
#define INF 0x3fffffff
#define INFLL 0x3fffffffffffffff

#define mod 998244353

#define MAXN 200010

int T;
ll pd[MAXN];
ll d[MAXN];
ll s[MAXN];

void imprimi(){
	
	for(int i= T;i>=1;i--){
		cout << pd[i] << " ";
	}

	cout << endl;
}

void solve(){

	ll exp = 1;
	ll temp = 0;

	vector<ll> sol;

	d[0] = s[0] = 0;

	FOR(i,1,T+1){
		exp *= 10;
		exp = exp % mod;
		ll ans =  i * exp;

		ll j = 1;
		
		s[i] = (s[i-1] + pd[i-1]) %mod;
		d[i] = (d[i-1] + s[i-1] + (2*pd[i-1] %mod)) %mod;

		pd[i] = (ans - d[i] + mod) %mod;
	}

	imprimi();
}

int main(){

	cin >> T;

	solve();

	return 0;
}