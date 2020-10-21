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

ll N,M,T,a;
int v[MAXN];

void solve(){
	
    bool vis[2*a+3] = {0};
    bool ans = false;

    vector<int> sol;
    sol.push_back(0);

    FOR1(i,a){
        vis[v[i]] = true;
    }

    FOR1(i,a){
        int aux = v[i];

        sol.push_back(v[i]);

        if(aux+1 > 2*a) {
            cout << -1 << endl;
            return;
        }
        while(vis[aux +1] == true){
            aux++;
            if( aux+1 >= 2*a+1){
                cout << -1 << endl;
                return;
            }
        }
        sol.push_back(aux+1);
        vis[aux+1] = true;
    }
    
    FOR1(i,2*a) cout << sol[i] << " \n"[i==2*a];
    
}

int main(){

	cin >> T;

	while(T--){
		cin >> a;
        
        FOR1(i,a){
            cin >> v[i];
        }
        solve();
	}

	return 0;
}