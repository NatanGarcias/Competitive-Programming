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
#define MAXN 300010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
int A[MAXN], nums[MAXN], permA[MAXN], xorA[MAXN];

void solve(){

	for(int i=0;i<N;i++) nums[i] = rng() % mod;
	for(int i=0;i<N;i++) xorA[i+1] = (A[i] + nums[ A[i] ]) ^ xorA[i];
	for(int i=0;i<N;i++) permA[i+1] = (nums[i + 1] + i + 1) ^ permA[i]; 

	int ans = 0, ptr = 0, ptr2 = 0;
	vector<pii> par;

	//Da esquerda para a direita
	int maior = 0, ok = 0;
	for(int i=0;i<N;i++) {

		if(A[i] == 1) {
			ans++;
			maior = 1;
			ok = 1;
		}
		else if(ok){
			maior = max(maior, A[i]);

			int l = i - maior + 1;
			int r = i;

			if(l >= 0) par.pb(pii(l,r));
		}
	}

	//Direita para esquerda
	reverse(A,A+N);
	
	maior = 0, ok = 0;
	for(int i=0;i<N;i++) {

		if(A[i] == 1) {
			maior = 1;
			ok = 1;
		}
		else if(ok){
			maior = max(maior, A[i]);

			int r = N - 1 - (i - maior + 1);
			int l = N - 1 - i;
			if(l >= 0) par.pb(pii(l,r));
		}
	}

	for(auto [l,r] : par){
		if( (xorA[r + 1] ^ xorA[l]) == permA[r - l + 1] ) ans++;		
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