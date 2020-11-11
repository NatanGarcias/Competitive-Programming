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
#define MAXN 1010
#define MAXL 987654321

ll T,N,M,K;
char v[MAXN][MAXN];
ll tempo[MAXN][MAXN];
bool vis[MAXN][MAXN];

bool posValid(int x , int y){

    if(x >= 0 && x < N && y>=0 && y<M) return true;
    return false;
}

void dfs(){

    priority_queue<pair<ll,pii>> pq;

    FOR(i,0,N){
        FOR(j,0,M){
            int cont = 0;

            if(posValid(i-1,j)) if(v[i-1][j] == v[i][j]) cont++;
            if(posValid(i+1,j)) if(v[i+1][j] == v[i][j]) cont++;
            if(posValid(i,j-1)) if(v[i][j-1] == v[i][j]) cont++;
            if(posValid(i,j+1)) if(v[i][j+1] == v[i][j]) cont++;

            if(cont){
                pq.push(make_pair(0,pii(i,j)));
                vis[i][j] = 1;
                tempo[i][j] = 0;
            }
        }
    }

    while(!pq.empty()){
        ll t = -pq.top().fi;
        int i = pq.top().se.fi, j = pq.top().se.se;
        pq.pop();
        
        if(posValid(i-1,j) && !vis[i-1][j]){
            tempo[i-1][j] = t+1;
            pq.push(make_pair(-(t+1),pii(i-1,j)));
            vis[i-1][j] = 1;
        }

        if(posValid(i+1,j) && !vis[i+1][j]){
            tempo[i+1][j] = t+1;
            pq.push(make_pair(-(t+1),pii(i+1,j)));
            vis[i+1][j] = 1;
        }

        if(posValid(i,j-1) && !vis[i][j-1]){
            tempo[i][j-1] = t+1;
            pq.push(make_pair(-(t+1),pii(i,j-1)));
            vis[i][j-1] = 1;
        }

        if(posValid(i,j+1) && !vis[i][j+1]){
            tempo[i][j+1] = t+1;
            pq.push(make_pair(-(t+1),pii(i,j+1)));
            vis[i][j+1] = 1;
        }
    }
}

void solve(){

    FOR(i,0,N) FOR(j,0,M) tempo[i][j] = MAXL;

    dfs();

    FOR(i,0,K){
        int a,b;
        ll c;

        cin >> a >> b >> c; a--; b--;

        if(tempo[a][b] == MAXL) cout << v[a][b] << endl;
        else if( tempo[a][b] >= c){
            cout << v[a][b] << endl;
        }else{
            ll dif = c - tempo[a][b];
            
            if( !(dif&1)){
                cout << v[a][b] << endl;
            }else{
                int ans = v[a][b] - '0';
                cout << (ans ^ 1) << endl;
            }
        }
    }
}

int main(){

    cin >> N >> M >> K;
    
    FOR(i,0,N) FOR(j,0,M) cin >> v[i][j];

    solve();

	return 0;
}