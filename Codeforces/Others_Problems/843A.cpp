#include<bits/stdc++.h>
using namespace std;

// Template 1
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
#define MAXN 200010

ll T,N,M;
int v[MAXN];
bool vis[MAXN];

vector<vector<int>> ans;

void dfs(int x){
    vector<int> nums;

    nums.pb(x);

    vis[x] = true;

    stack<int> fila;
    fila.push(x);

    while(!fila.empty()){
        int u = fila.top();
        fila.pop();

        if(!vis[ v[u] ]){
            vis[ v[u] ] = true;
            fila.push(v[u]);
            nums.push_back(v[u]);
        }
    }

    ans.pb(nums);
}

void solve(){

    FOR(i,1,N+1){
        if(!vis[i]) dfs(i);
    }

    cout << ans.size() << endl;

    FOR(i,0,ans.size()){
        cout << ans[i].size() << " ";
        
        FOR(j,0,sz(ans[i])-1)   cout << ans[i][j] << " ";
    
        cout << ans[i][sz(ans[i])-1] << endl;
    }
}

int main(){

	cin >> N;

    pii v2[N+1];

    FOR(i,1,N+1){
        cin >> v[i];
        v2[i].fi = v[i];
        v2[i].se = i;
    }

    sort(v2+1, v2+N+1);

    FOR(i,1,N+1){
        v[i] = v2[i].se;
    }

    solve();

	return 0;
}