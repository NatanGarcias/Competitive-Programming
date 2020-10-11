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
#define MAXN 1010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
int nums[MAXN];

void yes(vector<int> &ans){

    cout << "Yes\n";
    for(int i=0;i<ans.size();i++) cout << ans[i] << " \n"[i==ans.size()-1];
    exit(0);
}

void no(){
    cout << "No\n";
    exit(0);
}

void solve(){

    int t = 0;
    vector<int> ans;

    for(int i=0;i<N;i++){
        int a;

        cin >> a;

        if(a > 0){
            nums[a]++;
        }
        else if(!a){
            t++;
        }
        else{
            if( nums[-a] ) nums[-a]--;
            else if( t ){
                ans.push_back(-a);
                t--;
            }
            else no();
        }
    }

    while(t--) ans.pb(500);

    yes(ans);
}

int main(){

	optimize;
	
	cin >> N;
    
	solve();
    
	return 0;
}