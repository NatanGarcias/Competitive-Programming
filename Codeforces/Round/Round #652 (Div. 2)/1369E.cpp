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
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;

vector<set<int>> adj, adj2;
int A[MAXN];
bool vis[MAXN], vis2[MAXN];

void solve(){
    vector<int> ans;
    queue<int> fila;

    for(int i=0;i<N;i++) {
        if(A[i] >= adj[i].size() ) {
            fila.push(i);
            vis[i] = true;
        }
    }

    int cnt = 0;

    while(!fila.empty()){
        int u = fila.front();
        fila.pop();
        
        //Para todo mundo que come essa pizza
        for(auto i : adj[u]){

            if(!vis2[i]) {
                vis2[i] = true;
                ans.pb(i);
                cnt++;
            }

            //Para todas as pizzas que essa pessoa pode comer
            for(auto j : adj2[i]){
                if(!vis[j]){
                    if(!adj[j].empty()) adj[j].erase(i);

                    if(!vis[j] && A[j] >= adj[j].size()) {
                        vis[j] = true;
                        fila.push(j);
                    }
                }
            }
        }
    }

    if(cnt != M)
        cout << "DEAD\n";
    else{
        cout << "ALIVE\n";
        for(int i=M-1;i>=0;i--) cout << ans[i]+1 << " \n"[!i];
    }

}

int main(){

	optimize;
	
    cin >> N >> M;

    adj.resize(N);
    adj2.resize(M);

    for(int i=0;i<N;i++) cin >> A[i];

    for(int i=0;i<M;i++) {
        int a,b;

        cin >> a >> b;

        a--, b--;

        adj[a].insert(i);
        adj[b].insert(i);

        adj2[i].insert(a);
        adj2[i].insert(b);
    }
    
    solve();

	return 0;
}