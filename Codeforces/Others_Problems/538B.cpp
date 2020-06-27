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
#define MAXN 100010

ll T,N,M,K,A,B,C;
ll v[MAXN];

void solve(){

	vector<int> ans;

	while(N>0){
		int aux = N;
		int temp = 0;
		int cont = 1;
		while(aux>0){
			int aux2 = aux%10;
			if(aux2) temp += 1*(cont);
			cont *=10;
			aux = aux/10;
		}
		ans.pb(temp);
		N -= temp;
	}

	cout << ans.size() << endl;
	FOR(i,0,sz(ans)) cout << ans[i] << " \n"[i==sz(ans)-1];

}

int main(){

    cin >> N;

    solve();

	return 0;
}