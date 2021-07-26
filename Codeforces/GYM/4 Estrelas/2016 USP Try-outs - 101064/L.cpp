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
pii A[MAXN];
unordered_map<ll,ll> m;
ll ansM;

ll solve(ll w){

    if(w <= 0) return -INFLL;
    if(m.find(w) != m.end()) return m[w];

    ll ans = 0;

    for(ll i=0;i<N && w < 1001;i++) if(A[i].fi == w && A[i].se > ans) ans = A[i].se;

    ll mid = w/2LL;
    ll um = (w&1LL);

    ll range = min(500LL, mid - 1LL);

    for(ll i = 0;mid && i <= range; i++) ans = max(ans, solve(mid - i) + solve(mid + um + i) );

    return m[w] = ans;
}

int main(){

	optimize;
	
    cin >> N >> M;
    
    for(int i=0;i<N;i++) cin >> A[i].fi >> A[i].se;

	cout << solve(M) << endl;
    
	return 0;
}