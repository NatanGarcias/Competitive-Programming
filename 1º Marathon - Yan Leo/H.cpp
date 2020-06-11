//Tle, DP fica N^2 *M
//Precisa utilizar DP com D&C para reduzir para NM logN

#include<bits/stdc++.h>
using namespace std;

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
#define MAXN 20010
#define MAXM 110

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
int v[MAXN];
int segMin[4*MAXN], segMax[4*MAXN];
ll dp[MAXM][MAXN];

void buildMin(int p, int tl, int tr){

	if(tl == tr) segMin[p] = v[tl-1];
	else{
		int tm = (tl+tr)/2;
		int e = (p << 1);
		int d = (p << 1) + 1;

		buildMin(e,tl,tm);
		buildMin(d,tm+1,tr);

		segMin[p] = min(segMin[d],segMin[e]);
	}
}

int queryMin(int p, int tl, int tr, int a, int b){

	if(a > tr || b < tl) return INF;
	else if(tl >= a && tr <= b){
		return segMin[p];
	}else{
		int tm = (tl+tr)/2;
		int e = (p << 1);
		int d = (p << 1) + 1;

		return min( queryMin(e,tl,tm,a,b) , queryMin(d,tm+1,tr,a,b) );
	}
}

void buildMax(int p, int tl, int tr){

	if(tl == tr) segMax[p] = v[tl-1];
	else{
		int tm = (tl+tr)/2;
		int e = (p << 1);
		int d = (p << 1) + 1;

		buildMax(e,tl,tm);
		buildMax(d,tm+1,tr);

		segMax[p] = max(segMax[d],segMax[e]);
	}
}

int queryMax(int p, int tl, int tr, int a, int b){

	if(a > tr || b < tl) return -INF;
	else if(tl >= a && tr <= b){
		return segMax[p];
	}else{
		int tm = (tl+tr)/2;
		int e = (p << 1);
		int d = (p << 1) + 1;

		return max( queryMax(e,tl,tm,a,b) , queryMax(d,tm+1,tr,a,b) );
	}
}

ll solve(int i, int j){
	
	if(!i) return 0;
	if(j == N) return -INFLL;

	if(dp[i][j] == -1){
		ll ans = -INFLL;
		for(int k = j;k<N;k++){
			ll aux = queryMax(1,1,N,j+1,k+1) - queryMin(1,1,N,j+1,k+1);
			ans = max(ans, solve(i-1,k+1) + aux);
		}

		dp[i][j] = ans;
	}
	return dp[i][j];
}
void solve(){

	buildMin(1,1,N);
	buildMax(1,1,N);

	ms(dp,-1);

	ll ans = solve(M,0);

	cout << max(ans,0LL) << endl;
}

int main(){

	optimize;

	cin >> N >> M;

	FOR(i,0,N) cin >> v[i];

	solve();

	return 0;
}