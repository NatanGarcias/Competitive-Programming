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
#define MAXN 500010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
vector<ll> A;

void solve(){

    ll ans = 0;

    reverse(all(A));

    while(A.size() > 1){
        ll a = A.back();
        A.pop_back();
        
        ll b = A.back();
        A.pop_back();

        A.pb(b - a);
    }

    ans = A.back();

    cin >> M;

    for(ll i=0, u, v, w; i < M ; i++){
        cin >> u >> v >> w;

        if((v - u) & 1LL); 
        else if( (u & 1) == (N & 1))   ans += w;
        else                           ans -= w;

        cout << ans << endl;
    }
}

int main(){

	optimize;
	
	cin >> N;
	
    for(ll i = 0, u; i < N; i++){
        cin >> u;
        A.pb(u);
    }

	solve();

	return 0;
}