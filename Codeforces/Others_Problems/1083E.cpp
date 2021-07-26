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

#define all(x) x.begin(),x.end()
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 2000100

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;

struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

ll dp[MAXN];
vector<tuple<ll,ll,ll>> ret;

bool cmp(const tuple<ll,ll,ll> & r1, const tuple<ll,ll,ll> & r2){
	ll a1 = get<0>(r1);
	ll x1 = get<1>(r1);
	ll b1 = get<2>(r1);

	ll a2 = get<0>(r2);
	ll x2 = get<1>(r2);
	ll b2 = get<2>(r2);

	if(x1 != x2) return x1 > x2;
	if(a1 != a2) return a1 < a2;
	return b1 < b2;
}

void solve(){

	LineContainer cht;

	sort(all(ret), cmp);

	ll a = get<0>(ret[0]);
	ll x = get<1>(ret[0]);
	ll b = get<2>(ret[0]);

	dp[0] = a * x - b;
	cht.add( - a , dp[0]);

	for(int i=1;i<N;i++){
		ll a = get<0>(ret[i]);
		ll x = get<1>(ret[i]);
		ll b = get<2>(ret[i]);

		dp[i] = a * x - b + max( cht.query(x) , 0ll);
		cht.add( - a, dp[i]);
	}

	ll ans = 0;

	for(int i=0;i<N;i++) ans = max(ans, dp[i]);

	cout << ans << endl;
}

int main(){

	optimize;
	
	cin >> N;

	for(ll i=0,a,x,b;i<N;i++) {
		cin >> a >> x >> b;

		ret.pb(make_tuple(a,x,b));
	}
		
	solve();
    
	return 0;
}