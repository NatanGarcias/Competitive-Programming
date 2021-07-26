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
double A[MAXN];

double area(double a, double b, double c){

    double p = a + b + c;
    p/= 2.0;

    double ar = sqrt( p * (p - a) * (p - b) * (p - c) );

    return ar;
}

double calc(int i, int j){

    double ans = 1e11;

    double maxL = A[i] + A[j];
    double minL = max(A[i], A[j]) - min(A[i], A[j]);

    int p = upper_bound(A, A+N, minL) - A;
    int p2 = (upper_bound(A, A+N, maxL) - A) - 1;

    if(p == i) p++;
    if(p == j) p++;

    if(p2 == i) p2--;
    if(p2 == j) p2--;

    if(p > p2) return ans;

    ans = min(ans, area(A[i], A[j], A[p]));
    ans = min(ans, area(A[i], A[j], A[p2]));

    return ans;
}

void solve(){

    sort(A,A+N);

    double ans = 1e10;

    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            ans = min(ans , calc(i, j));     
        }
    }

    if(ans == 1e10) cout << -1 << endl;
    else cout << fixed << setprecision(10) << ans << endl;

}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
		cin >> N;

        for(int i=0;i<N;i++) cin >> A[i];
		
		solve();
    }

	return 0;
}