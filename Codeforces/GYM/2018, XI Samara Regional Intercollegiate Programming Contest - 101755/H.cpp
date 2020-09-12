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
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
vector<vector<char>> v;
vector<vector<int>> tempo;

bool posValid(int x, int y){
    if(x < 0 || y < 0 || x >= N || y >= M) return false;
    return true;
}

void realoc(){
    v.resize(N);
    tempo.resize(N);
    
    for(int i=0;i<N;i++) {
        v[i].resize(M);
        tempo[i].resize(M,-1);
    }
}

void bfsM(char k){

    queue<pair<int,pii>> fila;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(v[i][j] == k) {
                fila.push(make_pair(K,pii(i,j)));
                tempo[i][j] = INF;
            }
        }
    }

    while(!fila.empty()){
        int x = fila.front().se.fi;
        int y = fila.front().se.se;
        int t = fila.front().fi;
        fila.pop();

        if(!t) continue;

        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if(abs(i+j) == 1 && posValid(x+i,y+j) && tempo[x+i][y+j] == -1){
                    fila.push(make_pair(t-1,pii(x+i,y+j)));
                    tempo[x+i][y+j] = INF;
                }
            }
        }
    }
}

void bfsP(char k){

    queue<pair<int,pii>> fila;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(v[i][j] == k && tempo[i][j] != INF) {
                fila.push(make_pair(0,pii(i,j)));
                tempo[i][j] = 0;
                break;
            }
        }
    }

    while(!fila.empty()){
        int x = fila.front().se.fi;
        int y = fila.front().se.se;
        int t = fila.front().fi;

        fila.pop();
    
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if(abs(i+j) == 1 && posValid(x+i,y+j) && tempo[x+i][y+j] == -1){
                    fila.push(make_pair(t+1,pii(x+i,y+j)));
                    tempo[x+i][y+j] = t+1;
                }
            }
        }
    }
}

void solve(){

    bfsM('M');
    bfsP('S');

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(v[i][j] == 'F') {
                if(tempo[i][j] >= 0 &&  tempo[i][j] < INF){
                    cout << tempo[i][j] << endl;
                }else{
                    cout << -1 << endl;
                }
            }
        }
    }
}

int main(){

	optimize;
	
	cin >> N >> M >> K;

    realoc();

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> v[i][j];
        }
    }
		
	solve();

	return 0;
}