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
int A[MAXN];

void solve(){

	vector<int> pre(N+1,0), suf(N+1,0);

	for(int i=0;i<N;i++) pre[i+1] = pre[i] ^ A[i];
	for(int i=N-1;i>=0;i--) suf[i] = suf[i+1] ^ A[i];

	for(int i=1;i<N;i++){
		int aux = 0;

		for(int j=i;j<N;j++){

			if(j == i){
				if(pre[i] == suf[i]){
					cout << "YES\n";
					return;
				}	
			}
			else{
				if(pre[i] == aux && aux == suf[j]){
					cout << "YES\n";
					return;
				}
			}

			aux ^= A[j];
		}
	}

	cout << "NO\n";
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