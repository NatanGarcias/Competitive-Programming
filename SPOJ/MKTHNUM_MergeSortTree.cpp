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
#define MAXN 100010
#define MAXL 17
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
vector<int> v, v2;
vector<int> arv[MAXL * MAXN];

void build(int p, int tl, int tr){

	if(tl == tr) arv[p].pb(v2[tl-1]);
	else{
		int tm = (tl+tr)/2;
		int e = ( p << 1 );
		int d = ( p << 1 ) + 1;

		build(e,tl,tm);
		build(d,tm+1,tr);

		merge(arv[e].begin(), arv[e].end(), arv[d].begin(), arv[d].end(), back_inserter(arv[p]));
	}	
}

int query(int p, int tl, int tr, int a, int b, int k){

	if(a > tr || b < tl) return 0;
	if(a <= tl && tr <= b)
		return upper_bound(arv[p].begin(), arv[p].end(), k) - arv[p].begin();
	else{
		int tm = (tl+tr)/2;
		int e = (p << 1);
		int d = (p << 1) +1;

		return query(e,tl,tm,a,b,k) + query(d,tm+1,tr,a,b,k);
	}
}

int busca_binaria(int a, int b, int c){

	int l = 0, r = N-1;

	while(true){
		int m = (l+r)/2;

		if(l >= r) return m;

		if(query(1,1,N,a,b,m) >= c){
			r = m;
		}else{
			l = m + 1;
		}
	}
}

void solve(){

	build(1,1,N);

	for(int i=0;i<M;i++){
		int a,b,c;

		cin >> a >> b >> c;

		int aux = busca_binaria(a,b,c);

		cout << v[aux] << endl;
	}
}

int main(){

	optimize;
	
	cin >> N >> M;
			
	v.resize(N);
	v2.resize(N);

	for(int i=0;i<N;i++) {
		int a;
		cin >> a;
		v[i] = a;
		v2[i] = a;
	}
		
	sort(all(v));

	for(int i=0;i<N;i++) v2[i] = lower_bound(v.begin(), v.end(), v2[i]) - v.begin();

	solve();

	return 0;
}