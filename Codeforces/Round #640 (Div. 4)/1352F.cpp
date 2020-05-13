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
    vector<int> ans;

    if(N == 0 && M == 0){
        FOR(i,0,K+1) ans.pb(1);
    }else if(N == 0 && K == 0){
        ans.pb(1);
        FOR(i,0,M) ans.pb( ans[ans.size()-1] ^ 1);
    }else if(M == 0 && K == 0){
        FOR(i,0,N+1) ans.pb(0);
    }else if(N == 0){

        if(K>0) FOR(i,0,K+1) ans.pb(1);
        
        FOR(i,0,M) ans.pb( ans[ans.size()-1] ^ 1);
    
    }else if(K == 0){
        
        if(N>0) FOR(i,0,N+1) ans.pb(0);
        
        FOR(i,0,M) ans.pb( ans[ans.size()-1] ^ 1);
        
    }else {
        if(M&1){
            ans.pb(0);

            FOR(i,0,M-1){
                ans.pb( ans[ans.size()-1] ^ 1);
            }
        }else{
            ans.pb(1);

            FOR(i,0,M-1){
                ans.pb( ans[ans.size()-1] ^ 1);
            }
        }
        
        FOR(i,0,N) ans.pb(0);
        FOR(i,0,K+1) ans.pb(1);
    }

    for(auto i : ans) cout << i;
    cout << endl;
}

int main(){

	cin >> T;

    while(T--){
		cin >> N >> M >> K;
		solve();
    }

	return 0;
}