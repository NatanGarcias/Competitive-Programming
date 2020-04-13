#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld; 

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define endl "\n"
#define space " " 

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

ll T,N,L,R;

void imprimi(vector<ll> &sol, ll c, ll f){
	for(ll i=c;i<f;i++){
		cout << sol[i] << " \n"[i==f-1];
	}
}

void solve(){
	ll c = 1;

	ll qttos = R - L + 1; 

	while( (N*2)-(2*c) > 0 && L > ( (N*2)-(2*c))){
		L -= ( (N*2)-(2*c) );
		c++;
	}

	L--;

	qttos += L;
	
	vector<ll> sol;

	while(sz(sol) < qttos){
		if(c == N){
			sol.pb(1);
		}else{
			ll cont = N*2-(2*c);
			ll pos = 0;

			while(pos < cont){
				if(pos%2){
					sol.pb( ((pos+1) /2) +1 + (c-1));
				}else{
					sol.pb(c);
				}
				pos++;
			}
			c++;
		}
	}

	imprimi(sol,L,qttos);
}

int main(){

	cin >> T;

    while(T--){
		cin >> N >> L >> R;
		solve();
    }

	return 0;
}