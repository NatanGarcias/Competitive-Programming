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
int v[MAXN];

void solve(){
    map<ll,int> mapa;

    ll cont = 0, ans = 0;
    int ultimo = 0;
    
    mapa[0] = 1;
    FOR(i,1,N+1){ 
        cont +=v[i-1];

        ultimo = max(ultimo, mapa[cont]);

        ans += i - ultimo;
        
        mapa[cont] = i+1;
    }    

    cout << ans << endl;
}

int main(){

	cin >> N;

    FOR(i,0,N){
        cin >> v[i];
    }

    solve();

 	return 0;
}