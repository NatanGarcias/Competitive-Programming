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
#define MAXN 100010

ll X,Y,H,V;
ll inv;
vector<pii> hor;
vector<pii> ver;

ll aux[MAXN];
ll hor2[MAXN];
ll ver2[MAXN];

void mergesort(ll arr[], ll l, ll r) {
	
	if (l == r) return;
	
	int m = (l + r) / 2;
	
	mergesort(arr, l, m);
	mergesort(arr, m+1, r);
	
	int i = l, j = m + 1, k = l;
	
	while(i <= m && j <= r) {
		if (arr[i] > arr[j]) {
			aux[k++] = arr[j++];
			inv += j - k;
		}
		else aux[k++] = arr[i++];
	}
	while(i <= m) aux[k++] = arr[i++];
	for(i = l; i < k; i++) arr[i] = aux[i];

}

void solve(){

	sort(all(hor));
	sort(all(ver));

	FOR(i,0,H)	hor2[i] = hor[i].se;
	FOR(i,0,V)	ver2[i] = ver[i].se;

	mergesort(hor2,0,H-1);
	mergesort(ver2,0,V-1);

	cout << (H+1)*(V+1) + inv << endl;

}

int main(){

	optimize;
	
	cin >> X >> Y >> H >> V;

	hor.resize(H);
	ver.resize(V);
	
	FOR(i,0,H)	cin >> hor[i].fi >> hor[i].se;
	FOR(i,0,V)	cin >> ver[i].fi >> ver[i].se;

	solve();

	return 0;
}