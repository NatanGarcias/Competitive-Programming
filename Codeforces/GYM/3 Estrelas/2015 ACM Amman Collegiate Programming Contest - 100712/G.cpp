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
#define MAXN 200

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;

int A[MAXN], ans;

void solve(int bt, int i, int cnt){
    
    if(i == N) {
        if(cnt < M) return;

        bool ok = true;
        for(int j = 0 ; j < N; j++){
            if(bt & (1 << j) && cnt - A[j] >= M){
                ok = false;
                break;
            }
        }

        if(ok) ans = max(ans, __builtin_popcount(bt));
        return;
    }

    solve(bt, i + 1, cnt);
    solve(bt | (1 << i), i + 1, cnt + A[i]);
}

void solve(){

    ans = 0;
    solve(0, 0, 0);

    cout << ans << endl;
}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
		cin >> N >> M;

        for(int i = 0 ; i < N ; i++) cin >> A[i];

		solve();
    }

	return 0;
}