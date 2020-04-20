#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef unsigned long long ll;
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

ll T,X,N,M;
ll A,B,C;

ll solve2(set<ll> &sA, set<ll> &sB, set<ll> &sC){

	ll ans = INFLL;

	auto itA = sA.begin();

	FOR(i,0,sz(sA)){
		auto it = sB.upper_bound(*itA);
		auto it2 = sC.upper_bound(*itA);

		if(it != sB.end() && it2 != sC.end()){	
			auto it3 = it;
			auto it4 = it2;

			ans = min( ans , (*it3 - *itA)*(*it3 - *itA) + (*it4 - *itA)*(*it4 - *itA) + (*it3 - *it4)*(*it3 - *it4)  );
		}
		if(it != sB.begin() && it2 != sC.end()){
			auto it3 = it;
			it3--;

			auto it4 = it2;

			ans = min( ans , (*it3 - *itA)*(*it3 - *itA) + (*it4 - *itA)*(*it4 - *itA) + (*it3 - *it4)*(*it3 - *it4)  );
		}	
		if(it != sB.end() && it2 != sC.begin()){
			auto it3 = it;
			auto it4 = it2;
			it4--;

			ans = min( ans , (*it3 - *itA)*(*it3 - *itA) + (*it4 - *itA)*(*it4 - *itA) + (*it3 - *it4)*(*it3 - *it4)  );
		}	
		if(it != sB.begin() && it2 != sC.begin()){
			auto it3 = it;
			auto it4 = it2;

			it3--;
			it4--;

			ans = min( ans , (*it3 - *itA)*(*it3 - *itA) + (*it4 - *itA)*(*it4 - *itA) + (*it3 - *it4)*(*it3 - *it4)  );
		}

		itA++;
	}

	return ans;
}

void solve(set<ll> &sA, set<ll> &sB, set<ll> &sC){

	ll ans = solve2(sA,sB,sC);
	ans = min(ans, solve2(sB,sA,sC));
	ans = min(ans, solve2(sC,sA,sB));

	cout << ans << endl;
}	

int main(){

	cin >> T;

	while(T--){

		set<ll> sA;
		set<ll> sB;
		set<ll> sC;

		cin >> A >> B >> C;
	
		int a;
		
		FOR(i,0,A){
			cin >> a;
			sA.insert(a);
		}

		FOR(i,0,B){
			cin >> a;
			sB.insert(a);
		}

		FOR(i,0,C){
			cin >> a;
			sC.insert(a);
		}

		solve(sA,sB,sC);
	}

   	
	return 0;
}