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
#define FOR(x,n) for(int x=0;(x) < int(n);(x)++)
#define FOR1(x,n) for(int x=1;(x) <= int(n);(x)++)

#define INF 0x3fffffff
#define INFLL 0x3fffffffffffffff

#define mod %1000000007

#define MAXN 200010

ll v[MAXN];
ll v2[MAXN];

int T,N,M;

bool verifica(ll valor, int pos){

    if(valor + v[pos] > 0){
        return true;
    }else{
        return false;
    }
}

int binarySearch(ll valor, ll pos){

    int l = pos , r = T-1;
    
    while(true){
        ll m = (l+r+1)/2;

        if(l==r)
            return m;
        if(verifica(valor, m)){
            l = m;
        }
        else
            r = m-1;
    }
}

ll quantidade(ll x, int i){
    return binarySearch(x,i) - i;
}

void solve(){

    ll ans = 0;

    FOR(i,T){
        ans += quantidade(v[i],i);
    }

    cout << ans << endl;

}

int main(){

	cin >> T;

	FOR(i,T){
        cin >> v[i];
    }

	FOR(i,T){
        cin >> v2[i];
    }

	FOR(i,T){
        v[i] = v[i] - v2[i];
    }

    sort(v,v+T);
    reverse(v,v+T);

    solve();

	return 0;
}