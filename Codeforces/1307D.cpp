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

int n, m ,k;
int a,b;

bool v[MAXN];
int dist[MAXN];
int dist2[MAXN];

vector<vector<int>> adj(MAXN);
vector<int> esp;

void bfs(int d[],int x){

    v[x] = true;
    d[x] = 0;
    
    queue<pii> fila;

    fila.push({x,1});

    while(fila.size()){
        pii u = fila.front();
        fila.pop();

        for(int i=0;i<adj[u.fi].size();i++){
            int aux = adj[u.fi][i];
            if(!v[aux]){
                d[aux] = u.se;
                v[aux] = true;
                fila.push(make_pair(aux,u.se+1));
            }
        }
    }
}

void solve(){
    
    bfs(dist,0);

    ms(v);

    bfs(dist2,n-1);

    vector<pii> nums;

    FOR(i,sz(esp)){
        nums.push_back({dist[esp[i]] , esp[i]});    
    }

    sort(all(nums));

    int ans = -1;

    FOR(i,sz(nums)-1){
        int aux = dist[nums[i].se] + dist2[nums[i+1].se] + 1;
        ans = max(ans, aux);
    }

    ans = min(ans,dist[n-1]);

    cout << ans << endl;
}
int main(){

    cin >> n >> m >> k;
    
    FOR(i,k){
        cin >> a;
        esp.push_back(a-1);
    }

    FOR(i,m){
        cin >> a >> b;
        
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    solve();

  	return 0;
}