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

void solve(){

    vector<pii> ans;

    if(N == M){
        for(int i=0;i<=N;i++) {
            ans.pb({i,N-i});
        }
    }
    else{
        int x = 0, y = 0;
    
        if(N>=M) x = 1;
        else y = 1;

        FOR(i,0,min(N,M)+1){
            ans.pb(pii(i+x,i+y));
        }
    }
    
    K = ans.size();

    cout << K << endl;
    FOR(i,0,K) cout << ans[i].fi << " " << ans[i].se << endl;
}

int main(){

	cin >> N >> M;

	solve();

	return 0;
}