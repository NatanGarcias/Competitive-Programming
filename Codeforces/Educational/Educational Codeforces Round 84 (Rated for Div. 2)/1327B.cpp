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

int T,N,M;
vector<vector<int>> adj;

void solve(){
    vector<bool> vis(N,false);
    vector<bool> vis2(N,false);

    FOR(i,N){
        FOR(j,sz(adj[i])){
            if( !vis2[ adj[i][j] ] ){
                vis2[ adj[i][j] ] = true;
                vis[i] = true;
                j+= sz(adj[i]);
            }
        }
    }
    
    bool pular = true;

    FOR(i,N){
        if(!vis[i]){
            pular = false;
            cout << "IMPROVE" << endl << i+1 << " ";
            break;
        }
    }

    FOR(i,N){
        if(!vis2[i]){
            cout << i+1 << endl;
            break;
        }
    }

    if(pular){
        cout << "OPTIMAL" << endl;
    }

    
}
int main(){

	cin >> T;

    int a,b;

	while(T--){
        cin >> N;

        adj.clear();
        adj.resize(N);

        FOR(i,N){
            cin >> a;

            FOR(j,a){
                cin >> b;
                adj[i].push_back(b-1);
            }

        }
     
        solve();
	}

	return 0;
}