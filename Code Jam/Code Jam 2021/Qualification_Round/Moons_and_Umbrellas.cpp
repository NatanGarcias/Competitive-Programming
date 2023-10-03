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
//Subtasks 1 - AC
//Subtasks 2 - AC
//Subtasks 3 - AC

ll T,N,M,K,X,Y;
string s;

int dp[MAXN][2], ok[MAXN][2];

ll solve(int i, bool b){
    
    if(i == N-1) return 0;

    ll ans = 0;

    if(ok[i][b]) return dp[i][b];

    if(s[i + 1] == 'C'){
        if(!b) ans = solve(i+1, 0); 
        else   ans = Y + solve(i+1, 0);
    }
    else if(s[i + 1] == 'J'){
        if(!b) ans = X + solve(i+1, 1); 
        else   ans = solve(i+1, 1);
    }
    else{
        if(!b) ans = min(     solve(i+1, 0), X + solve(i+1, 1) ); 
        else   ans = min( Y + solve(i+1, 0),     solve(i+1, 1) ); 
    }

    ok[i][b] = true;
    return dp[i][b] = ans;
}

void solve(int caso){

    ms(dp, 0);
    ms(ok, 0);

    ll ans = INFLL;

    if(s[0] == 'C'){
        ans = solve(0, 0);
    }
    else if(s[0] == 'J'){
        ans = solve(0, 1);
    }
    else{
        ans = min(ans, solve(0, 0));

        ms(dp, 0);
        ms(ok, 0);

        ans = min(ans, solve(0, 1));
    }

	cout << "Case #" << caso << ": " << ans << endl;
}

int main(){

	optimize;
	
	cin >> T;

    for(int i=1;i<=T;i++){
		cin >> X >> Y >> s;

        N = s.size();

		solve(i);
    }

	return 0;
}