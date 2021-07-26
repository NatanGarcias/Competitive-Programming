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
#define MAXN 1010
#define MAXM 200100

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
int A[MAXN], sum;
bool vis[MAXN];

bool solve(int meta){

	vector<bool> calc(meta+1, 0);
	calc[0] = true;

	for(int j=0;j<N;j++){
		if(vis[j]) continue;

		for(int i=meta-1;i>=0;i--){
			if(calc[i] && i + A[j] <= meta){
				calc[i + A[j] ] = true;
			}
		}
	}

	return calc[meta];
}

void solve(){

	if( sum&1 || !solve(sum/2) ){
		cout << 0 << endl;
		return;
	}

	for(int i=0;i<N;i++){
		vis[i] = true;

		if( (sum - A[i]) % 2){
			cout << 1 << endl;
			cout << i + 1 << endl;
			return;
		}
		else if( !solve( (sum-A[i])/2 ) ){
			cout << 1 << endl;
			cout << i + 1 << endl;
			return;
		}

		vis[i] = false;
	}
}

int main(){

	optimize;
	
	cin >> N;

	for(int i=0;i<N;i++){
		cin >> A[i];
		sum += A[i];
	}	

	solve();
    
	return 0;
}