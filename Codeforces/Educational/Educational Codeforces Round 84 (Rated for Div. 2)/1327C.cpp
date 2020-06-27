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

int T,N,M,K;
vector<char> sol;
pii maior;

void imprimi(){
	cout << sz(sol) << endl;
	FOR(i,sz(sol)){
		cout << sol[i];
	}
	cout << endl;
}
void solve(){

	while(maior.fi > 1){
		sol.pb('U');
		maior.fi--;
	}

	while(maior.se > 1){
		sol.pb('L');
		maior.se--;
	}

	FOR(i,M){
		if(!(i%2)){
			while(maior.se < N){
				sol.pb('R');
				maior.se++;
			}

			if(i < M-1){
				maior.fi++;
				sol.pb('D');
			}
		}else{
			while(maior.se > 1){
				sol.pb('L');
				maior.se--;
			}

			if(i < M-1){
				maior.fi++;
				sol.pb('D');
			}
		}
	}

	imprimi();
}

int main(){

	cin >> N >> M >> K;
	
	swap(N,M);
	
	int a,b;

	maior = pii(-1,-1);
    FOR(i,K){
        cin >> a >> b;
        
		if( a > maior.fi){
			maior.fi = a;
		}

		if( b > maior.se){
			maior.se = b;
		}
    }

    FOR(i,K){
        cin >> a >> b;
    }

    solve();

	return 0;
}