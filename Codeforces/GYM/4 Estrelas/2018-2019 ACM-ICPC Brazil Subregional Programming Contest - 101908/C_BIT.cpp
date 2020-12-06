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
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K,X,Y,H,V;

vector<pii> h,v;
ll p, p2;
ll numsH[MAXN], numsV[MAXN], compH[MAXN], compV[MAXN];

ll bit[2][MAXN];

void update(ll i, ll x, ll z){
	for(;x<MAXN;x+= x&-x) bit[i][x] += z;
}

ll query(ll i, ll x){
	ll sum = 0;

	for(;x>0;x-= x&-x) sum += bit[i][x];

	return sum;
}

void solve(){

	sort(numsH, numsH+p);
	sort(numsV, numsV+p2);
	
	ll n = unique(numsH,numsH+p) - numsH;
	ll n2 = unique(numsV,numsV+p2) - numsV;

	sort(all(h));
	sort(all(v));

	reverse(all(h));
	reverse(all(v));

	for(int i=0;i<H;i++){
		compH[2*i] = lower_bound(numsH, numsH + n, h[i].fi) - numsH + 1;
		compH[2*i +1] = lower_bound(numsH, numsH + n, h[i].se) - numsH + 1;
	}

	for(int i=0;i<V;i++){
		compV[2*i] = lower_bound(numsV, numsV + n2, v[i].fi) - numsV + 1;
		compV[2*i +1] = lower_bound(numsV, numsV + n2, v[i].se) - numsV + 1;
	}

	ll ans = 0;

	for(int i=0;i<H;i++){
		ll aux = query(0, compH[2*i+1]);

		ans += aux;

		update(0,compH[2*i+1],1);
	}	

	for(int i=0;i<V;i++){
		ll aux = query(1, compV[2*i+1]);
	
		ans += aux;

		update(1,compV[2*i+1],1);
	}

	ans += (V+1)*(H+1);

	cout << ans << endl;
}

int main(){

	optimize;

	cin >> X >> Y >> H >> V;

	h.reserve(H);
	v.reserve(V);

	for(ll i=0;i<H;i++){
		ll a,b;
		cin >> a >> b;

		h.pb(pii(a,b));

		numsH[p++] = a;
		numsH[p++] = b;
	}

	for(ll i=0;i<V;i++){
		ll a,b;
		cin >> a >> b;

		v.pb(pii(a,b));

		numsV[p2++] = a;
		numsV[p2++] = b;
	}
	
	solve();

	return 0;
}