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

int p[3] = {2, 3, 5};
int d[2][3], v[2], nums[2];

void solve(){

    for(int i=0;i<2;i++){
        int aux = v[i];

        for(int j=0;j<3;j++){
            while( !(aux % p[j]) ){
                d[i][j]++;
                aux/= p[j];
            }
        }

        nums[i] = aux;
    }

    if(nums[0] != nums[1]) cout << -1 << endl;
    else{
        int ans = 0;

        for(int j=0;j<3;j++) ans += abs(d[0][j] - d[1][j]);
        
        cout << ans << endl;
    }
}

int main(){

	optimize;
	
    for(int i=0;i<2;i++) cin >> v[i];
		
	solve();
    
	return 0;
}