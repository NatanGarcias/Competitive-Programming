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
#define MAXN 200020

vector<vector<int>> adj;
vector<int> present;
int N;

void bfs(int x, vector<int> &sol){

    bool vis[N] = {0};

    vis[x] = true;

    queue<int> fila;

    fila.push(x);

    while(!fila.empty()){
        int u = fila.front();
        fila.pop();

        sol.pb(u);

        for(auto i : adj[u]){
            if(!vis[i]){
                vis[i] = true;

                fila.push(i);
            }
        }
    }   
}

void corte(int x, int y){

    bool vis[N] = {0};

    vis[x] = true;

    queue<int> fila;

    fila.push(x);

    while(!fila.empty()){
        int u = fila.front();
        fila.pop();

        for(auto i : adj[u]){

            if(i == y){
                adj[i].erase( find (all(adj[i]),u));
                adj[u].erase( find (all(adj[u]),i));
                return;
            }

            if(!vis[i]){
                vis[i] = true;

                fila.push(i);
            }
        }
    }   
}

void buscaF(vector<int> &folhas){
    
    for(auto i : present){
        if(sz(adj[i]) == 1){
            folhas.pb(i);
        }
    }
}

void solve(){
    
    srand(time(NULL));
    
    int a,b,c;

    vector<int> folhas;

    while(sz(present) > 1){

        folhas.clear();

        buscaF(folhas);

        int a = folhas[0];
        int b = folhas[1];

        cout << "? " << a+1 << " " << b+1 << endl;

        cin >> c;

        c--;

        if(c == -1){
            return;
        }else if( a == c || b == c){
            cout << "! " << c+1 << endl;
            return;
        }else{
            present.clear();

            corte(a,c);
            corte(b,c);

            bfs(c,present);
        }
    }

    cout << "! " << present[0]+1 << endl;

}

int main(){

    cin >> N;

    adj.resize(N);
    present.assign(N,0);

    FOR(i,N){
        present[i] = i;
    }

    int a,b;   

    FOR(i,N-1){
        cin >> a >> b;

        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
	
    solve();

    return 0;
}