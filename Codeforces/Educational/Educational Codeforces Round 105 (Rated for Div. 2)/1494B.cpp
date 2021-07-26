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

ll T,N,M,K,U,R,L,D;

void solve(){

	M = 4*N;

	if(U == N && D == N) {
		if(L < 2 || R < 2){
			cout << "NO\n";
			return;
		}
	}
	else if( (U == N && D == N-1) || ((U == N-1 && D == N)) ){
		if(min(L,R) < 1 || max(L,R) < 2){
			cout << "NO\n";
			return;
		}
	}
	else if( U == N || D == N){
		if(L < 1 || R < 1){
			cout << "NO\n";
			return;
		}
	}
	else if( U == N-1 && D == N-1 ){
		if(L >= 2 || R >=2 || (L && R) );
		else{
			cout << "NO\n";
			return;
		}
	}
	else if(U == N-1 || D == N-1 ){
		if(L || R);
		else{
			cout << "NO\n";
			return;
		}
	}

	swap(L, U);
	swap(R, D);

	if(U == N && D == N) {
		if(L < 2 || R < 2){
			cout << "NO\n";
			return;
		}
	}
	else if( (U == N && D == N-1) || ((U == N-1 && D == N)) ){
		if(min(L,R) < 1 || max(L,R) < 2){
			cout << "NO\n";
			return;
		}
	}
	else if( U == N || D == N){
		if(L < 1 || R < 1){
			cout << "NO\n";
			return;
		}
	}
	else if( U == N-1 && D == N-1 ){
		if(L >= 2 || R >=2 || (L && R) );
		else{
			cout << "NO\n";
			return;
		}
	}
	else if(U == N-1 || D == N-1 ){
		if(L || R);
		else{
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";
}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
		cin >> N >> U >> R >> D >> L;
		
		solve();
    }

	return 0;
}