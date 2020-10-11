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
#define FOR(x,a,n) for(int x= (int)(a);(x) < int(n);(x)++)
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 2010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
char v[MAXN][MAXN];
bool vis[MAXN][MAXN];
pii pos[MAXN][MAXN];

pii c,f;
string ans;

void resposta(){
    if(ans.empty()) cout << -1 << endl;
    else {
        cout << ans.size() << endl;
        cout << ans << endl;
    }

    exit(0);
}

bool posValid(int x, int y){
    if(x >= 0 && y >= 0 && x < N && y < M) return true;
    return false;
}

void bfs(pii x){

    queue<pii> fila;
    vis[x.fi][x.se] = true;

    fila.push(x);

    while(!fila.empty()){
        pii u = fila.front();
        fila.pop();

        //Para baixo
        int cnt = 1;
        while(posValid(u.fi + cnt, u.se) && v[u.fi + cnt][u.se] == 'X') cnt++;

        if(posValid(u.fi + cnt, u.se) && v[u.fi + cnt][u.se] != 'X' && !vis[u.fi + cnt][u.se]){

            pos[u.fi + cnt][u.se] = u;
            vis[u.fi + cnt][u.se] = true;
            fila.push(pii(u.fi + cnt,u.se));

            if(pii(u.fi + cnt, u.se) == f) return;        
        }
    
        //Para esquerda
        cnt = 1;
        while(posValid(u.fi, u.se - cnt) && v[u.fi][u.se - cnt] == 'X') cnt++;

        if(posValid(u.fi, u.se - cnt) && v[u.fi][u.se - cnt] != 'X' && !vis[u.fi][u.se - cnt]){

            pos[u.fi][u.se - cnt] = u;
            vis[u.fi][u.se - cnt] = true;
            fila.push(pii(u.fi,u.se - cnt));

            if(pii(u.fi, u.se - cnt) == f) return;        
        }       

        //Para direita
        cnt = 1;
        while(posValid(u.fi, u.se+cnt) && v[u.fi][u.se+cnt] == 'X') cnt++;

        if(posValid(u.fi, u.se+cnt) && v[u.fi][u.se+cnt] != 'X' && !vis[u.fi][u.se+cnt]){
            
            pos[u.fi][u.se+cnt] = u;
            vis[u.fi][u.se+cnt] = true;
            fila.push(pii(u.fi,u.se+cnt));

            if(pii(u.fi, u.se + cnt) == f) return;        
        }

        //Para cima
        cnt = 1;
        while(posValid(u.fi - cnt, u.se) && v[u.fi - cnt][u.se] == 'X') cnt++;

        if(posValid(u.fi - cnt, u.se) && v[u.fi - cnt][u.se] != 'X' && !vis[u.fi - cnt][u.se]){

            pos[u.fi - cnt][u.se] = u;
            vis[u.fi - cnt][u.se] = true;
            fila.push(pii(u.fi - cnt,u.se));

            if(pii(u.fi - cnt, u.se) == f) return;        
        }
    }
}

void solve(){

    ms(pos, -1);

    bfs(c);

    if(!vis[f.fi][f.se]) resposta();

    while(f != c){
        int x = pos[f.fi][f.se].fi;
        int y = pos[f.fi][f.se].se;

        if(f.fi > x){
            ans.push_back('D');
        }
        else if(f.fi < x){
            ans.push_back('U');
        }
        else if(f.se > y){
            ans.push_back('R');
        }
        else if(f.se < y){
            ans.push_back('L');
        }

        f = pii(x,y);
    }

    reverse(all(ans));
    resposta();
}

int main(){

	optimize;
	
	cin >> N >> M;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> v[i][j];

            if(v[i][j] == 'S') c = pii(i,j);  
            else if(v[i][j] == 'E') f = pii(i,j);
        }
    }

	solve();

	return 0;
}