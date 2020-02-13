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
#define MAXN 200010

vector<ll> v(MAXN);

int binarySearch(ll x){

    int l = 0, r = sz(v)-1;

    while(true){
        int m = (l+r+1)/2;
        if(l == r){
            return m;
        }
        else if(v[m] < x){
            l = m;
        }else{
            r = m-1;
        }
    } 
}

int main(){

    int a,b;

    cin >> a >> b;

    v.clear();
    v.resize(a+1);

    v[0] = 0;

    ll aux;

    FOR1(i,a){
        cin >> aux;
        v[i] = v[i-1]+aux;
    }

    FOR(i,b){
        cin >> aux;

        ll temp = binarySearch(aux)+1;

        cout << temp << space << aux - v[temp-1] << endl;        
    }

    return 0;
}