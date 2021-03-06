#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

#define fi first 
#define se second 
#define pb push_back

#define sz(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define FOR(x,a,n) for(int x= (int)(a);(x) < int(n);(x)++)
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;

pii p[MAXN];

ll area(int i , int j, int k){
    return abs( p[i].fi*p[j].se + p[j].fi*p[k].se + p[k].fi*p[i].se
        - p[i].fi*p[k].se - p[j].fi*p[i].se  - p[k].fi*p[j].se);
}

void solve(){

    ll ans = INFLL;

    FOR(i,0,N-2) ans = min(ans, area(i,i+1,i+2));

    ans = min(ans, area(N-2, N-1, 0));
    ans = min(ans, area(N-1, 0, 1));

    cout << ans << endl;
}

int main(){

	optimize;
	
	cin >> N;

    FOR(i,0,N) cin >> p[i].fi >> p[i].se;
		
	solve();
    
	return 0;
}