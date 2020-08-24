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

#define mod 998244353LL
#define MAXN 1010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;

set<string> s;
int v[MAXN];

void solve(){

    ll ans = 0;

    int p = 0;


    for(auto i : s) v[p++] = i.size();

    sort(v,v+p);

    ll cont = 0;

    while(ans < p && cont + v[ans] <= N){
        cont += v[ans] + 1;
        ans++;
    }

    cout << ans << endl;
}

int main(){

    optimize;
	
	cin >> N >> M;
		
    FOR(i,0,M){
        string st;

        cin >> st;
        
        s.insert(st);
    }

	solve();

	return 0;
}