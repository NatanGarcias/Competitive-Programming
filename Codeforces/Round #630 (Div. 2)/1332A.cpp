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
ll a,b,c,d,x,y, y3 ,y2,x1,x2;

void solve(){
	if(y3 == y2 && (d>0 || c>0)){
		cout << "No\n";
	}else if(x1 == x2 && (a>0 || b>0)){
		cout << "No\n";	
	}else if( (a-b)> 0 && (x - x1) < a-b ){
		cout << "No\n";	
	}else if( (b-a)> 0 && (x2 - x) < b-a ){
		cout << "No\n";	
	}else if( (c-d)> 0 && (y - y3) < c-d ){
		cout << "No\n";	
	}else if( (d-c)> 0 && (y2 - y) < d-c ){
		cout << "No\n";	
	}else{
		cout << "Yes\n";
	}
}

int main(){

	cin >> T;

    while(T--){
		cin >> a >> b >> c >> d;
		cin >> x >> y >> x1 >> y3 >> x2 >> y2;
		solve();
    }
	return 0;
}