#include<bits/stdc++.h>
using namespace std;

// Template 1
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld; 

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

#define pii pair<int,int>
#define fi first 
#define se second 
#define pb push_back

#define sz(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define FOR(x,a,n) for(int x= (int)(a);(x) < int(n);(x)++)
#define ms(x,a) memset(x,a,sizeof(x))

#define PI 3.141592653589793238462643383279502884
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007
#define MAXN 200010

ll T,N,M;

bool verifica(ll x){

	ll aux = 0;
	ll X = x;

	while(X>0){
		aux += X%10;
		X/=10;
	}

	if(x >= M + aux) return true;
	return false;
}

ll bb(){

	ll l = 0, r = N+10;

	while(true){
		ll m = (l+r)/2;

		if(l>= r) return m;
		if(verifica(m)){
			r = m;
		}else{
			l = m+1;
		}
	}
}

void solve(){
	ll aux = bb();

	if(aux > N){
		cout << 0 << endl;
	}else{
		cout << N - bb() +1 << endl;
	}
	
}

int main(){

    cin >> N >> M;

    solve();

	return 0;
}