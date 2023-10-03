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
#define MAXN 1010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;

int A[MAXN][MAXN], B[MAXN][MAXN];
set<int> primos;
int p[MAXN];

void crivo() {

    for(int i = 2; i < MAXN; i++) {
        if(p[i]) continue;

        primos.insert(i);

        for(int j = i * i; j < MAXN; j+= i) p[j] = true;
    }
}

void print() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cout << A[i][j] << " \n"[j == M - 1];
        }
    }
}

void f() {
    
    int c = 1;

    for(int j = 0; j < M; j++) {
        for(int i = 0; i < N; i++) {
            A[i][j] = c++;
        }
    }
}

void g() {
    
    int c = 1;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            A[i][j] = c++;
        }
    }
}

void t() {

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            B[i][j] = A[i][j];
        }
    }

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            A[i][j] = B[j][i];
        }
    }
}

void h() {

    int s = 0;

    if(N > M) {
        s = true;
        swap(N, M);
    }

    int d = 2 * M;

    vector<int> l(M, 0);
    vector<int> ord;

    for(int i = 0; i < M; i++) l[i] =  (N * i) + 1;

    int e = 1;
    while(e < M) {
        ord.push_back(e);
        e += 2;
    }

    e = 0;
    while(e < M) {
        ord.push_back(e);
        e += 2;
    }

    for(int j = 0; j < M; j++) {
        int c = l[ord[j]];

        for(int i = 0; i < N; i++) {
            A[i][j] = c++;
        }
    }

    if(s) {
        t();
        swap(N, M);
    }
}

void solve() {

	cin >> N >> M;

    if(primos.find(N) == primos.end()) {
        f();
    }
    else if(primos.find(M) == primos.end()) {
        g();
    }
    else {
        h();
    }

    print();
}

int main() {

	optimize;
	
	T = 1;
	
    crivo();

	cin >> T;

    while(T--) {
		solve();
    }

	return 0;
}
