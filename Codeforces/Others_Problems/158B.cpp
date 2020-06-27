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

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
int v[MAXN];

void solve(){

	ll sum  = 0;
	vector<int> r(4,0);

	FOR(i,0,N) {
		if(v[i] == 1) r[0]++;
		if(v[i] == 2) r[1]++;
		if(v[i] == 3) r[2]++;
		if(v[i] == 4) r[3]++;
	}

	sum += r[3];
	sum += r[2];

	r[0] = max(0,r[0]-r[2]);

	sum += ((r[1]+1)/2);

	if(r[1]&1) r[0]-=2;

	r[0] = max(0,r[0]);

	sum += (r[0]+3)/4;

	cout << sum << endl;
}

int main(){

	cin >> N;

	FOR(i,0,N) cin >> v[i];

	solve();

	return 0;
}