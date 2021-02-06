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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
int pot[MAXN];
bool dp[MAXN][MAXN];
string s, ans;

bool solve(int i, int j){

	if(i == N) return !j;

	if(!dp[i][j]) {

		if(s[i] == '?'){
			for(int k = 0;k<=9;k++){
				if(!i && !k) continue;

				if(solve(i+1, (j + pot[N-i-1] * k) % K)){
					ans[i] = k + '0';
					return dp[i][j] = true; 	
				}
				
			}
		}
		else{
			int k = s[i] - '0';

			return solve(i+1, (j + pot[N-i-1] * k) % K);
		}

		dp[i][j] = true;
	}

	return false;


}

void solve(){

	pot[0] = 1 % K;
	for(int i=1;i<N;i++) pot[i] = (pot[i-1] * 10) % K;

	ans = s;

	if(solve(0,0))  cout << ans << endl;
	else			cout << -1 << endl;
}

int main(){

	optimize;
	
	cin >> N >> K;
	
	cin >> s;

	if(N == 1 && s[0] == '?'){
		cout << "0\n";
		return 0;
	}

	if(N > 1 && s[0] == '0'){
		cout << "-1\n";
		return 0;
	}

	solve();

	return 0;
}