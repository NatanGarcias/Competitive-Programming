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

ll T,N,M,K,X,Y,W,S;
vector<vector<ll>> w,s;
vector<ll> corte;

void solve(){

    corte.resize(N);

    for(int i = 0; i<X ;i++) {
        ll m = 0;
        
        for(int j=0;j<S;j++){
            m = max(m, s[j][i]);
        }
        corte.pb(m);
    }

    for(int i=0;i<W;i++){
        for(int j=0;j<X;j++){
            w[i][j] = min(Y - corte[j], w[i][j]);
        }
    }


    for(int i=0;i<W;i++){
        for(int j=0;j<X;j++){
            cout << w[i][j] << " \n"[j==X-1];
        }
    }
}

int main(){

	optimize;
	
	cin >> W >> S >> X >> Y;
    
    w.resize(W);
    s.resize(S);
    
    for(int i=0;i<W;i++) {
        for(int j=0;j<X;j++) {
            int a;
            
            cin >> a;

            w[i].pb(a);
        }
    }

    for(int i=0;i<S;i++) {
        for(int j=0;j<X;j++) {
            int a;
            
            cin >> a;

            s[i].pb(a);
        }
    }

	solve();
    
	return 0;
}