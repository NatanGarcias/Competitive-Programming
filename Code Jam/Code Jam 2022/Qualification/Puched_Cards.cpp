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
#define MAXN 100

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;

char A[MAXN][MAXN];

void solve(int caso) {

	cin >> N >> M;
	
    char v[4] = {'.', '+', '-', '|'};

    for(int i = 0; i < N * 2 + 1; i++) {
        for(int j = 0; j < M * 2 + 1; j++) {
            if(i < 2 && j < 2) {
                A[i][j] = v[0];
            }
            else if( (i&1) == 0 ) {
                if( (j&1) == 0) {
                    A[i][j] = v[1];
                }
                else{
                    A[i][j] = v[2];
                }
            }
            else {
                if( (j&1) == 0) {
                    A[i][j] = v[3];
                }
                else{
                    A[i][j] = v[0];
                }
            }
        }
    }

    cout << "Case #" << caso << ": " << "\n";
    
    for(int i = 0; i < N * 2 + 1; i++) {
        for(int j = 0; j < M * 2 + 1; j++) {
            cout << A[i][j];
        }
        cout << endl;
    }
}

int main() {

	optimize;
	
	cin >> T;

    for(int i = 1; i <= T; i++) {
        solve(i);
    }

	return 0;
}