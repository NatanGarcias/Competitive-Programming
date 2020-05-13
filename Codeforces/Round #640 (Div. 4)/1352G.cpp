#include<bits/stdc++.h>
using namespace std;

// Template 1
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
#define MAXN 8010

ll T,N,M,K;

void solve(){
    if(N < 4){
        cout << -1 << endl;
        return;
    }

    vector<int> ans;

    if(N&1){
        for(int i=1;i<=N;i+=2){
            ans.pb(i);
        }
        ans.pb(N-3);
        ans.pb(N-1);

        for(int i=N-5;i>=1;i-=2){
            ans.pb(i);
        }
    }else{
        for(int i=2;i<=N;i+=2){
            ans.pb(i);
        }
        ans.pb(N-3);
        ans.pb(N-1);

        for(int i=N-5;i>=1;i-=2){
            ans.pb(i);
        }
    }

    FOR(i,0,sz(ans)) cout << ans[i] << " \n"[i==sz(ans)-1];
}

int main(){

	cin >> T;

    while(T--){
		cin >> N;
		solve();
    }

	return 0;
}