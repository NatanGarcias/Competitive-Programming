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
int A[MAXN], B[MAXN], ok[MAXN], vis[MAXN], nxt[MAXN];

bool dfs(int p){

    set<int> s;

    for(int i=0;i<p;i++) vis[A[i]] = 2, B[i] = A[i];

    B[p] = nxt[p];
    vis[nxt[p]] = 2;

    for(int i=0;i<N;i++){
        if(vis[i] == 2){
            for(int j : adj[i]){
                if(vis[j] < 2){
                    vis[j] = 3;
                    s.insert(j);
                }
            }
        }
    }

    while(!s.empty()){
        int v = *s.begin();

        B[++p] = v;

        s.erase(s.begin());

        for(int i : adj[v]){
            if(vis[i] < 2){
                s.insert(i);
                vis[i] = 3;
            }
        }
    }

}

void print(){
    for(int i=0;i<N;i++) cout << B[i] + 1 << " \n"[i==N-1];
}

void solve(){

    ok[0] = (A[0] != N-1);
    nxt[0] = A[0] + 1;

    set<int> s;
    vis[ A[0] ] = true;

    for(int v : adj[ A[0] ]){
        vis[v] = true;
        s.insert(v);
    }

    int cnt = 1;
    
    while(ok[0] && !s.empty()){
        auto it = s.lower_bound(A[cnt]);
        int u = *it;

        it++;

        if(it != s.end()) {
            ok[cnt] = true;
            nxt[cnt++] = *it;
        }
        else ok[cnt++] = false;
        
        s.erase(--it);

        for(int v : adj[u]){
            if(!vis[v]){
                vis[v] = true;
                s.insert(v);
            }
        }
    }

    for(int i=N-1;i>=0;i--){
        if(ok[i]) {
            dfs(i);
            print();
            return;
        }
    }

    cout << -1 << endl;
}

int main(){

	optimize;
	
	cin >> N >> M;

    adj.resize(N);

    for(int i=0;i<M;i++){
        int a,b;

        cin >> a >> b;

        a--, b--;

        adj[a].pb(b);
        adj[b].pb(a);
    }	
	
    for(int i=0;i<N;i++) cin >> A[i], A[i]--;

    solve();
    
	return 0;
}