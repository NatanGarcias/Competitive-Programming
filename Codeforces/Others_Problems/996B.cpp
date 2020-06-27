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
#define MAXN 100010

int v[MAXN];

int main(){

    int n;

    cin >> n;

    FOR(i,n){
        cin >> v[i];
    }    

    int pos = -1;
    int valor = 0;

    while(true){
        pos++;
        if(pos == n)
            pos = 0;

        if(v[pos] <= valor){
            cout << pos+1 << endl;
            return 0;
        }

        valor++;
    }
    
    return 0;
}