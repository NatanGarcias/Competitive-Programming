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
#define MAXN 110

ll T,N,M,K;

int v[MAXN];
int h[MAXN];

void solve(){

}

int main(){

	cin >> N;

 	FOR(i,0,N){
 		FOR(j,0,N){
 			char k;
 			cin >> k;
 			if(k == 'C'){
 				h[i]++;
 				v[j]++;
 			}
 		}
 	}

 	int ans = 0;
 	
 	FOR(i,0,N){
 		if(h[i] > 1) ans+= (h[i]*(h[i]-1))/2;
 		if(v[i] > 1) ans+= (v[i]*(v[i]-1))/2;
 	}

 	cout << ans << endl;
	return 0;
}