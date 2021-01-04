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

ll T,N,M,K;
bool p[MAXN];
vector<ll> primos;

void crivo(ll lim){

	for(ll i=2;i<lim;i++){
		if(!p[i]){
			for(ll j = i*i;j<lim;j+= i){
				p[j] = true;
			}
			primos.pb(i);
		}
	}
}

void solve(){

	if(!(N&1LL)){
		cout << N/2 << " " << N/2 << endl;
	}
	else{
		vector<ll> fact;
		ll aux = 1LL;

		for(int i=0;i<primos.size() && N > 1;i++){
			if( N%primos[i] == 0){
				if(fact.size()) aux *= primos[i];
				fact.pb(primos[i]);
				N /= primos[i];
				i--;
			}
		}

		if(fact.empty()){
			cout << 1 << " " << N-1 << endl;
		}
		else{
			cout << aux*N << " " << (fact[0]-1)*aux*N << endl;
		}
	}

}

int main(){

	//optimize;
	
	cin >> T;

	crivo(MAXN-1);

    while(T--){
		cin >> N;
		
		solve();
    }

	return 0;
}