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

ll A[MAXN];

ll f(ll x){

    ll ans = 0, cnt = 1;
    
    for(int i = 0; i < N ; i++) {
        if(A[i] > x){
            ans += A[i] - cnt;
            cnt++;
        }
    }

    return ans;
}

ll bt(){

	ll l = 0, r = N;
	
	while(l < r){

		ll m1 = l + (r-l)/3;
		ll m2 = r - (r-l)/3;

        ll f1 = f(m1);
		ll f2 = f(m2);

		//Cuidado nessa condição
		if(f1 > f2){
			r = m2 - 1;
		}
		else{
			l = m1 + 1;
		}
	}

	return f(l);
}

void solve(){
    ll ans = bt();

    cout << ans << endl;
}

int main(){

	optimize;
	
	cin >> N;
		
	for(int i = 0; i < N ; i++) cin >> A[i];

    solve();
    
	return 0;
}