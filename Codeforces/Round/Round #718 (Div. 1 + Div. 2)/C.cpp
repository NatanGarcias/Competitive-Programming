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
#define MAXN 550

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
int A[MAXN][MAXN];
int B[MAXN][MAXN];
int d[MAXN];

void solve(){

	for(int i=0;i<N-1;i++){

		int one = -1;

		for(int j=i;j<N;j++){
			if(B[j][j-i] == 1) {
				one = j;
				break;
			}
		}

		for(int j=i;j<N;j++){ 
			if(one > j){
				A[j+1][j-i] = A[j][j-i];
				B[j+1][j-i] = B[j][j-i] - 1;
			}
			else if(one < j){
				A[j][j-i-1] = A[j][j-i];
				B[j][j-i-1] = B[j][j-i] - 1;
			}
		}
		
	}

	for(int i=0;i<N;i++){
		for(int j=0;j<=i;j++){
			cout << A[i][j] << " \n"[j==i];
		}
	}
}

int main(){

	optimize;
	
	cin >> N;
	
	for(int i=0;i<N;i++) cin >> A[i][i], B[i][i] = A[i][i];

	solve();

	return 0;
}