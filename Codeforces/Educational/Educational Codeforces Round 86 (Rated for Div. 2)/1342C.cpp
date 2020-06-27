#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld; 

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

#define pii pair<int,int>
#define fi first 
#define se second 
#define pb push_back

#define sz(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define FOR(x,a,n) for(ll x= (ll)(a);(x) < ll(n);(x)++)
#define ms(x,a) memset(x,a,sizeof(x))

#define PI 3.141592653589793238462643383279502884
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007
#define MAXN 200010

ll T,A,B,Q,L,R;

ll MDC(ll a, ll b){
	return b ? MDC(b,a%b) : a;
}

ll MMC(ll a, ll b){
	return a*( b / MDC(a,b));
}

int ahh = 0;

void solve(){

    vector<ll> ans;

    ll aux = MMC(A,B);
    ll bom = aux - max(A,B);
    ll ruim = max(A,B);

    ll ant = 0, resp = 0, cont = 0;
    
    FOR(i,0,Q){
    
        cin >> L >> R;

        resp = 0;

        cont = (L+aux-1)/aux;
        
        if(R < aux*cont){
            
            L -= aux*(cont-1);
            R -= aux*(cont-1);

            if(L > ruim)   resp += R-L+1;
            else if(R > ruim-1)  resp += R - ruim +1;
        
        }else{
            
            ll temp = max(L,aux*(cont-1) + ruim);
            resp += aux*cont -temp;

            ant = cont;
            cont = R/aux;
            
            if(cont > ant) resp+= bom*(cont-ant);
            
            if(R+1 > aux*cont + ruim )  resp += R - aux*cont - ruim +1;
        }

        ans.pb(resp);
    }

    FOR(i,0,sz(ans)){
        cout << ans[i] << " \n"[i==sz(ans)-1];
    }
}

int main(){

    optimize;

	cin >> T;

    while(T--){
        cin >> A >> B >> Q; 

    	solve();
    }

	return 0;
}