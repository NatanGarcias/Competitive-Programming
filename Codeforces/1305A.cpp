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

int T,N,M;

int v[MAXM];
int v2[MAXM];

void solve(){

}

int main(){

	cin >> T;

	while(T--){
		cin >> N;

		ms(v);
		ms(v2);

		FOR(i,N){
			cin >> v[i];
		}

		FOR(i,N){
			cin >> v2[i];
		}

		sort(v,v+N);
		sort(v2,v2+N);


		FOR(i,N){
			cout << v[i] << " \n"[i==N-1];
		}

		FOR(i,N){
			cout << v2[i] << " \n"[i==N-1];
		}
	}	
	return 0;
}