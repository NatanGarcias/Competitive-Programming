#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld; 

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define endl "\n"
#define space " " 

#define pii pair<int,int>
#define fi first 
#define se second 
#define pb push_back
#define sz(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define ms(x) memset(x,0,sizeof(x))
#define ms2(x) memset(x,-1,sizeof(x))

#define PI 3.141592653589793238462643383279502884
#define FOR(x,n) for(int x=0;(x) < int(n);(x)++)
#define FOR1(x,n) for(int x=1;(x) <= int(n);(x)++)

#define INF 0x3fffffff
#define INFLL 0x3fffffffffffffff

#define mod %1000000007
#define MAXN 200010

priority_queue<pii> folhas;
vector<vector<int>> adj;
bool valor[MAXN];
int pai[MAXN];
int N,K;

void bfs(){

    bool vis[N] = {0};

    stack<pii> fila;
    
    pai[0] = -1;

    fila.push({0,1});
    
    vis[0] = true;

    while(!fila.empty()){
        int u = fila.top().first;
        int t = fila.top().second;
        fila.pop();

        if(adj[u].empty()){
            folhas.push({t,u});
        }

        FOR(i,sz(adj[u])){
            
            int aux = adj[u][i];

            if(!vis[aux]){
                pai[aux] = u;
                fila.push({aux,t + 1});
                vis[aux] = true;
            }
        }
    }
}

int atualizo(int v){
    if(valor[v]) return 0;
    
    int cont = 1;

    while(pai[v] != -1 && !valor[pai[v]]){
        cont++;
        v = pai[v];
    }

    return cont;
}
void corte(int v){

    if(valor[v]) return;
    
    valor[v] = true;
    
    while(pai[v] != -1){
        v = pai[v];
        valor[v] = true;
    }
}

void solve(){

    int ans = 0;
    int v, cont = -1;

    bfs();

    while(K--){
        cont++;
        if(!cont){
            v = folhas.top().se;
            ans += folhas.top().fi;
            folhas.pop();
        }else{
            v = -1;
            
            while(v != folhas.top().se){
                v = folhas.top().se;
                folhas.pop();

                int z = atualizo(v);
                folhas.push({z,v});
            }
            ans += folhas.top().fi;
            folhas.pop();
        }
        corte(v);
    }   
    
    cout << ans << endl;
}

int main(){

    cin >> N >> K;

    adj.resize(N);

    int a;
    FOR(i,N-1){
        cin >> a;
        adj[a-1].push_back(i+1);
    }

    solve();

    return 0;
}