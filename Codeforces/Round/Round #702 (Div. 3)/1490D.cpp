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
int A[MAXN], level[MAXN];

void preenche(int l, int r, int d){

    int p = l;

    for(int i=l+1;i<=r;i++){
        if(A[i] > A[p]) p = i;
    }

    level[p] = d;

    if(l != p) preenche(l  , p-1,d + 1);
    if(r != p) preenche(p+1, r  ,d + 1);
}

void solve(){

    preenche(0,N-1,0);

    cout << level[0];
    for(int i=1;i<N;i++) cout << " " << level[i];
    cout << endl;
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