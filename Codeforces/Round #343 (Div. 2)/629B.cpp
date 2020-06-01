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
#define MAXN 370

ll T,N,K;

int m[MAXN];
int f[MAXN];

vector<pii> M;
vector<pii> F;

void solve(){

	FOR(i,0,sz(M)){
		m[ M[i].fi]++;
		m[ M[i].se +1]--;
	}

	FOR(i,0,sz(F)){
		f[ F[i].fi]++;
		f[ F[i].se +1]--;
	}

	int ans = 0;
	int sumM = 0;
	int sumF = 0;

	FOR(i,0,367){
		sumM += m[i];
		sumF += f[i];

		ans = max( ans , 2*min(sumM,sumF) );
	}
	cout << ans << endl;
}

int main(){

	cin >> T;

    FOR(i,0,T){
    	char k;
    	int a,b;

    	cin >> k >> a >> b;

    	if(k == 'M'){
    		M.pb(pii(a,b));
    	}else{
    		F.pb(pii(a,b));
    	}
    }

    solve();

	return 0;
}