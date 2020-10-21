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
#define MAXN 110

int T,N,M;
char v[MAXN][MAXN];
void solve(){

	ms(v,0);
	if(N == 2 && M == 2){
		cout << "BW\nBB\n"; 
	}else{

		if(N==2){
			FOR(j,0,2){
				v[0][j] = 'W';
			}
		}else{
			FOR(i,0,2){
				v[i][M-1] = 'W';
			}
		}
		FOR(i,0,N){
			FOR(j,0,M){
				if(v[i][j] == 'W'){
					cout << 'W';
				}else{
					cout << 'B';
				}
			}
			cout << endl;
		}
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