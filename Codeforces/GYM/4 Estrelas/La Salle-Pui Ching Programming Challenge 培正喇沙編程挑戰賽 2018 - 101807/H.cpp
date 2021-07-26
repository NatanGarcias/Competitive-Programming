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

ll T,N,M,K,X,Y;
int A[MAXN];

int f(int x){
    if(Y - A[x] <= 0) return INF;

    return abs(Y - A[x] - X); 
}

int bt(){
    int l = 0, r = N;

    while(l < r){
        int m1 = l + (r - l)/3;
        int m2 = r - (r - l)/3;

        int f1 = f(m1);
        int f2 = f(m2);

        if(f1 <= f2) r = m2 - 1;
        else         l = m1 + 1;
    }

    return l;
}

void solve(){

    for(int i=0;i<M;i++){
        cin >> X >> Y;

        cout << bt() << endl;
    }
}

int main(){

	optimize;
	
    cin >> N;

    for(int i=1;i<=N;i++) cin >> A[i];

    cin >> M;

	solve();
    
	return 0;
}