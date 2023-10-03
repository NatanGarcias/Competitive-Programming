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

#define mod 1000000007LL
#define MAXN 1010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
ld dp[2][MAXN][MAXN];
bool ok[2][MAXN][MAXN];

ld solve(int j, int b, int p){

	if(p < 0) return 0.0;

	if(!b) return 0.0;

	if(!p) {
		if(j) return 0.0;
		else return 1.0;
	}

	if(!ok[j][b][p]){
		if(j){
			dp[j][b][p] = ( 1.0 - (b/ ((p+b)*1.0) ) ) * ( (b/ ((p+b-1)*1.0 ) )*solve(j^1,b-1,p-1) + ( ((p-1)/ ((p+b-1)*1.0) )*solve(j^1,b,p-2) ) );
		}else{
			dp[j][b][p] = (b/ ((p+b)*1.0) ) + ( (1.0 - (b/ ((p+b)*1.0) )) * solve(j^1,b,p-1) );
		}
		
		ok[j][b][p] = true;	
	}
	
	return dp[j][b][p];
}

void solve(){

	ld ans = solve(0,N,M);

	cout << fixed << setprecision(10) << ans << endl;
}

int main(){

    cin >> N >> M;

    solve();

	return 0;
}