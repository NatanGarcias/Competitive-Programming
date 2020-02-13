#include<bits/stdc++.h>
using namespace std;

#define FOR(x,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define INF 0x3f3f3f3f
#define endl "\n"
#define space " "
#define MAXN 200010

typedef long long ll;

ll n,a,b,k;
int v[MAXN];


int main(){

    cin >> n >> a >> b >> k;

    FOR(i,n){
        cin >> v[i];
        if(!(v[i] % (a+b))){
            v[i] = a+b;
        }else{
            v[i]%= (a+b);
        }
    }

    FOR(i,n){
        v[i] = ((v[i]+a-1)/a) - 1;
    }

    sort(v,v+n);

    int ans = 0;

    FOR(i,n){
        if(k>=v[i]){
            ans++;
            k-=v[i];
        }else{
            break;
        }
    }
    
    cout << ans << endl;
}