#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
map<int,int> mapa;
map<int,int> mapa3;
map<pii,int> mapa2;
set<pii> s;

void solve(){

    ll ans = 0;
    for(auto i: s){
        ll aux = mapa2[ pii(i.fi,i.se) ];

        ll cont = (aux*(aux-1))/2;

        mapa[i.fi] -= aux;
        mapa3[i.se] -= aux;

        ll cont2 =  mapa[i.fi];
        ll cont3 =  mapa3[i.se];

        ans += cont + aux*cont2 + aux*cont3;
    }

    cout << ans << endl;

}

int main(){

	cin >> N;

	FOR(i,0,N){
        int a,b;

        cin >> a >> b;

        mapa[a]++;
        mapa3[b]++;
        mapa2[pii(a,b)]++;
        s.insert(pii(a,b));
    }

	solve();

	return 0;
}