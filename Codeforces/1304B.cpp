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
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()

#define PI 3.141592653589793238462643383279502884
#define FOR(x,n) for(int x=0;(x) < int(n);(x)++)
#define FOR1(x,n) for(int x=1;(x) <= int(n);(x)++)

#define INF 0x7fffffff
#define INFLL 0x7fffffffffffffff

#define mod %1000000007

#define MAXN 500

int n,m;
vector<string> v;
bool vis[MAXN];

bool palindromo(string &a){
    
    for(int i=0;i<a.size()/2;i++){
        if(a[i] != a[a.size()-1-i]){
            return false;
        }
    }
    return true;
}

bool inversas(string &a, string &b){
    
    for(int i=0;i<a.size();i++){ 
        if(a[i] != b[a.size()-i-1]){
            return false;
        }
    }
    return true;
}

void solve(){

    vector<string> sol;
    string palin = "";

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(!vis[i] && !vis[j] && inversas(v[i],v[j])){
                vis[i] = true;
                vis[j] = true;
                sol.push_back(v[i]);
                sol.push_back(v[j]);
            }
        }
    }

    for(int i=0;i<n;i++){
        if(!vis[i] && palindromo(v[i])){
            palin = v[i];
            break;
        }
    }

    if(sol.size() == 0 && palin.empty()){
        cout << 0 << endl;
    }else{
        cout << sol.size()*m + palin.size() << endl;
        for(int i=0;i<sol.size();i+=2){
            cout << sol[i];
        }
        cout << palin;
        for(int i=sol.size()-1;i>=1;i-=2){
            cout << sol[i];
        }
    }
    cout << endl;
}

int main(){

    optimize;

    cin >> n >> m;

    v.clear();
    v.resize(n);
    memset(vis,0,sizeof(vis));

    FOR(i,n){
        cin >> v[i];
    } 

    solve();

    return 0;
}