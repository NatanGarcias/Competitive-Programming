#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
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

ull T,N,M;

int main(){

	cin >> N >> M;
	
	if(N > M || (M%2 != N%2) ){
		cout << -1 << endl;
	}else if(N == M && M == 0){
		cout << N << endl;
	}else if(N == M){
		cout << 1 << endl;
		cout << N << endl;
	}else if( (N & ((M-N)/2)) == 0){
		cout << 2 << endl;
		cout << N+((M-N)/2) << " " << ((M-N)/2) << endl;
	}else{
		cout << 3 << endl;
		cout << N << " " << ((M-N)/2) << " " << ((M-N)/2) << endl;
	}

	return 0;
}