#include<bits/stdc++.h>
using namespace std;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define ll long long
#define ld long double 

#define endl "\n"

#define pii pair<int,int>
#define fi first 
#define se second 

#define INF 0x7fffffff
#define INFLL 0x7fffffffffffffff

#define MAXN 100010

int v[MAXN];
int n,c,t;

bool verifica(ll x){

    ll ans = 0;
    ll cont = 0;

    for(int i=0;i<n;i++){

        if(ans + v[i] > x*t ){
            
            cont++;
            
            if(cont >= c){
                return false;
            }

            i--;
            ans = 0;
            
        }
        else
            ans +=v[i];
    }

    return true;

}

int binarySearch(){

    ll l = 1, r = 1000000010;

    while(true){
        ll m = (l+r)/2;

        if(l==r)
            return m;
        else if(verifica(m))
            r = m;
        else 
            l = m+1;
    }
}

int main(){

    cin >> n >> c >> t;

    for(int i=0;i<n;i++){
        cin >> v[i];
    }

    cout << binarySearch() << endl;

    return 0;
}