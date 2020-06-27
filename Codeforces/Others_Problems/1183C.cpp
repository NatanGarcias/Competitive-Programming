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
#define MAXN 100010

ll v[MAXN];
ll N,k,n,a,b;

bool verifica(ll x){
    if(x*a + (n-x)*b < k){
        return true;
    }
    return false;
}

ll binarySearch(){
    
    ll l = 0, r = n;

    while(true){
        ll m = (l+r+1)/2;
        if(l == r){
            return m;
        }else if(verifica(m)){
            l = m;
        }else{
            r = m-1;
        }
    }
}

int main(){

    cin >> N;

    while(N--){
        cin >> k >> n >> a >> b;

        ll cont = 0;

        if(b*n >= k){
            cout << -1 << endl;
        }else{
            cout << binarySearch() << endl;
        }   
    }
    
    return 0;
}