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
#define FOR(x,a,n) for(int x= (int)(a);(x) < int(n);(x)++)

#define INF 0x3fffffff
#define INFLL 0x3fffffffffffffff

#define mod %1000000007

#define MAXN 200010

ll T;

void imprimi(pii p){

    cout << p.fi << " " << p.se << endl;
}

void solve(){
    ll cont = 0,n = 0;

    while(n < T){
        cont++;
        n = cont*cont;
    }

    pii p;

    if(cont%2){
        p.fi = 1;
        p.se = cont;
    }else{
        p.fi = cont;
        p.se = 1;
    }

    int t = (cont*cont) - T;

    if(cont%2){
        if(t > cont-1){
            p.fi += cont-1;
            t-= cont-1;
            p.se -= t;
        }else{
            p.fi += t;
        }
    }else{
        if(t > cont-1){
            p.se += cont-1;
            t-= cont-1;
            p.fi -= t;
        }else{
            p.se += t;
        }
    }

    imprimi(p);
}

int main(){

    while(cin >> T){
        if(T==0)
            continue;
        solve();
    }

 	return 0;
}