#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld; 
typedef unsigned long long ull; 

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
#define FOR(x,n) for(int x=0;(x) < int(n);(x)++)
#define FOR1(x,n) for(int x=1;(x) <= int(n);(x)++)

#define INF 0x3fffffff
#define INFLL 0x3fffffffffffffff

#define mod %998244353
#define num 998244353

#define MAXN 200010

ull N,M;

ull v[MAXN];
ull v2[MAXN];

ull fastExpo(ull a, ull n) {
  ull ret = 1;
  ull b = a;
  while (n) {
    if (n & 1)
      ret = (ret * b) mod; // if(n==odd)
    b = (b * b) mod;
    n >>= 1; // n/=2
  }
  return (ull)ret;
}

void fat(){
    ull cont = 1;
    for(int i=1;i<MAXN;i++){
        v[i] = cont;
        cont = (cont * (i+1)) mod;
    }
}

void pot(){
    ull cont = 1;
    for(int i=0;i<MAXN;i++){
        v2[i] = cont;
        cont = (cont * 2) mod;
    }
}

ull comb(){
    
    ll Mfat = v[M];
    
    ll Kfat = v[N-1];
    
    ll M_N = v[M - (N-1)];
    
    ll A = (Kfat * M_N) mod;
    
    ll exp = fastExpo( A , (num-2) );
    
    return ((Mfat * exp) mod);
}

void solve(){

    if(N == 2) {
        cout << 0 << endl;
        return;
    }

    fat();
    pot();

    ull ans = comb();

    ans = (ans * (N-2)) mod;
    
    ans = (ans * v2[N-3]) mod;  
    
    cout << ans << endl;
}

int main(){

	cin >> N >> M;

	solve();

	return 0;
}