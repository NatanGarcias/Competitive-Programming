#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
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

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007
#define MAXN 200010

ll T,N,M;

void imprimi(int caso, vector<pii> &sol){
	cout << "Case #" << caso << ": " << endl;
	FOR(i,0,sz(sol)){
		cout << sol[i].fi << " " << sol[i].se << endl;
	}
}

void solve(int caso){
	
	vector<pii> sol;

	int bitEsq = 0;

	for(int i = 30; i >= 0; i--){
		if( N & (1 << i) ){
			bitEsq = i;   
			break;
		}
	}

	int aux = N - (1 << bitEsq);

	bool indo = true;
	int alt = 1;


	if(aux >= bitEsq){
		
		int n = N - bitEsq;

		int cont = 0;

		for(int i=1; i<= bitEsq+1; i++){
			if( n & (1 << (i-1))){
				
				cont++;

				if(indo){
					for(int j= 1; j <= i;j++){
						sol.pb(pii(i,j));
					}
				}else{
					for(int j = i ; j>= 1; j--){
						sol.pb(pii(i,j));
					}
				}
				indo = indo^1;
			}else{
				if(indo){
					sol.pb(pii(i,1));
				}else{
					sol.pb(pii(i,i));
				}
			}	
		}
		alt = bitEsq +1;

		for(int i=1;i<cont;i++){
			if(!indo){
			sol.pb(pii(alt+i,alt+i));
			}else{
				sol.pb(pii(alt+i,1));
			}
		}
	}else{
		for(int i=1; i<= bitEsq; i++){
			if(indo){
				for(int j= 1; j <= i;j++){
					sol.pb(pii(i,j));
				}
				indo = indo^1;
			}else{
				for(int j = i ; j>= 1; j--){
					sol.pb(pii(i,j));
				}
				indo = indo^1;
			}
		}
		
		int n = N - ((1 << bitEsq) -1);
		
		alt = bitEsq;
		
		for(int i=1;i<=n;i++){
			if(!indo){
				sol.pb(pii(alt+i,alt+i));
			}else{
				sol.pb(pii(alt+i,1));
			}
		}
	}

	imprimi(caso,sol);
}

int main(){

	cin >> T;

    FOR(i,1,T+1){
		cin >> N;
		solve(i);
    }

	return 0;
}