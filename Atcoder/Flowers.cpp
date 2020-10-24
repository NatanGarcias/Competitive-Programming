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
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;

ll v[MAXN], v2[MAXN], seg[4*MAXN];

ll query(int p, int tl, int tr, int a, int b){

	if(a > tr || b < tl) return 0;
	
	if(a <= tl && b >= tr) return seg[p];

	int tm = (tl+tr)/2;
	int e = (p << 1);
	int d = (p << 1) +1;

	return max(query(e,tl,tm,a,b), query(d,tm+1,tr,a,b));
}

void update(int p, int tl, int tr, int a, int b, ll z){

	if(a > tr || b < tl) return;
	
	if(a <= tl && b >= tr) {
		seg[p] = z;
		return;
	}

	int tm = (tl+tr)/2;
	int e = (p << 1);
	int d = (p << 1) +1;

	update(e,tl,tm,a,b,z);
	update(d,tm+1,tr,a,b,z);

	seg[p] = max(seg[e], seg[d]);

	return;
}

void solve(){

	ll ans = 0;

	update(1,1,N,v[0],v[0], v2[0]);
		
	for(int i=1;i<N;i++){
		ans = query(1,1,N,1,v[i]);
		update(1,1,N,v[i],v[i], ans + v2[i]);
	}

	ans = query(1,1,N,1,N);

	cout << ans << endl;
}

int main(){

	optimize;
	
	cin >> N;
	
	for(int i=0;i<N;i++) cin >> v[i];
	for(int i=0;i<N;i++) cin >> v2[i];

	solve();
    
	return 0;
}