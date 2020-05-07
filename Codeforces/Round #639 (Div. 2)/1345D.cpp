#include<bits/stdc++.h>
using namespace std;

// Template 1 .. Natan
typedef long long ll;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define pii pair<int,int>
#define fi first 
#define se second 
#define pb push_back
#define sz(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define FOR(x,a,n) for(int x= (int)(a);(x) < int(n);(x)++)
#define INF 0x3f3f3f3f
#define ms(x,a) memset(x,a,sizeof(x))

#define MAXN 1010

ll T,N,M;
char v[MAXN][MAXN];
bool q[MAXN][MAXN];

vector<bool> hor;
vector<bool> ver;
vector<bool> H;
vector<bool> V;    

bool posValid(int x, int y){
    if(x < 0 || y < 0 || x >= N || y >= M ) return false;
    return true;
}

void quinas(){
    
    FOR(i,0,N){
        FOR(j,0,M){
            int cont = 0;
            bool ve = false,ho = false;

            if(v[i][j] == '#'){
            
                if(posValid(i-1,j)){
                    if(v[i-1][j] == '#'){
                        cont++;
                        ho = true;
                    }
                }
                if(posValid(i+1,j)){
                    if(v[i+1][j] == '#'){
                        cont++;
                        ho = true;
                    }
                }
                if(posValid(i,j-1)){
                    if(v[i][j-1] == '#'){
                        cont++;
                        ve = true;
                    }
                }
                if(posValid(i,j+1)){
                    if(v[i][j+1] == '#'){
                        cont++;
                        ve = true;
                    }
                }

                if(cont == 0 || cont == 1 || cont == 3 || (cont == 2 && (ve && ho) )){
                    q[i][j] = true;
                }
            }
        }
    }
}

bool seqH(int y,int y1, int y2){
    
    FOR(i,y1,y2+1){
        if(v[y][i] != '#') return true;
    }

    return false;
}

bool seqV(int y,int y1, int y2){
    
    FOR(i,y1,y2+1){
        if(v[i][y] != '#') return true;
    }

    return false;
}

bool olhaQuinas(){

    FOR(i,0,N){
        
        int menor = INF;
        int maior = -INF;

        FOR(j,0,M){
            if(v[i][j] == '#'){
                maior = max(maior, j);
                menor = min(menor,j);
            }
        }

        if(menor == INF ){
            H[i] = true;
        }
        if(menor == maior) hor[i] = true;

        if(menor != INF && seqH(i,menor,maior)){
            return false;
        }
    }


    FOR(i,0,M){

        int menor = INF;
        int maior = -INF;

        FOR(j,0,N){
            if(v[j][i] == '#'){
                maior = max(maior, j);
                menor = min(menor,j);
            }
        }

        if(menor == INF){
            V[i] = true;
        }
        
        if(menor == maior) ver[i] = true;
        
        if(menor != INF && seqV(i,menor,maior)){
            return false;
        }
    }

    return true;
}

void i(){
    FOR(i,0,N){
        FOR(j,0,M){
            if(q[i][j]) cout << 1;
            else cout << 0;
        }cout << endl;
    }cout << endl;
}

void dfs(int i, int j){

    stack<pii> pilha;

    pilha.push(pii(i,j));

    q[i][j] = true;

    while(!pilha.empty()){
        auto u = pilha.top();
        pilha.pop();

        if(posValid(u.fi-1,u.se) && !q[u.fi-1][u.se] && v[u.fi-1][u.se] == '#'){
            q[u.fi-1][u.se] = true;
            pilha.push(pii(u.fi-1,u.se));
        }
        if(posValid(u.fi+1,u.se) && !q[u.fi+1][u.se] && v[u.fi+1][u.se] == '#'){
            q[u.fi+1][u.se] = true;
            pilha.push(pii(u.fi+1,u.se));
        }
        if(posValid(u.fi,u.se-1) && !q[u.fi][u.se-1] && v[u.fi][u.se-1] == '#'){
            q[u.fi][u.se-1] = true;
            pilha.push(pii(u.fi,u.se-1));
        }
        if(posValid(u.fi,u.se+1) && !q[u.fi][u.se+1] && v[u.fi][u.se+1] == '#'){
            q[u.fi][u.se+1] = true;
            pilha.push(pii(u.fi,u.se+1));
        }
    }
}

int ciclos(){
    
    ms(q,0);    
    
    int ans = 0;

    FOR(i,0,N){
        FOR(j,0,M){
            if(!q[i][j] && v[i][j] == '#'){
                dfs(i,j);
                ans++;
            }
        }
    }

    return ans;
}

bool verifica(){


    FOR(i,0,N){
        FOR(j,0,M){
            if( H[i] && V[j]){
                hor[i] = true;
                ver[j] = true;
            }
        }
    }

    FOR(i,0,N){
        FOR(j,0,M){
            if(q[i][j]){
                hor[i] = true;
                ver[j] = true;
            }
        }
    }

    FOR(i,0,N){
        if(!hor[i]) return false;
    }

    FOR(i,0,M){
        if(!ver[i]) return false;
    }

    return true;
}

void solve(){
    
    quinas();

    bool resp = olhaQuinas();

    if(!verifica()){
        cout << -1 << endl;
        return;
    }

    if(!resp) {
        cout << -1 << endl;
        return;
    }

    int ans = ciclos();

    cout << ans << endl;
}

int main(){

    optimize;
    
    cin >> N >> M;

    H.assign(N,false);
    V.assign(M,false);
    hor.assign(N,false);
    ver.assign(M,false);

    FOR(i,0,N) FOR(j,0,M) cin >> v[i][j];

    solve();

	return 0;
}