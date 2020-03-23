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

#define mod %998244353

#define MAXN 200010

int T,N,M;
pii v[MAXN];

int main(){
    
	cin >> N >> M;

	FOR(i,N){
        cin >> v[i].fi;

        v[i].se = i;
	}

    sort(v,v+N);
    reverse(v,v+N);

    vector<int> pos;

    ll cont = 0;
    
    FOR(i,M){
        cont += v[i].fi;
        pos.pb(v[i].se);
    }
    
    sort(all(pos));

    ll ans = 1;
    FOR(i,sz(pos)-1){
        ans = (ans * (pos[i+1] - pos[i])) mod;
    }

    cout << cont << " " << ans << endl;

	return 0;
}