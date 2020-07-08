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

#define mod 998244353LL
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
string s,s2;
int v[MAXN];

ll fastExpo(ll a, ll n) {
	ll ret = 1;
	ll b = a;
  	while (n) {
    	if (n & 1)
     	 	ret = (ret * b) %mod; // if(n==odd)
    	b = (b * b) %mod;
    	n >>= 1; 
  	}
  	return (ll)ret;
}

void solve(){

    int sum = 0;
    FOR(i,0,M){
        if(s2[i] == '1') sum++;
        v[i] = sum;
    }

    ll ans = 0;
    int cont = 1;
    for(int i = N-1;i>=0;i--){
        if(M- cont < 0 )break;
        if(s[i] == '1'){
            ll aux = fastExpo(2,N-i-1) %mod;
            aux = (v[M-cont] * aux) %mod;
            ans = (aux + ans)%mod;
        }
        cont++;
    }

    cout << ans << endl;
}

int main(){
    
    cin >> N >> M;

    cin >> s >> s2;

    solve();

	return 0;
}