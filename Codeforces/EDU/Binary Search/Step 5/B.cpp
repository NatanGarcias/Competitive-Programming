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

#define INF 0x7f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;

bool verifica(ll x){

    ll ans = 0;

    for(int i=1;i<=N;i++){
        ll aux = x / i;

        if(aux >= N) aux = N;

        ans += aux;
    }
    
    return ans >= M;
}

ll bb(){
    ll l = 0, r = N*N;

    while(l < r){
        ll m = (l+r)/2LL;

        if(verifica(m)) r = m;
        else            l = m + 1LL;
    }

    return l;
}

void solve(){
    cout << bb() << endl;
}

int main(){

	optimize;
	
	cin >> N >> M;

	solve();
    
	return 0;
}