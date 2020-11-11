#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;

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
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;

struct Node{
    ll a,b,c;

    Node(ll _a = 0, ll _b = 0, ll _c = 0): a(_a), b(_b), c(_c) {};
};

Node v[MAXN];
vector<vector<int>> adj;
bool vis[MAXN];
ll ans;

pii dfs(ll u, ll cost){
  
    pii a(0,0);

    vis[u] = true;

    if(v[u].b == 1 && v[u].c == 0) a.fi++;
    else if(v[u].b == 0 && v[u].c == 1) a.se++;

    for(int w : adj[u]){
        if(vis[w]) continue;

        pii aux = dfs(w, min(cost, v[u].a));

        a.fi += aux.fi;
        a.se += aux.se;
    }

    if(v[u].a < cost){
        ll aux = min(a.fi,a.se);
        
        ans += 2LL*aux*v[u].a;

        a.fi -= aux;
        a.se -= aux;
    }   
    
    return a;
}
void solve(){

    pii a = dfs(0,INFLL);

    if(a.fi || a.se)    cout << -1 << endl;
    else                cout << ans << endl;
}

int main(){

	optimize;
	
    cin >> N;

    adj.resize(N);

    for(int i=0;i<N;i++){
        int a,b,c;
        cin >> a >> b >> c;

        v[i] = Node(a,b,c);
    }	

    for(int i=0;i<N-1;i++){
        int a,b;

        cin >> a >> b;

        a--, b--;

        adj[a].pb(b);
        adj[b].pb(a);
    }

	solve();
    
	return 0;
}