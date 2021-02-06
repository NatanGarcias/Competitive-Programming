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
string s;

void solve(){

	N = s.size();
	vector<bool> A(N,0);
	vector<int> dp(N,-1);

	for(int i=0;i<N;i++) if(s[i] == 'R') A[i] = true;

	for(int i=1;i<N;i++){

		int k = __gcd(i, (int) N);

		if(~dp[k]){
			K += dp[k];
			continue;
		}

		for(int j=0;j<k;j++){

			bool ok = true;
			vector<bool> vis(N,0);
			int l = j;

			while(!vis[l]){
				if(!A[l]){
					ok = false;
					break;
				}

				vis[l] = true;
				l += k;
				l %= N;
			}

			dp[k] = max( (int) ok, dp[k]);
			
			if(ok){
				K++;
				break;
			}
		}
	}
	
	cout << K << endl;
}

int main(){

	optimize;
	
	cin >> s;

	solve();
    
	return 0;
}