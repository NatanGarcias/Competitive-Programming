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

int N,M,T;
int a,b,x,y;

int solve(){
	
	int c = a * y;
	int d = b * x;

	int e = (a-x-1)*(b);
	int f = (a)*(b-y-1);

	
	return max({c,d,e,f});
	
}

int main(){

	cin >> T;

	while(T--){
		cin >> a >> b >> x >> y;

		cout << solve() << endl;
	}

	return 0;
}