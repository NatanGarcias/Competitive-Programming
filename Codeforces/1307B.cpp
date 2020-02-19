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
#define ms(x) memset(x,0,sizeof(x))

#define PI 3.141592653589793238462643383279502884
#define FOR(x,n) for(int x=0;(x) < int(n);(x)++)
#define FOR1(x,n) for(int x=1;(x) <= int(n);(x)++)

#define INF 0x3fffffff
#define INFLL 0x3fffffffffffffff

#define mod %1000000007
#define MAXN 200010

int v[MAXN];

int main(){

    int t,n,m;

    cin >> t;

    while(t--){
        cin >> n >> m;
        ms(v);

        bool resp = false;

        FOR(i,n){
            cin >> v[i];
            if(v[i] == m){
                resp = true;
            }
        }

        if(resp){
            cout << 1 << endl;
            continue;
        }

        sort(v,v+n);

        int ans = 0;
        int onde = n-1;

        if(m < v[onde]){
            cout << 2 << endl;
            continue;
        }else{
            if(m>=v[onde]){
                int aux = m/v[onde];
                m-=aux*v[onde];
                ans+= aux;
            }
            if(m>0){
                ans++;
            }
            cout << ans << endl;
        }
    }

  	return 0;
}