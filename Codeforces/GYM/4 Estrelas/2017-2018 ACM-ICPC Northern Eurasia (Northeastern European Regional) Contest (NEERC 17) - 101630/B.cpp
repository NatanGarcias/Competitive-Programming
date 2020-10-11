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
ll nums[3];

void yes(){
    cout << "Yes\n";
    exit(0);
}

void no(){
    cout << "No\n";
    exit(0);
}

bool f(){
    
    if( 2LL * nums[0] + 2LL * nums[1] <= N && 2LL * nums[0] + nums[2] <= M) return true;
    if( 2LL * nums[0] + 2LL * nums[1] <= M && 2LL * nums[0] + nums[2] <= N) return true;
    if( 3LL * nums[0] + nums[1] + nums[2] <= N && nums[1] + nums[2] <= M) return true;
    if( 3LL * nums[0] + nums[1] + nums[2] <= M && nums[1] + nums[2] <= N) return true;

    return false;
}

void solve(){

    sort(nums,nums+3);

    do{
        if( f() ) yes();
    }while(next_permutation(nums,nums+3));

    no();
}

int main(){

	cin >> nums[0] >> nums[1] >> nums[2] >> N >> M; 
		
	solve();

	return 0;
}