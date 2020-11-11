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

#define mod 1000000007LL
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
int v[MAXN];

void solve(){

	vector<pii> par,impar;

    FOR(i,0,2*N){
        if(v[i] &1) impar.pb(pii(v[i],i));
        else par.pb(pii(v[i],i));
    }

    vector<pii> ans;

    for(int i=0;i<sz(impar)-1;i+=2){
        ans.pb(pii(impar[i].se+1,impar[i+1].se+1));
    }

    for(int i=0;i<sz(par)-1;i+=2){
        ans.pb(pii(par[i].se+1,par[i+1].se+1));
    }
    
    FOR(i,0,N-1) cout << ans[i].fi << " " << ans[i].se << endl;
}

int main(){

	cin >> T;

    while(T--){
		cin >> N;

        FOR(i,0,2*N) cin >> v[i];
		
		solve();
    }

	return 0;
}