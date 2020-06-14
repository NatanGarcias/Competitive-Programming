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

#define mod 1000000007
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;

void solve(){

    ll ans = 1;

    ll menor = K, maior = K;

    FOR(i,0,M){
        ll a,b;
        cin >> a >> b;
        
        if(a >= menor && b <= maior) continue;
        if(a <= menor && b >= maior){
            ans += abs(a-menor);
            menor = min(a,menor);
            ans += abs(b-maior);
            maior = max(b,maior);
        }
        else if(a <= menor && b >= menor){
            ans += abs(a-menor);
            menor = min(a,menor);
        }else if(a <= maior && b >= maior){
            ans += abs(b-maior);
            maior = max(b,maior);
        }
    }

    cout << ans << endl;
}

int main(){

	cin >> T;

    while(T--){
		cin >> N >> K >> M;
		
		solve();
    }

	return 0;
}