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
#define MAXN 7070

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
int A[MAXN];

void f(int l, int r) {
    while(l < r) swap(A[l++], A[r--]);
}

void g() {
    vector<tuple<int,int,int,int>> m1, m2, m3;

    for(int i = 0 ; i < N; i++) {
        for(int j = i; j < N; j++) {
            if(A[i] == A[j])        m2.emplace_back(-i, A[j], -j, -A[i]);
            else if(A[i] < A[j])    m3.emplace_back(-i, A[j], -j, -A[i]);
            else                    m1.emplace_back( i, A[j],  j, -A[i]);
        }
    }

    M--;
    if(M < m1.size()) {
        sort(m1.begin(), m1.end());
        int l = get<0> (m1[M]);
        int r = get<2> (m1[M]);
        f(l, r);
    }
    else if(M < m1.size() + m2.size()) {
        return;
    }
    else {
        sort(m3.begin(), m3.end());
        M -= m1.size() + m2.size();
        int l = -get<0> (m3[M]);
        int r = -get<2> (m3[M]);
        f(l, r);
    }
}

void solve() {

	cin >> N >> M;
    
    for(int i = 0; i < N; i++) cin >> A[i];

    g();    

    for(int i = 0; i < N; i++) cout << A[i] << " \n"[i == N - 1];
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
    