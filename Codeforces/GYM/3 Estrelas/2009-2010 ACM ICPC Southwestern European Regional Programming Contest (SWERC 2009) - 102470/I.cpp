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
pii v[MAXN];
int ans[MAXN];

int main(){

	optimize;
	
	while(cin >> N >> M){
        if(!N && !M) break;

        ms(ans, 0);

        FOR(i,0,N){
            int a,b,c,d;

            cin >> a >> b >> c >> d;
       
            v[i].fi = c;
            v[i].se = c+d-1;
        }	

        FOR(i,0,M){
            int a,b;

            cin >> a >> b;

            b = a+b-1;

            FOR(j,0,N)
                if(! (b < v[j].fi || a > v[j].se) )
                    ans[i]++;
        }

        FOR(i,0,M) cout << ans[i] << "\n";

    }

    return 0;
}