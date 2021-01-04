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

#define sz(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
ll A[MAXN], B[2*MAXN];

void solve(){

    for(int i=1;i<N;i+=2){
        B[i/2 + N/2 + 1] = A[i];
    }
    
    for(int i=0;i<N;i+=2){
        B[i/2] = A[i];
    }

    for(int i=0;i<N;i++){
        B[i+N] = B[i];
    }

    ll ans = 0;
    ll aux = 0;

    for(int i=0;i<N/2 + 1;i++){
        aux += B[i];
        ans = max(ans,aux);
    }

    for(int i=N/2 + 1;i<N/2 + 1 + N;i++){
        aux -= B[i - N/2 - 1];
        aux += B[i];
        ans = max(ans,aux);
    }

    cout << ans << endl;
}

int main(){

	optimize;
	
    cin >> N;

    for(int i=0;i<N;i++) cin >> A[i];

	solve();
    
	return 0;
}