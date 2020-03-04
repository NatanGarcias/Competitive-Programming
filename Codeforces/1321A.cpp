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
#define MAXM 2029
#define MAXL 20

ll N,M,T;

int v[MAXN];
int v2[MAXN];

int main(){

	int cont = 0, cont2 = 0;
	cin >> T;

	FOR(i,T){
		cin >> v[i];
	}

	FOR(i,T){
		cin >> v2[i];
	}

	FOR(i,T){
		if(v[i] == 1 && v2[i]== 0){
			cont++;
		}else if(v[i] == 0 && v2[i]== 1){
			cont2++;
		}
	}

	if(cont == 0){
		cout << -1 << endl;
		return 0;
	}
	cout << (int) (cont2/cont)+1 << endl;

	return 0;
}