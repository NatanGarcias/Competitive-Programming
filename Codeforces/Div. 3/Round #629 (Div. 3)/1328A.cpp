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

#define FOR(x,a,n) for(int x= (int)(a);(x) < int(n);(x)++)
#define ms(x,a) memset(x,a,sizeof(x))

#define PI 3.141592653589793238462643383279502884
#define INF 0x33ffffff
#define INFLL 0x33ffffffffffffff

#define mod %1000000007

#define MAXN 200010

int T,N,M;

void solve(){
    int a = N%M;

    if( a == 0){
        cout << 0 << endl;
    }
    else{
        cout << M - a <<  endl;
    }
}

int main(){

	cin >> T;

	while(T--){
		cin >> N >> M;		
        solve();                
	}

	return 0;
}