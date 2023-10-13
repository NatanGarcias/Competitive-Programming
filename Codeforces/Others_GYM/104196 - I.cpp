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
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
int p1, p2, u1, u2;
int in[MAXN], out[MAXN];

void solve() {

	cin >> p1 >> u1;

	N = p1 + u1;

	for(int i = 1, u; i <= N; i++) {
		cin >> u;
		in[u] = i;
	}

	cin >> p2 >> u2;

	for(int i = 1, u; i <= N; i++) {
		cin >> u;
		out[i] = in[u];
	}	

	int ans = 0;
	int ok = true;

	// Pinned files
	for(int i = 1; i <= p2; i++) {
		// in = pinned, out = pinned
		if(out[i] <= p1) {
			// Preciso trocar de lado e voltar
			if(!ok) {
				ans += 2;
			}
			else {
				// Preciso mexer e agora todos depois de mim tb precisam	
				if(i > 1 && out[i] < out[i - 1]) {
					ok = false;
					ans += 2;
				}
				// Não preciso mexer -> ans += 0
			}
		}
		// in = unpinned, out = pinned
		else {
			ans++;
		}

	}

	ok = true;
	// Unpinned files
	for(int i = N; i > p2; i--) {
		// in = unpinned, out = unpinned
		if(out[i] > p1) {
			// Preciso trocar de lado e voltar
			if(!ok) {
				ans += 2;
			}
			else {
				// Preciso mexer e agora todos depois de mim tb precisam
				if(i < N && out[i] > out[i + 1]) {
					ok = false;
					ans += 2;
				}
				// Não preciso mexer -> ans += 0
			}
		}
		// in = pinned, out = unpinned
		else {
			ans++;
		}
	}

	cout << ans << endl;
}

int main() {

	optimize;
	
	T = 1;
	
	//cin >> T;

    while(T--) {
		solve();
    }

	return 0;
}
