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
#define MAXN 510

ll N,M,I;
char K;
int idade[MAXN];
vector<set<int>> adj;

void imprimi(){
    cout << "Adj:\n";
    FOR(i,0,N){
        for(auto j : adj[i]){
            cout << j << " ";
        }cout << endl;
    }
    cout << "Fim\n";
}

int dfs(int a){

    vector<bool> vis(N,false);

    int menor = INF;

    stack<int> pilha;

    pilha.push(a);
    vis[a] = true;

    while(!pilha.empty()){
        int v = pilha.top();
        pilha.pop();

        for(auto i : adj[v]){
            if(!vis[i]){
                menor = min(menor , idade[i]);
                pilha.push(i);
                vis[i] = true;
            }
        }
    }

    return menor;
}

void solve(){

    FOR(i,0,I){
        cin >> K;

        if( K == 'T'){
            int a,b;

            cin >> a >> b;

            a--; b--;

            FOR(j,0,N){
                vector<int> add;
                vector<int> rem;
                for(auto it = adj[j].begin(); it != adj[j].end();it++){
                    if( (*it) == a ){
                        rem.pb(a);
                        add.pb(b);
                    }else if( (*it) == b ){
                        rem.pb(b);
                        add.pb(a);
                    }
                }

                for(auto k : rem) adj[j].erase(k);
                for(auto k : add) adj[j].insert(k);
            }
            swap(adj[a], adj[b]);
        }else{
            int a;
            
            cin >> a;

            a--;

            int ans = dfs(a);

            if(ans == INF) cout << '*' << endl;
            else cout << ans << endl;
        }
    }

}

int main(){

    optimize;

	cin >> N >> M >> I;

    adj.resize(N);

    FOR(i,0,N) cin >> idade[i];

    FOR(i,0,M){
        int a,b;

        cin >> a >> b;

        a--; b--;

        adj[b].insert(a);
    }

    solve();

	return 0;
}