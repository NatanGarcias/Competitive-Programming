#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld; 

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

#define pii pair<int,int>
#define fi first 
#define se second 
#define pb push_back

#define sz(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define FOR(x,a,n) for(int x= (int)(a);(x) < int(n);(x)++)
#define ms(x,a) memset(x,a,sizeof(x))

#define PI 3.141592653589793238462643383279502884
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007
#define MAXN 100010

ll T,N,M,K,A,B,C;
vector<vector<int>> adj;
vector<vector<int>> adj2;
vector<int> ans;
int v[MAXN];
int vis[MAXN];

void dfs(int x){

    vis[x] = true;

    stack<int> fila;
    fila.push(x);   

    vector<int> aux;

    while(!fila.empty()){
        int u = fila.top();
        fila.pop();
        
        if(adj[u].size() > 1) break;
        else{
            aux.pb(u);
            for(auto i : adj2[u]){
                if(!vis[i]){
                    fila.push(i);
                    vis[i] = true;
                }
            }
        }
    }

    if(ans.empty() || ans.size() < aux.size()) {
        reverse(all(aux));
        ans = aux;
    }
}

void solve(){

    FOR(i,1,N+1) if(v[i]) dfs(i);

    cout << sz(ans) << endl;
    FOR(i,0,sz(ans)) cout << ans[i] << " \n"[i == sz(ans) -1];
}

int main(){

    cin >> N;

    adj.resize(N+1);
    adj2.resize(N+1);

	FOR(i,1,N+1) cin >> v[i];
	
    FOR(i,1,N+1){
        int a;
        cin >> a;

        if(a){
            adj[a].pb(i);
            adj2[i].pb(a);
        } 
    } 

    solve();

	return 0;
}