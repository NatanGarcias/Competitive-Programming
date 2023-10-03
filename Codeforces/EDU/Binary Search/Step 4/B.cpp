#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef unsigned long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;

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
vector<vector<pii>> adj;
bool vis[MAXN];
ld dp[MAXN];
int path[MAXN];

ld dfs(int u, ld x){

	if(dp[u] != -1) return dp[u];

	if(u == N-1) return 0.0;

	vis[u] = true;

	ld valF = INF;

	for(auto i : adj[u]){
		int v = i.fi;
		int w = i.se;

		ld a;

		if(!vis[v]){
			a = dfs(v,x);
			a += w - x;
		}
		else{
			a = dp[u];
			a += w - x;
		} 

		if(a < valF){
			valF = a;
			path[u] = v;
		}	
	}

	dp[u] = valF;
	vis[u] = false;

	return dp[u];
}

bool f(ld x){

	for(int i=0;i<N;i++) {
		dp[i] = -1;
	}

	return dfs(0,x) <= 0;
}

ld bb(){

    ld l = 0.0, r = 100.0;
    
    for(int i=0;i<100;i++){
        ld m = (l+r)/2.0;

        if(f(m))
            r = m;
        else
            l = m;
    }

	return l;
}

void solve(){
    
    ld m = bb();

	f(m);

	vector<int> ans;
	ans.pb(0);

	while(ans.back() != N-1){
		ans.pb(path[ans.back()]);
	}

	cout << ans.size() - 1 << endl;
	
	cout << ans[0] + 1;
	for(int i=1;i<ans.size();i++) cout << " " << ans[i] + 1;
	cout << endl;
}

int main(){

	optimize;
	
	cin >> N >> M;

    adj.resize(N);

    for(int i=0;i<M;i++) {
        int a,b,c;

        cin >> a >> b >> c;

        a--, b--;

        adj[a].pb(pii(b,c));
    }
		
	solve();
    
	return 0;
}