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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
vector<int> ans;

bool g(string &a){

	int m = a.size();

	for(int i=0;i<m/2;i++) if(a[i] != a[m-i-1]) return false;
	return true;
}

void f(int x){

	int n = N;

	string aux;

	while(n){
		string a;

		aux.pb(n%x + '0');
		n /= x; 
	}

	if(g(aux)) ans.pb(x);
}

void solve(){

	ans.clear();

	for(int i=2;i<=16;i++) f(i);

	M = ans.size();

	if(!M) cout << -1 << endl;
	else   for(int i=0;i<M;i++) cout << ans[i] << " \n"[i==M-1];
}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
		cin >> N;
		
		solve();
    }

	return 0;
}