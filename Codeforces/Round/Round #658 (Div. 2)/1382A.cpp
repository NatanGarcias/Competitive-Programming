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
#define MAXN 1020

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
int A[MAXN], B[MAXN], C[MAXN];

void solve(){
	
	ms(C,0);

	for(int i=0;i<N;i++){
		C[A[i]] = 1;
	}

	for(int i=0;i<M;i++){
		if(C[B[i]]) C[B[i]] = 2;
	}

	int ans = -1;

	for(int i=0;i<1010;i++){
		if(C[i] == 2){
			ans = i;
			break;
		}
	}

	if(ans == -1){
		cout << "NO\n";
	}
	else{
		cout << "YES\n";
		cout << 1 << " " << ans << endl;
	}

}

int main(){

	//optimize;
	
	cin >> T;

    while(T--){
		cin >> N >> M;

		for(int i=0;i<N;i++) cin >> A[i];
		for(int i=0;i<M;i++) cin >> B[i];

		solve();
    }

	return 0;
}