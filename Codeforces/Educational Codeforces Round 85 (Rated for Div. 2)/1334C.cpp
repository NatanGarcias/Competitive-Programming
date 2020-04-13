#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld; 

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define endl "\n"
#define space " " 

#define pii pair<ll,ll>
#define fi first 
#define se second 

#define pb push_back
#define sz(x) (ll)(x.size())
#define all(x) x.begin(),x.end()

#define FOR(x,a,n) for(int x= (int)(a);(x) < int(n);(x)++)
#define ms(x,a) memset(x,a,sizeof(x))

#define PI 3.141592653589793238462643383279502884

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007
#define MAXN 300010

int T,N,M;
pii v[MAXN];
ll menor,pos;

void solve(){
    
    ll ans = 0;

    FOR(i,0,N){
        if(v[i].se < v[i+1].fi){
            ans+= (v[i+1].fi - v[i].se);

            if(v[i].se < menor){
                menor = v[i].se;
            }
        }
    }

    cout << ans+menor << endl;
}

int main(){
    
    optimize;
    
	cin >> T;

    while(T--){
		cin >> N;
        
        menor = INFLL;
        pos = -1;
        
        FOR(i,0,N){
            cin >> v[i].fi >> v[i].se;
            if(v[i].fi < menor){
                menor = v[i].fi;
                pos = i;
            }
        }

        v[N] = v[0];

        solve();
    }
	return 0;
}