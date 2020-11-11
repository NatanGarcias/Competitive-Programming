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
#define MAXN 2010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
string s,t;
int dp[MAXN][MAXN], suf[MAXN][26], suf2[MAXN][26];

int solve(int i, int j){

    if(j == 0) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int ans = INF;

    if(i > 0){
        ans = min(ans, 1 + solve(i-1,j));

        if(s[i-1] == t[j-1]) ans = min(ans, solve(i-1,j-1));
    }   

    int c = t[j-1] - 'a';
    
    if(suf[i+1][c] > suf2[j+1][c]) ans = min(ans, solve(i,j-1));

    dp[i][j] = ans;

    return dp[i][j];
}

void solve(){

    int ans = solve(N,N);

    if(ans == INF)  cout << -1 << endl;
    else            cout << ans << endl;
}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
		cin >> N;

        cin >> s >> t;

        for(int i=0;i<=N;i++){
            for(int j=0;j<=N;j++){
                dp[i][j] = -1;
            }
            for(int j=0;j<26;j++){
                suf[i][j] = -1;
                suf2[i][j] = -1;
            }
        }
        
        for(int i=N;i>=1;i--){
            for(int j=0;j<26;j++){
                suf[i][j] = suf[i+1][j];
                suf2[i][j] = suf2[i+1][j];
            }

            suf[i] [ (int)s[i-1] - 'a']++;
            suf2[i][ (int)t[i-1] - 'a']++;
        }
        
		solve();
    }

	return 0;
}