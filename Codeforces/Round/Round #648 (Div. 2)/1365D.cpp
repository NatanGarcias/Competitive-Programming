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
#define MAXN 55

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;

char m[MAXN][MAXN];
bool vis[MAXN][MAXN];

vector<pii> mov = { pii(-1,0), pii(1,0), pii(0,-1), pii(0,1) };

bool posValid(int x, int y){
    if(x < 0 || y < 0 || x >= N || y >= M) return false;

    return true;
}

bool cercar(int x, int y){

    for(auto i : mov){
        if(posValid(x+i.fi, y+i.se)){
            if(m[x+i.fi][y+i.se] == 'G') return false;
            else if(m[x+i.fi][y+i.se] != 'B') m[x+i.fi][y+i.se] = '#';
        }
    }

    return true;
}

void bfs(){

    queue<pii> fila;

    if(m[N-1][M-1] == '#') return;

    fila.push(pii(N-1,M-1));
    vis[N-1][M-1] = true;

    while(!fila.empty()){
        int x = fila.front().fi;
        int y = fila.front().se;
        fila.pop();

        for(auto k : mov){
            if(posValid(x+k.fi,y+k.se) && !vis[x+k.fi][y+k.se] && m[x+k.fi][y+k.se] != '#'){
                vis[x+k.fi][y+k.se] = true;
                fila.push(pii(x+k.fi,y+k.se));
            }
        }
    }
}
void solve(){

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(m[i][j] == 'B'){
                if(!cercar(i,j)){
                    cout << "No\n";
                    return;
                }
            }
        }
    }

    bfs();

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(m[i][j] == 'G' && !vis[i][j]){
                cout << "No\n";
                return;
            }
        }
    }
    
    cout << "Yes\n";
}

int main(){

	//optimize;
	
	cin >> T;

    while(T--){
		cin >> N >> M;

        for(int i=0;i<N;i++) for(int j=0;j<M;j++) cin >> m[i][j];

        for(int i=0;i<N;i++) for(int j=0;j<M;j++) vis[i][j] = false;

		solve();
    }

	return 0;
}