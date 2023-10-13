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

ll T,N,M;
int v[MAXN];
bool vis[MAXN];

void solve(){

    ms(vis,0);

    FOR(i,0,N){
        int sum = 0;

        sum += v[i];
        FOR(j,i+1,N){
            sum += v[j];

            if(sum < 8005){
                vis[sum] = true;
            }
        }
    }

    int ans = 0;

    FOR(i,0,N){
        if(vis[v[i]]) ans++;
    }
    cout << ans << endl;
}

int main(){

    optimize;

	cin >> T;

    while(T--){
		cin >> N;
    
        int aux = 0;

        FOR(i,0,N) cin >> v[i];

		solve();
    }

	return 0;
}