#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

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

vector<vector<int>> adj;

int query(int a, int b){
    cout << "? " << a << " " << b << endl;

    char k;
     
    cin >> k;

    if(k == '>') return 1;
    if(k == '<') return -1;
    return 0;
}

void solve(){

    vector<int> nums, nums2;

    FOR(i,0,N) nums.pb(i+1);

    while(nums.size() >= 2){

        for(int i=1;i<nums.size();i+=2){
            int aux = query(nums[i-1],nums[i]);

            if(aux > 0){ 
                adj[nums[i-1]].pb(nums[i]);
                nums2.pb(nums[i-1]);
            }
            else if(aux < 0){
                adj[nums[i]].pb(nums[i-1]);
                nums2.pb(nums[i]);
            }
        
        }

        if( ((int)nums.size()) & 1) nums2.pb(nums[nums.size()-1]);
        nums = nums2;
        nums2.clear();
    }

    int a = adj[nums[0]][0];

    for(int i=1;i<adj[nums[0]].size();i++){
        int aux = query(a,adj[nums[0]][i]);

        if(aux < 0) a = adj[nums[0]][i];
    }

    cout << "! " << a << endl;

}

int main(){

    cin >> N;

    adj.resize(N+1);

	solve();

	return 0;
}