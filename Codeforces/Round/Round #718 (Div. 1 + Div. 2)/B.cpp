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
#define MAXN 110

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
int A[MAXN][MAXN];
int B[MAXN][MAXN];

void solve(){

	vector<int> ptr(N,0);
	vector<int> ptr2(N,M-1);

	for(int i=0;i<N;i++) sort(A[i],A[i]+M);

	for(int i=0;i<M;i++){

		int m = INF, p = -1;

		for(int j=0;j<N;j++){
			if(A[j][ ptr[j] ] < m){
				p = j;
				m = A[j][ ptr[j] ];
			}
		}

		for(int j=0;j<N;j++){
			if(j == p){
				B[j][i] = A[j][ptr[j]];
				ptr[j]++;
			}
			else{
				B[j][i] = A[j][ptr2[j]];
				ptr2[j]--;
			}
		}

	}
	
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) {
			cout << B[i][j] << " \n"[j==M-1];
		}
	}
	
}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
		cin >> N >> M;

		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				cin >> A[i][j];
			}
		}	

		solve();
    }

	return 0;
}