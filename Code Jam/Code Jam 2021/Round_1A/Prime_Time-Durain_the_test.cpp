#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef unsigned long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;

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
//Subtasks 1 - AC
//Subtasks 2 - AC
//Subtasks 3 - TLE

ll T,N,M,K;
vector<pii> A;

ll solve(ll x, ll prod){

    if(x < prod) return 0;
    if(x == prod) return prod;

    ll ans = 0;

    for(int i=0;i<N;i++){

        if(!A[i].se) continue;

        A[i].se--;

        ans = max(ans, solve(x - A[i].fi, prod * A[i].fi) );

        A[i].se++;
    }

    return ans;
}   

void solve(int caso){

    ll ans = solve(M, 1);

	cout << "Case #" << caso << ": " << ans << endl;
}

int main(){

	optimize;
	
	cin >> T;

    for(int i=1;i<=T;i++){

		cin >> N;
        
        A.resize(N);

        for(ll j=0;j<N;j++){
            cin >> A[j].fi >> A[j].se;

            M += A[j].fi * A[j].se;
        } 
		
		solve(i);

        M = 0;
        A.clear();
    }

	return 0;
}