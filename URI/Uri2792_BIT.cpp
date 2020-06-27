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

#define PI 3.141592653589793238462643383279502884
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007
#define MAXN 500010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;

int v[MAXN];
int bit[MAXN];

void update(int x, int valor){
	for(;x<=N;x+= x&-x) bit[x] += valor;
}

int query(int x){
	int sum = 0;
	
	for(;x>0;x-= x&-x){
		sum += bit[x];
	}

	return sum;
}

int queryI(int p, int q){
	return query(q) - query(p);
}

void solve(){
	FOR(i,1,N+1) update(i,1);

	FOR(i,0,N){
		cout << queryI(0,v[i]) << " \n"[i==N-1];
		update(v[i],-1);
	}
}

int main(){
	
	cin >> N;

	FOR(i,0,N) cin >> v[i];
		
	solve();

	return 0;
}