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
#define MAXN 200100

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;

const ll R = 200001;
ll A[MAXN], seg[4*MAXN], lazy[4*MAXN];

void push(int p, int tl, int tr){
	if(!lazy[p]) return;

	int e = (p << 1);
	int d = (p << 1) | 1;

	seg[p] += lazy[p] * (tr - tl +1);
	
	if(tl != tr){
		lazy[e] += lazy[p];
		lazy[d] += lazy[p];
	}

	lazy[p] = 0;
}

void upd(int p, int tl, int tr, int a, int b, int x){
	push(p,tl,tr);

	if(tr < a || tl > b) return;

	if(tl >= a && tr <= b){
		lazy[p] += x;
		push(p,tl,tr);
		return;
	}

	int tm = (tl+tr)/2;
	int e = (p << 1);
	int d = (p << 1) | 1;

	upd(e,tl,tm,a,b,x);
	upd(d,tm+1,tr,a,b,x);

	seg[p] = seg[e] + seg[d];
}

ll qry(int p, int tl, int tr, int a, int b){
	push(p,tl,tr);

	if(tr < a || tl > b) return 0;

	if(tl >= a && tr <= b){
		return seg[p];
	}

	int tm = (tl+tr)/2;
	int e = (p << 1);
	int d = (p << 1) | 1;

	return qry(e,tl,tm,a,b) + qry(d,tm+1,tr,a,b);
}

ll kth(int p, int tl, int tr, ll k){
	push(p,tl,tr);

	if(seg[p] < k) return -1;
	if(tl == tr) return tl;

	int tm = (tl+tr)/2;
	int e = (p << 1);
	int d = (p << 1) | 1;

	push(e,tl,tm);
	if(seg[e] >= k){
		return kth(e,tl,tm,k);
	}
	else{
		return kth(d,tm+1,tr,k - seg[e]);
	}
}

void no(){
	cout << -1 << endl;
	exit(0);
}

void solve(){

	sort(A,A+N);
	reverse(A,A+N);

	upd(1,1,R,1,1,1);

	ll ans = INF;
	
	for(int i=0;i<N;i++){

		int p = kth(1,1,R,1);

		if(p == -1) break;

		A[i]-= 2;

		upd(1,1,R,p,p,-1);
		
		upd(1,1,R,p+2,p+A[i]/2+2,1);
		upd(1,1,R,p+2,p+(A[i]-1)/2+2,1);

		ll aux = kth(1,1,R,M);

		if(aux != -1) ans = min(ans, aux-1);
	}
	
	if(ans != INF){
		cout << ans << endl;
	}
	else{
		no();
	}
}

int main(){

	optimize;
	
	cin >> N >> M;
		
	for(int i=0;i<N;i++) cin >> A[i];

	solve();
    
	return 0;
}