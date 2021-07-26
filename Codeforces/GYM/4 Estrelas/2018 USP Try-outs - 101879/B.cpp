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

ll _tam_crivo;

bool v[MAXN];
vector<int> primos;

void crivo(ll limite) { 
    _tam_crivo = MAXN - 10;
    for (ll i = 2; i <= _tam_crivo; i++){
        if (!v[i]) {   
            for (ll j = i*i; j <= _tam_crivo;j+=i)   v[j] = true;
            primos.pb(i);
        }
    }
}

vector<int> nums;

void fatores(){
	
	int M = N;

	for(int i=0;i<primos.size() && M > 1;i++){
		if(primos[i] > M) break;

		while(M > 1 && (! (M % primos[i] ) ) ){
			M /= primos[i];
			nums.pb(primos[i]);
		}
	}
} 

int A[MAXN];

void solve(){

	fatores();

	unique(all(nums));

	for(int i=0;i<nums.size();i++){
		vector<int> vis(nums[i],0);

		for(int j=0;j<N;j++){
			int resto = A[j]%nums[i];

			vis[resto]++;
		}

		bool ok = true;
		for(int j=0;j<nums[i];j++){
			if(vis[j] != N/nums[i]) {
				ok = false;
				break;
			}
		}

		if(ok){
			cout << nums[i] << endl;
			return;
		}
	}

	cout << -1 << endl;
}

int main(){

	optimize;

	crivo(MAXN);

	cin >> N;

	for(int i=0;i<N;i++) cin >> A[i];
    	
	solve();
    
	return 0;
}