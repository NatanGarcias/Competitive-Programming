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
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()

#define PI 3.141592653589793238462643383279502884
#define FOR(x,n) for(int x=0;(x) < int(n);(x)++)
#define FOR1(x,n) for(int x=1;(x) <= int(n);(x)++)

#define INF 0x7fffffff
#define INFLL 0x7fffffffffffffff

#define mod %1000000007

int t;

int main(){

    ll x,y,a,b;

    cin >> t;

    while(t--){

        cin >> x >> y >> a >> b;

        if( (y-x)%(a+b) == 0){
            cout << (y-x)/(a+b) << endl;
        }else{
            cout << -1 << endl;
        }
    }
  	return 0;
}