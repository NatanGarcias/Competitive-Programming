#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
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

#define FOR(x,a,n) for(int x= (int)(a);(x) < int(n);(x)++)
#define ms(x,a) memset(x,a,sizeof(x))

#define PI 3.141592653589793238462643383279502884

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007
#define MAXN 200010

int T,N,M;
pii v[MAXN];

void solve(){
    
    int c = v[0].fi;
    int f = v[0].se;

    if(c < f) {
        cout << "NO\n";
        return;
    }
    
    FOR(i,1,N){
        if( (v[i].fi < c) || (v[i].se < f) || (v[i].fi - c) < (v[i].se - f) ){
            cout << "NO\n";
            return;
        }
        c = v[i].fi;
        f = v[i].se;
    }

    cout << "YES\n";
}

int main(){

	cin >> T;

    while(T--){
		cin >> N;
        ms(v,0);
        
        FOR(i,0,N){
            cin >> v[i].fi >> v[i].se;
        }
        
        solve();
    }
	return 0;
}