#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld; 

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define endl "\n"
#define space " " 

#define pii pair<ll,ll>
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

int N,T,C;

struct Cliente{
    ll m,ti,tf;
};

int main(){

    optimize;

    cin >> N;

    while(N--){
        cin >> C >> T;

        vector<Cliente> c(C);

        FOR(i,C){
            cin >> c[i].m >> c[i].ti >> c[i].tf;
        } 

        pii tm = (make_pair(T,T));
        ll tempo = 0;
        bool ans = true;

        FOR(i,C){
            if(c[i].tf < tm.fi - (c[i].m-tempo) || c[i].ti > tm.se + (c[i].m-tempo)){
                ans = false;
                break;
            }

            tm.fi = max(tm.fi - (c[i].m-tempo), c[i].ti );
            tm.se = min(tm.se + (c[i].m-tempo), c[i].tf );
            tempo = c[i].m;
        }

        if(ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}