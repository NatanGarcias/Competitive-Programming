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
vector<vector<int>> adj;
ll dp[MAXN][2], pre[MAXN], suf[MAXN];

void dfs(int u){

    vector<ll> a,b;
    ll prod = 1LL, sum = 0LL;

    for(auto i : adj[u]) {
        dfs(i);     

        a.pb(dp[i][0]);
        b.pb(dp[i][1]);

        prod = (prod * dp[i][0]) % mod;
    }

    int n = a.size();
    suf[0] = pre[0] = 1;

    for(int i=0;i<n;i++) pre[i+1] = (pre[i] * a[i]) % mod;
    for(int i=n-1;i>=0;i--) suf[ n - i ] = (suf[ n - (i+1) ] * a[i]) % mod;
    
    for(int i=0;i<n;i++){
        sum += ((pre[i] * suf[n-i-1]) % mod) * b[i];
        sum %= mod;
    }

    dp[u][0] = (prod + sum) % mod;
    dp[u][1] = sum;

    if(adj[u].empty()) {
        dp[u][0] = 1LL;
        dp[u][1] = 1LL;
    }
}

void solve(){

    dfs(0);
    
    cout << dp[0][0] << endl;
}

int main(){

	optimize;
	
	cin >> N;

    adj.resize(N);

    for(int i=1;i<N;i++){
        int a;

        cin >> a;
        a--;

        adj[a].pb(i);
    }
		
	solve();
    
	return 0;
}