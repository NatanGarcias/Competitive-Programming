#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld; 

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

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

ll T,X,Y;

bool venci(ll X, ll Y){
	if( X == 0 && Y == 0) return true;
	else return false;
}

void solve(int caso){

	if(venci(X,Y)){
		cout << "Case #" << caso << ": " << endl;
		return;
	}else if ( ((X & 1) && (Y & 1)) || (!(X & 1) && !(Y & 1)) ){
		cout << "Case #" << caso << ": IMPOSSIBLE" << endl;
		return;
	}

	string ans;

	while(true){

		if( X & 1){
			ll x = X, y = Y;

			if( venci(x-1,y)){
				ans.pb('E');
				break;
			}else if(venci(x+1,y)){
				ans.pb('W');
				break;
			}else if(  (((x-1)/2) & 1) ^ ((y/2) & 1)){
				ans.pb('E');
				X = (x-1)/2;
				Y = y/2;
			} else{
				ans.pb('W');
				X = (x+1)/2;
				Y = y/2;
			}

		}else if( Y & 1){
			ll x = X, y = Y;

			if( venci(x,y-1)){
				ans.pb('N');
				break;
			}else if(venci(x,y+1)){
				ans.pb('S');
				break;
			}else if(  ((x/2) & 1) ^ (((y-1)/2) & 1)){
				ans.pb('N');
				X = x/2;
				Y = (y-1)/2;
			} else{
				ans.pb('S');
				X = x/2;
				Y = (y+1)/2;
			}
		}
	}

	cout << "Case #" << caso << ": " << ans << endl;
}

int main(){

	cin >> T;

    FOR(i,1,T+1){
		cin >> X >> Y;
		
		solve(i);
    }

	return 0;
}