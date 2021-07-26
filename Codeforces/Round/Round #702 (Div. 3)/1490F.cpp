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
vector<int> A,B, comp;

void solve(){

    vector<int> apar(N+1,0), nums(N+1,0);

    for(int i=0;i<N;i++) apar[ comp[i] ]++;

    for(int i=0;i<N;i++) if(apar[i]) nums[apar[i]]++;
    
    ll acum = 0, ans = INFLL;

    for(int i=N;i>=1;i--){
        if(!nums[i]) continue;

        ll aux = N - (nums[i] * i) - (acum * i);

        if(aux < ans) ans = aux;

        acum += nums[i];
    }

    cout << ans << endl;
}

int main(){

	optimize;
	
	cin >> T;

	while(T--){
		cin >> N;

        A.resize(N);
        B.resize(N);
        comp.resize(N);

		for(int i=0;i<N;i++) {
            cin >> A[i];
            B[i] = A[i];
        }
        
        sort(all(B));
        B.resize(unique(all(B)) - B.begin() );

        for(int i=0;i<N;i++){
            comp[i] = lower_bound(all(B), A[i]) - B.begin();
        }

		solve();
	}

	return 0;
}