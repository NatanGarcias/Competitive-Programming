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

#define PI 3.141592653589793238462643383279502884
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;

void solve(){
    
    vector<int> ans;

    if(M){
        ans.pb(2);
        M--; 
    }

    if(K){
        ans.pb(1);
        K--; 
    }
    
    while(M>0){
        ans.pb(2);
        M--;
    }

    while(K>0){
        ans.pb(1);
        K--;
    }

    FOR(i,0,sz(ans)) cout << ans[i] << " \n"[i==sz(ans)-1];
}

int main(){

	cin >> N;

	FOR(i,0,N){
        int a;
        cin >> a;

        if(a == 2) M++;
        else K++;
    }

	solve();

	return 0;
}