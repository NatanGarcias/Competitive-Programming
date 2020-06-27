#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld; 

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

#define pii pair<ld,ll>
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
#define MAXN 100010

ll T,N,M,K;

ld seg[4*MAXN];
pii v[MAXN];

void update(int p, int tl, int tr, int a, int b, ld val){

	if(b < tl || a > tr) return;
	if(tl >= a && tr <= b){
		seg[p] = val;
		return;
	}
	else{
		int tm = (tl+tr)/2; 
		int e = (p << 1);
		int d = (p << 1) +1;

		update(e,tl,tm,a,b,val);
		update(d,tm+1,tr,a,b,val);

		seg[p] = max(seg[e],seg[d]);
	}
}

ll query(int p, int tl, int tr, int a, int b){

	if(b < tl || a > tr) return -1;
	if(tl >= a && tr <= b){
		return seg[p];
	}
	else{
		int tm = (tl+tr)/2; 
		int e = (p << 1);
		int d = (p << 1) +1;

		return max(query(e,tl,tm,a,b),query(d,tm+1,tr,a,b));
	}
}

void solve(){

	sort(v,v+N);

	FOR(i,0,N){

		ld vol = v[i].fi;
		
		int id = -v[i].se;

		ld q = query(1,1,N,1,id);

		update(1,1,N,id,id,vol+q);
	}

	cout << fixed << setprecision(10) << query(1,1,N,1,N)*PI << endl;
}

int main(){

	cin >> N;

	FOR(i,0,N){
		ld r,h;

		cin >> r >> h;

		v[i].fi = (r*r*h);
		v[i].se = -(i+1);
	}

	solve();

	return 0;
}