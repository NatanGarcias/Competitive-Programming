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

#define sz(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
ll A[MAXN];

void solve(){

	pii p;

	for(int i=0;i<N-1;i++){
		if(!i) p = pii(A[i],A[i]);
		else{
			if(p.fi- 2*K +2 > A[i] || p.se+K-1 < A[i]){
				cout << "NO\n";
				return;
			}
			else{
				p.fi = max(A[i], p.fi - K+1);
				p.se = min(A[i] + K -1, p.se + K-1);
			}
		}
	}

	if(p.fi- K+1 > A[N-1] || p.se+K-1 < A[N-1]){
		cout << "NO\n";
	}
	else{
		cout << "YES\n";
	}
}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
		cin >> N >> K;
		
		for(int i=0;i<N;i++) cin >> A[i];

		solve();
    }

	return 0;
}