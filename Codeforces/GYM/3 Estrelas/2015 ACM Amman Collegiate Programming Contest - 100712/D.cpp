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
#define MAXN 100100

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;

string s;

int dp[MAXN], seg[4 * MAXN];

int init(){
	ms(dp,0);
	ms(seg, 0x3f);
}

int query(int p, int tl, int tr, int a, int b){
	
	if(tr < a || b < tl) return INF;

	if(tl >= a && tr <= b){
		return seg[p];
	}

	int e = (p << 1);
	int d = (p << 1) | 1;
	int tm = (tl+tr)/2;

	return min(query(e,tl,tm,a,b), query(d,tm+1,tr,a,b));
}

void update(int p, int tl, int tr, int a, int b, int x){
	
	if(tr < a || b < tl){
		return;
	}
	if(tl == tr){
		seg[p] = x;
		return;
	}

	int e = (p << 1);
	int d = (p << 1) | 1;
	int tm = (tl+tr)/2;

	update(e,tl,tm,a,b,x);
	update(d,tm+1,tr,a,b,x);

	seg[p] = min(seg[e], seg[d]);
}

void upd(int l, int x){
	update(1, 1, N + 1, l + 1, l + 1, x);
}

int qry(int l, int r){
	return query(1, 1, N + 1, l + 1, r + 1);
}

void solve(){   

	init();

	deque<int> trocas;

	upd(N, 0);

	dp[N - 1] = 1;
	upd(N - 1, dp[N - 1]);
			
	for(int i = N - 2; i >= 0 ; i--){
		if(s[i] == s[i+1]) trocas.push_back(i);

		if(!trocas.empty() && trocas.front() >= i + K) trocas.pop_front();

		dp[i] = INF;

		if(!trocas.empty()) {
			int u = trocas.back();
			dp[i] = 1 + qry(u + 2, min(N, i + K));
		}
		
		dp[i] = min(dp[i], 1 + dp[i + 1]);
		
		upd(i, dp[i]);
	}

	cout << dp[0] - 1 << endl;
}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
		cin >> N >> K >> s;
		
		solve();
    }

	return 0;
}