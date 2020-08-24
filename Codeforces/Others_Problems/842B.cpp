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
ll T,N,M,K,X,Y;
int R,D;

struct Circle{
    int x,y,r;
};

Circle C[MAXN];

ld dist(ld x, ld y, ld x2, ld y2){
    return (x-x2)*(x-x2) + (y-y2)*(y-y2);
}

void solve(){

    int ans = 0;

    FOR(i,0,N){ 
        if(dist(C[i].x, C[i].y, 0.0, 0.0)  >= (R-D+C[i].r)*(R-D+C[i].r)){
            if(dist(C[i].x, C[i].y, 0.0, 0.0 ) <= (R -C[i].r)*(R -C[i].r)){
                ans++;
            }
        }
        
    }
    
    cout << ans << endl;
}

int main(){

    cin >> R >> D >> N;

    FOR(i,0,N) cin >> C[i].x >> C[i].y >> C[i].r;

    solve();

    return 0;
}