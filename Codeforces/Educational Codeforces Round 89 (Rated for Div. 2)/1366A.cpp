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

#define mod 1000000007
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;

void solve(){
	ll ans = 0;

	if(N < M) swap(N,M);

	ll aux = N - M;
	
	ans = min (min(N/2,M) , aux);
	
	N -= 2*ans;
	M -= ans;

	aux = N/3;
	ll aux2 = M/3;

	N -= min(aux, aux2) *3;
	M -= min(aux, aux2) *3;

	ans += min(aux, aux2) *2;
	
	while(N >= 2 && M >= 2){	
		if( N > 2){
			N -=2;
			M-=1;
			ans++;
		}else{
			N -=1;
			M -=2;
			ans++;
		}
	}
	cout << ans << endl;
}

int main(){

	cin >> T;

    while(T--){
		cin >> N >> M;
		
		solve();
    }

	return 0;
}