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
#define MAXM 1000010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;

template<typename T>
T modMul(T a, T b, T m) {
	T x = 0, y = a % m;
	while (b > 0) {
		if (b % 2 == 1) x = (x + y) % m;
		y = (y * 2) % m;
		b /= 2;
	}
	return x % m;
}

template<typename T>
T modExp(T a, T b, T m) {
	if (b == 0) return (T)1;
	T c = modExp(a, b / 2, m);
	c = (c * c) % m;
	if (b % 2 != 0) c = (c*a) % m;
	return c;
}

bool miller(long long n) {
	const int pn = 9;
	const int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
	for (int i = 0; i < pn; i++)
		if (n % p[i] == 0) return n == p[i];
	if (n < p[pn - 1]) return false;
	long long s = 0, t = n - 1;
	while (~t & 1) t >>= 1, ++s;
	for (int i = 0; i < pn; ++i) {
		long long pt = modExp((long long)p[i], t, n);
		if (pt == 1) continue;
		bool ok = false;
		for (int j = 0; j < s && !ok; j++) {
			if (pt == n - 1) ok = true;
			pt = modMul(pt, pt, n);
		}
		if (!ok) return false;
	}
	return true;
}


void solve(){

    if(N == 1){
        cout << "FastestFinger" << endl;
    }else if(N&1 || N == 2){
        cout << "Ashishgup" << endl;
    }else if( miller(N/2) || (N - (N&-N) == 0)){
        cout << "FastestFinger" << endl;
    }else{
        cout << "Ashishgup" << endl;
    }
}

int main(){

	cin >> T;

    while(T--){
		cin >> N;
		
		solve();
    }

	return 0;
}