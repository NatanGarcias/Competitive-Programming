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
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K,L,R;

void solve(){

	ll menorD = L-R, maiorD = R-L;

	for(ll i = L;i<=R;i++){
		ll aux = max(M/i,1LL);
		ll aux2 = aux+1;

		ll aux3 = aux * i;
		ll aux4 = aux2 * i;

		ll D, B, C;
		if(M - aux3 >= menorD && M - aux3 <= maiorD){
			D = M - aux3;

			if(D < 0){
				B = L;
				C = L - D;
			}
			else{
				B = R;
				C = R - D;
			}

			cout << i << " " << B << " " << C << endl;
			return;
		}

		if(M - aux4 >= menorD && M - aux4 <= maiorD){
			D = M - aux4;

			if(D < 0){
				B = L;
				C = L - D;
			}
			else{
				B = R;
				C = R - D;
			}

			cout << i << " " << B << " " << C << endl;
			return;
		}
	}
}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
		cin >> L >> R >> M;
		
		solve();
    }

	return 0;
}