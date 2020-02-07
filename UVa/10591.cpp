#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll dig(ll s){
  ll r = 0;
  while(s != 0){
    r += (s % 10) * (s % 10);
    s /= 10;
  }
  return r;
}

int main(){
  ll k,n;
  cin >> k;
  for(ll h=0;h<k;h++){
    cin >> n;
    ll i = n;
    ll cont = 0;
    while(true){
          i = dig(i);
          cont++;
          if(i == 1 || cont > 11){
            if(i == 1){
                cout <<"Case #" << h+1 << ": " << n << " is a Happy number." << endl;
                break;
            }
            else if(cont>11){
                cout <<"Case #" << h+1 << ": " << n << " is an Unhappy number." << endl;
                break;
            }
            else
              break;
          }
    }
  }
}
