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

ll ans[MAXN];
ll A[MAXN], B[MAXN], C[MAXN];

void solve() {

	cin >> N >> M;

    for(int i = 0; i < M; i++) cin >> A[i] >> B[i] >> C[i];

    priority_queue<ll, vector<ll>, greater<ll>> pq;
    priority_queue<pii, vector<pii>, greater<pii>> wait;

    for(int i = 0; i < N; i++) pq.push(i);

    for(int i = 0; i < M; i++) {
        ll t = A[i];

        while(wait.size() && wait.top().first <= t) {
            pq.push(wait.top().second);
            wait.pop();
        }

        if(pq.size()) {
            int c = pq.top();
            pq.pop();

            ans[c] += B[i];

            wait.push(make_pair(t + C[i], c));
        }
    }

    for(int i = 0; i < N; i++) cout << ans[i] << endl;
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
