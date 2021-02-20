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
#define MAXN 200010
#define MAXM 60

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

int T,N,M,K;
ll seg[4 * MAXN], lazy[4 * MAXN];
ll dp[MAXM][MAXN], pre[MAXM][MAXN], A[MAXM][MAXN];

void build(int p, int tl, int tr, int j){
	lazy[p] = 0;
	
	if(tl == tr){
		seg[p] = dp[j][tl]; 
		return;
	}

	int tm = (tl+tr)/2;
	int e = (p << 1);
	int d = (p << 1) | 1;

	build(e,tl,tm,j);
	build(d,tm+1,tr,j);

	seg[p] = max(seg[e], seg[d]);
}

void push(int p, int tl, int tr){

	if(!lazy[p]) return;

	int e = (p << 1);
	int d = (p << 1) | 1;

	seg[p] += lazy[p];
	
	if(tl != tr){
		lazy[e] += lazy[p];
		lazy[d] += lazy[p];
	}

	lazy[p] = 0;
}

ll query(int p, int tl, int tr, int a, int b){

	push(p, tl, tr);

	if(a > tr || b < tl) return -INF;

	if(a <= tl && b >= tr) return seg[p];

	int tm = (tl+tr)/2;
	int e = (p << 1);
	int d = (p << 1) | 1;

	return max( query(e,tl,tm,a,b) , query(d,tm+1,tr,a,b) );
}	

void update(int p, int tl, int tr, int a, int b, int z){

	push(p, tl, tr);

	if(a > tr || b < tl) return;

	if(a <= tl && b >= tr) {
		lazy[p] += z;
		push(p, tl, tr);
		return;
	}

	int tm = (tl+tr)/2;
	int e = (p << 1);
	int d = (p << 1) | 1;

	update(e,tl,tm,a,b,z);
	update(d,tm+1,tr,a,b,z);

	seg[p] = max(seg[e], seg[d]);
}	

void solve(){
	for(int i=0;i<=T;i++){
		dp[0][i+1] = pre[0][i+K] - pre[0][i] + pre[1][i+K] - pre[1][i];
	}

	for(int i=1;i<N;i++){
		build(1,1,T,i-1);

		for(int j=1;j<=K;j++) 	update(1,1,T, 1, min(j, T), -A[i][j]);

		for(int j=1;j<=T;j++){

			dp[i][j] = query(1,1,T,1,T) + pre[i][j+K-1] - pre[i][j-1] + pre[i+1][j+K-1] - pre[i+1][j-1];

			update(1,1,T, max(1,j-K+1) , j , A[i][j]);
			
			if(j+K <= M)	update(1,1,T, j+1 , j+K , -A[i][j+K]);
		}
	}

	ll ans = 0;
	
	for(int j=1;j<=T;j++) 	ans = max(ans, dp[N-1][j]);

	cout << ans << endl;
}

int main(){

	optimize;
	
	cin >> N >> M >> K;
	
	T = M-K+1;

	for(int i=0;i<N;i++){
		for(int j=1;j<=M;j++){
			cin >> A[i][j];
			pre[i][j] = pre[i][j-1] + A[i][j];
		}
	}

	solve();

	return 0;
}