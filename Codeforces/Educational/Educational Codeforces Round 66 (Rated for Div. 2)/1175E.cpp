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
#define MAXN 500010
#define MAXL 20
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
pii A[MAXN], B[MAXN];

int st[MAXN][MAXL];

void preCalc(){

	int m = 0, j = 0;

	for(int i=0;i<MAXN;i++){
		
		while(j < N && i >= A[j].fi) {
			m = max(m, A[j].se);
			j++;
		}

		m = max(m, i);
		st[i][0] = m;
	}

	for(int k=1;k<MAXL;k++){
		for(int i=0;i<MAXN;i++){
			st[i][k] = st[ st[i][k-1] ][ k-1 ];
		}
	}

}

int query(int l, int r){

	bool ok = false;
	int ans = 0;

	for(int k = MAXL-1;k>=0;k--){ 
		if(st[l][k] >= r){
			ok = true;
		}
		else{
			ans += (1 << k);
			l = st[l][k];
		}
	}

	if(ok) return ans + 1;
	else return -1;
}

void solve(){

	sort(A,A+N);

	preCalc();

	for(int i=0,l,r;i<M;i++){
		cin >> l >> r;

		cout << query(l,r) << endl;
	}
}

int main(){

	optimize;
	
	cin >> N >> M;
	
	for(int i=0;i<N;i++) cin >> A[i].fi >> A[i].se;

	solve();

	return 0;
}