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
#define MAXN 2010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
char m[MAXN][MAXN];

pii moves[] = { {-1,0}, {+1,0}, {0,+1}, {0,-1} };

bool posValid(int x, int y){
    if(x < 0 || y < 0 || x >= N || y >= M) return false;
    if(m[x][y] == '#') return false;
    return true;
}

vector<vector<int>> bfs(char s){

    vector<vector<int>> time(N, vector<int> (M,0)); 
    vector<vector<bool>> vis(N, vector<bool> (M,0)); 

    queue<pair<pii, int>> fila;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(m[i][j] == s) fila.push(make_pair(pii(i,j), 0));
        }
    }

    while(!fila.empty()){
        pii p = fila.front().fi;
        int t = fila.front().se;

        fila.pop();

        vis[p.fi][p.se] = 1;
        time[p.fi][p.se] = t;

        for(int i=0;i<4;i++){
            if(posValid(p.fi + moves[i].fi, p.se + moves[i].se) && !vis[p.fi + moves[i].fi][ p.se + moves[i].se]){
                vis[p.fi + moves[i].fi][ p.se + moves[i].se] = 1;
                fila.push(make_pair(pii(p.fi + moves[i].fi, p.se + moves[i].se), t+1));
            }
        }
    }

    return time;
}

void solve(){

    auto preso = bfs('S');
    auto fogo = bfs('F');

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(m[i][j] == 'E' && preso[i][j]){
                if(preso[i][j] < fogo[i][j]) cout << "Y\n";
                else cout << "N\n";
                
                return;
            }
        }
    }
    
    cout << "N\n";
}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
		cin >> N >> M;

        for(int i=0;i<N;i++) for(int j=0;j<M;j++) cin >> m[i][j];

		solve();
    }

	return 0;
}