#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod %1000000007
#define inf 1000000007

ll fastexpo(ll a, ll n) {
  ll ret = 1;
  ll b = a;
  while (n) {
    if (n & 1)
      ret = (ret * b) mod; // if(n==odd)
    b = (b * b) mod;
    n >>= 1; // n/=2
  }
  return (ll)ret;
}

long long int PA(long long int o){
    return ((o mod * (o + 1) mod) mod) * (fastexpo(2, (ll)inf - 2) mod) mod;
}

long long int QA(long long int o){
    return ((((o mod * (o + 1) mod) mod) * (2 * o + 1) mod) mod * (fastexpo(6, (ll)inf - 2) mod)) mod;
}

int main(){
    long long int n, m, h;
    cin >> n >> m >> h;
    long long int x,y,z,p,q,r;
    cin >> x >> y >> z >> p >> q >> r;
    long long int sum = 0;
    long long int NMH = (((n mod * m mod) mod) * h mod) mod;
    long long int NM = (n mod * m mod) mod;
    long long int NH = (n mod * h mod) mod;
    long long int MH = (m mod * h mod) mod;
    long long int p1 = (NMH * (z mod * r mod) mod) mod;
    long long int p2 = (((NH * (q mod * z mod) mod) mod) * PA(m)) mod;
    long long int p3 = (((NM * (p mod * z mod) mod) mod) * PA(h)) mod;
    long long int p4 = (((NM * (r mod * y mod) mod) mod) * PA(h)) mod;
    long long int p5 = (((NM * (y mod * p mod) mod) mod) * QA(h)) mod;
    long long int p6 = (((MH * (x mod * r mod) mod) mod) * PA(n)) mod;
    long long int p7 = (((((m * (x mod * p mod) mod) mod) * PA(n)) mod) * PA(h)) mod;
    long long int p8 = (((((h * (x mod * q mod) mod) mod) * PA(n)) mod) * PA(m)) mod;
    long long int p9 = (((((n * (y mod * q mod) mod) mod) * PA(h)) mod) * PA(m)) mod;

    sum = (((((((((((((((p1 + p2) mod) + p3) mod) + p4) mod) + p5) mod) + p6) mod) + p7) mod) + p8) mod) + p9) mod;

    cout << sum << endl;

    return 0;
}