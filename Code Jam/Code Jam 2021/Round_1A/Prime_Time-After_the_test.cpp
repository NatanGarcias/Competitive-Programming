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
//Subtasks 3 - AC

ll T,N,M,K;
vector<pii> A;
const int dim = 64*500;

void solve(int caso){

    ll ans = 0;

    for(int i = 1; i < dim && i < M ;i++){
        ll mult = M - i;
        ll sum = M;
        ll acum = 1;

        bool ok = true;

        for(int j=0;j<A.size();j++){
            
            int cnt = 0;

            while(mult > 1 && mult % A[j].fi == 0){
                cnt++;
                mult /= A[j].fi;
            }

            if(cnt > A[j].se) {
                ok = false;
                break;
            }
            sum -= A[j].fi * cnt;
        }

        if(ok && mult == 1 && sum == M - i){
            ans = M - i;
            break;
        }
    }

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