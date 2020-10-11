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

#define mod 1000000007
#define MAXN 1010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;

ll f[MAXN];
ll g[MAXN][MAXN];
ll h[MAXN];

ll fastExp(ll a, ll n){

	ll ret = 1;
	ll b = a;

	while(n){
		if(n&1) ret = (ret*b) %mod;
		b = (b*b) %mod;
		n >>=1; 
	}	
	return (ll)ret;
}

void pre(){
	f[1] = 1;
	f[2] = 2;
	f[3] = 4;
	f[4] = 8;

	FOR(i,5,1001) f[i] = (f[i-1] +  f[i-2] + f[i-3] + f[i-4]) % mod;

	FOR(i,1,1001){
		FOR(j,1,1001){
			g[i][j] = fastExp(f[j],i);
		}
	}
}

void solve(){

	FOR(i,1,M+1){
		h[i] = g[N][i];
		FOR(j,1,i) h[i] = ((h[i] - ((h[j] * g[N][i-j]) %mod) ) + mod) %mod;
	}

	cout << h[M] << endl;
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