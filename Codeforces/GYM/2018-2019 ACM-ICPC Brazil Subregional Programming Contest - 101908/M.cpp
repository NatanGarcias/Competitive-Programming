#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
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
#define MAXN 2009

ll T,N,M;

vector<int> B;
vector< bitset<MAXN> > A;
bitset<MAXN> x;

bool check() {
	int n = A.size(), m = MAXN;
	for(int i = 0; i < n; i++) {
		int acum = 0;
		for(int j = 0; j < m; j++) {
			if (A[i][j]) acum ^= x[j];
		}
		if (acum != B[i]) return false;
	}
	return true;
}

bool gaussxor() {
	int cnt = 0, n = A.size(), m = MAXN;
	bitset<MAXN> vis; vis.set();
	for(int j = m-1, i; j >= 0; j--) {
		for(i = cnt; i < n; i++) {
			if (A[i][j]) break;
		}
		if (i == n) continue;
		swap(A[i], A[cnt]); swap(B[i], B[cnt]);
		i = cnt++; vis[j] = 0;
		for(int k = 0; k < n; k++) {
			if (i == k || !A[k][j]) continue;
			A[k] ^= A[i]; B[k] ^= B[i];
		}
	}
	x = vis;
	for(int i = 0; i < n; i++) {
		int acum = 0;
		for(int j = 0; j < m; j++) {
			if (!A[i][j]) continue;
			if (!vis[j]) {
				vis[j] = 1;
				x[j] = acum^B[i];
			}
			acum ^= x[j];
		}
		if (acum != B[i]) return false;
	}
	return true;
}

void solve(){
	
	if(!gaussxor()) cout << "impossible" << endl;
	else{
		FOR(i,0,M){
			if(x[i]) cout << 'T';
			else cout << 'F';
		}
		cout << endl;
	}
}

void le(){

	FOR(i,0,N){
		stringstream ss;
		string s;

		char k;
		cin >> k;

		getline(cin,s);
		
		FOR(i,0,sz(s))	if(s[i]==')') s.erase(s.begin()+i);
		
		ss << s;

		int val = 1, var;

		bitset<MAXN> clausula;

		while(ss >> k){
			if(k == 'a') break;
			else if(k == 'n'){
				ss >> s;
				val ^= 1;
			}else if(k == 'o'){
				ss >> s;
			}else if(k == 'x'){
				ss >> var;
				clausula[var-1] = 1^clausula[var-1]; 
			}
		}

		A.pb(clausula);
		B.pb(val);
	}
}

int main(){

	cin >> N >> M;

	le();
	solve();

	return 0;
}