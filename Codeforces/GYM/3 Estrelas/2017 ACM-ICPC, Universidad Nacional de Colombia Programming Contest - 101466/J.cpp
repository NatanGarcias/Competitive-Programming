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

#define mod 30000000LL
#define MAXN 30000010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;

int v[MAXN], nums[MAXN], prefix[MAXN];

const int LIM = 30000000;

int main(){

	optimize;
	
	cin >> N >> M >> K;
    
    for(int i=0;i<M;i++){
        cin >> v[i];
        nums[v[i]]++;
    }

    for(int i=0;i<N-M;i++){
        v[M+i] = (v[i] + v[i+1]) % mod;
        nums[v[M+i]]++;
    }

    for(int i=0;i<=LIM;i++){
        if(!i) prefix[i] = nums[i];
        else prefix[i] = prefix[i-1] + nums[i];
    }   

    for(int i=0;i<K;i++){
        int q;

        cin >> q;

        int ans = lower_bound(prefix,prefix+LIM+1, q) - prefix;

        cout << ans << endl;
    }
    
	return 0;
}