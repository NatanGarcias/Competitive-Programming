#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef unsigned long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;

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
int path[MAXN];

bool bfs(ll x){

    ms(path, -1);

	queue<pii> fila;

    fila.push(make_pair(0,0));

    while(!fila.empty()){
        int u = fila.front().fi;
        int t = fila.front().se;

        fila.pop();

        if(u == N-1)    break;
        
        if(t+1 > K)     continue; 
        
        for(pii i : adj[u]){
            
            ll v = i.fi, p = i.se;

            if(p > x) continue;

            if(path[v] == -1){
                path[v] = u;
                fila.push(make_pair(v,t+1));
            }
        }
    }

    return (path[N-1] != -1);
}

ll bb(){

    ll l = 0LL, r = INF;
    
    while(l < r){
        ll m = (l+r)/2LL;

        if(bfs(m))
            r = m;
        else
            l = m + 1LL;
    }

	return l;
}

void solve(){
    
    int m = bb();

    if(m != INF){

        bfs(m);

        vector<int> ans;

        int p = N-1;

        while(p){
            ans.pb(p);
            p = path[p];
        }

        ans.pb(0);

        reverse(all(ans));

        cout << ans.size() - 1 << endl;

        cout << ans[0] + 1;
        for(int i=1;i<ans.size();i++) cout << " " << ans[i] + 1;
        cout << endl;
    }
    else{
        cout << -1 << endl;
    }
}

int main(){

	optimize;
	
	cin >> N >> M >> K;

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