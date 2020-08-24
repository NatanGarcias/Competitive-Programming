#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

#define fi first 
#define se second 
#define pb push_back

#define sz(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define FOR(x,a,n) for(int x= (int)(a);(x) < int(n);(x)++)
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 998244353LL
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;

void solve(){

    int v[4] = {2,3,15,10};
    int v2[4] = {1,2,1,2};

    vector<int> ans, grupo;

    int g = 0;

    FOR(i,0,K*4){
        ans.pb( pow(v[(i/K)], (i%K)+1 ) );
    }

    FOR(i,0,K*2){
        grupo.pb(i+1);
    }

    FOR(i,0,K*2){
        grupo.pb(i+1);
    }

    cout << ans.size() << " " << ans.size()/2 << "\n";
    FOR(i,0,K*4) cout << ans[i] << " \n"[i==K*4-1];
    FOR(i,0,K*4) cout << grupo[i] << " \n"[i==K*4-1];
}

int main(){

	optimize;
	
	cin >> K;

	solve();
    
	return 0;
}