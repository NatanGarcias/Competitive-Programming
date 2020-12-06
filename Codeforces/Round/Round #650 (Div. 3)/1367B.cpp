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
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
int v[MAXN];

void solve(){

    int p = 0;

    for(int i=0;i<N;i++) if(! (v[i] & 1) ) p++;

    if(p != (N+1)/2) {
        cout << "-1\n";
        return;
    } 

    int ans = 0;
    for(int i=0;i<N;i+=2){
        if(v[i] & 1) ans++;
    }

    cout << ans << endl;
}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
		cin >> N;

        for(int i=0;i<N;i++) cin >> v[i];
		
		solve();
    }

	return 0;
}