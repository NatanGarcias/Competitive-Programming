#include<bits/stdc++.h>
using namespace std;

#define FOR(x,n) for(int x=0;x<n;x++)
#define ms(x) memset(x,0,sizeof(x))
#define MAXN 10010

int v[MAXN];
int n;

#define ll long long 

ll LCS(){

    ll ans = 0;
    ll temp = 0;
    for(int i=0;i<n;i++){
        temp += v[i];
        
        if(temp < 0) temp = 0;
        
        ans = max(temp,ans);
        
    }
    return ans;
}

int main(){

    while(cin >> n){
        if(n == 0) return 0;
        ms(v);  
        FOR(i,n){
            cin >> v[i];
        }

        ll ans = LCS();

        if(ans>0){
            cout << "The maximum winning streak is " << ans << ".\n";
        }else{
            cout << "Losing streak.\n";
        } 
    }
    return 0;
}