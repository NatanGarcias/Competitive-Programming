#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<ld,ld> pii;

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
#define MAXN 3500

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K,X,Y;
set<pii> s;
pii v[MAXN];

void solve(){
    
    sort(v,v+N);
	
    ll ans = 0;

    FOR(i,0,N){
        FOR(j,i+1,N){
    		pii aux = pii( v[i].fi , v[i].se );
    		
    		if(v[j].fi > v[i].fi) aux.fi += abs(v[i].fi - v[j].fi)/2.0;
    		else aux.fi -= abs(v[i].fi - v[j].fi)/2.0;

    		if(v[j].se > v[i].se) aux.se += abs(v[i].se - v[j].se)/2.0;
    		else aux.se -= abs(v[i].se - v[j].se)/2.0;

    		if(s.find(aux) != s.end())	ans++;
        	
        }
    }

    cout << ans << endl;
}

int main(){

    cin >> N;

    FOR(i,0,N) {
		pii a;
		cin >> a.fi >> a.se;

		v[i] = a;
		s.insert(a);
    }

    solve();

	return 0;
}