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
ll a[MAXN][MAXN], b[MAXN][MAXN], c[MAXN][MAXN], x[MAXN], x2[MAXN], x3[MAXN];

ll multi(ll p[MAXN][MAXN], ll q[], int i){
	
	ll aux = 0;

	for(int k=0;k<N;k++){
		aux += p[i][k] * q[k];
		aux %= mod;
	}

	return aux;
}

void multi(ll p[MAXN][MAXN], ll q[]){

	for(int i=0;i<N;i++){
		x3[i] = multi(p,q,i);
	}

	for(int i=0;i<N;i++) q[i] = x3[i];
}

bool igual(ll p[], ll q[]){

	for(int i=0;i<N;i++) if(p[i] != q[i]) return false;

	return true;
}

void solve(){

	for(int i=0;i<N;i++) x[i] = rng() % mod;
	for(int i=0;i<N;i++) x2[i] = x[i];

	multi(b,x);
	multi(a,x);

	multi(c,x2);
	
	if( igual(x,x2) ) 	cout << "YES\n";
	else 				cout << "NO\n";
}

int main(){

	optimize;
	
	cin >> N;

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> a[i][j];
		}
	}

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> b[i][j];
		}
	}

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> c[i][j];
		}
	}

	solve();
    
	return 0;
}