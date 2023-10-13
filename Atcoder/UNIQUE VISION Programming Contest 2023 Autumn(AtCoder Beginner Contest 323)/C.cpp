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
char A[MAXN][MAXN];
int P[MAXN], pont[MAXN], ans[MAXN];
pii m[MAXN];

void solve() {

	cin >> N >> M;

    for(int j = 0; j < M; j++) {
        cin >> P[j];
        m[j] = pii(P[j], j);
    }

    sort(m, m + M);
    reverse(m, m + M);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }

    int b = 0, id = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(A[i][j] == 'o') {
                pont[i] += P[j];
            }
        }

        pont[i] += i + 1;

        if(pont[i] > b) {
            b = pont[i];
            id = i;
        }
    }

    for(int i = 0; i < N; i++) {
        if(i == id) continue;

        for(int j = 0; j < M; j++) {
            if(pont[i] < b) {
                if(A[i][m[j].second] == 'x') {
                    pont[i] += m[j].first;
                    ans[i]++;
                }
            }
        }
    }

    for(int i = 0; i < N; i++) cout << ans[i] << "\n";
}

int main() {

	optimize;
	
	T = 1;
	
	//cin >> T;

    while(T--) {
		solve();
    }

	return 0;
}
