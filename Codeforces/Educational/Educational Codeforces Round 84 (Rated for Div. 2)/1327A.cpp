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

int T,N,M;

bool solve(){
    int cont = 0;
    int ans = 0;
    while(++cont <= M){
        ans += (2 * (cont-1))+1;
        if(ans >N){
            return false;
        }
    }

    return true;
}
int main(){

	cin >> T;

	while(T--){
        cin >> N >> M;

        if(N%2 && M%2 && solve()){
            cout << "YES" << endl;
        }else if(N%2){
            cout << "NO" << endl;
        }else if( !(N%2) && !(M%2) && solve() ){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
	}

	return 0;
}