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
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 1123456

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K,A,B;

ld pre[MAXN], nums[MAXN];

ld query(int l, int r){
    return pre[r] - pre[l]; 
}

void solve(){

    pre[0] = 0.0;
    nums[0] = 0.0;

    ld L = B - A + 1;

    for(int i=1;i<=N;i++){

        nums[i] = 1.0 + query( max(0LL, i-B-1) , max(0LL, min(i-A, i-1LL) ) );

        if(!A) nums[i] = nums[i] * (L / ((L-1)*1.0));

        pre[i] = pre[i-1] + ( 1.0/ (L*1.0) ) * nums[i];
    }    

    cout << fixed << setprecision(8) << nums[N] << endl;
}

int main(){

	optimize;
	
	cin >> N >> A >> B;
		
	solve();

	return 0;
}