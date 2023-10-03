#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef unsigned long long ll;
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

// #define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
int A[MAXN];
ld B[MAXN], C[MAXN], D[MAXN];
pii ans;

bool verifica(ld x){

    B[0] = C[0] = 0.0;

	for(int i=0;i<N;i++) B[i+1] = B[i] + A[i] - x;
    for(int i=0;i<N;i++) C[i+1] = min(C[i], B[i+1]);
    for(int i=0;i<N;i++) D[i+1] = C[i+1] < C[i] ? i+1 : D[i];
    
    for(int i = 0;i<=N-M;i++) {

        if(B[i+M] >= C[i]) {
            ans = pii(D[i] + 1, i+M);
            
            return true;
        }
    }

	return false;
}

ld bb(){

    ld l = 0.0, r = 100.0;
    
    for(int i=0;i<100;i++){
        ld m = (l+r)/2.0;

        if(verifica(m))
            l = m;
        else
            r = m;
    }

	return l;
}

void solve(){
    
    ans = pii(1,N);

    bb();

    cout << ans.fi << " " << ans.se << endl;

}

int main(){

	optimize;
	
	cin >> N >> M;

	for(int i=0;i<N;i++) cin >> A[i];
		
	solve();
    
	return 0;
}