#include<bits/stdc++.h>
using namespace std;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define ll long long
#define ld long double 

#define endl "\n"

#define pll pair<ll,ll>
#define fi first 
#define se second 

#define INF 0x7fffffff
#define INFLL 0x7fffffffffffffff

ll n,k;

vector<pll> jogos; 

bool verifica(ll x){

    ll ans = 0;

    for(ll i=0;i<n;i++){
        if(jogos[i].fi * x - jogos[i].se > 0)
            ans+= jogos[i].fi * x - jogos[i].se;

        if(ans >= k)
            return true;
    }

    return false;
}

int binarySearch(){

    ll l = 1,r = 10000000000;
    
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

    cin >> n >> k;

    for(ll i=0;i<n;i++){   
        int a,b;

        cin >> a >> b;

        jogos.push_back({a,b});
    }

    cout << binarySearch() << endl;

    return 0;
}