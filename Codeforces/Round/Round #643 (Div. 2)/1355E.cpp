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
ll T,N,M,K,A,R;
vector<ll> v;
ll pre[MAXN];

ll f(ll h){
    int p = upper_bound( all(v), h) - v.begin();

    ll falta = (p*h) - pre[p];

    ll sobra = pre[N] - (pre[p] + ( (N - p) *h) );

    ll aux = abs(sobra - falta);

    if(sobra <= falta)
        return A*aux + M * min(sobra,falta);
    else
        return R*aux + M * min(sobra,falta);
}

ll bt(){
    ll l = v[0], r = v[N-1];

    while(r - l > 1){
        ll m1 = l + (r-l)/3.0;
        ll m2 = r - (r-l)/3.0;

        ll f1 = f(m1);
        ll f2 = f(m2);

        if(f1 < f2)
            r = m2 - 1;
        else
            l = m1 + 1;
    }

    return min(f(l), f(r));
}

void solve(){

    sort(all(v));

    M = min(M,A+R);

    pre[0] = 0;
    for(int i=1;i<=N;i++) pre[i] = v[i-1] + pre[i-1];

    cout << bt() << endl;
}

int main(){

	optimize;
	
	cin >> N >> A >> R >> M;

    v.resize(N);
    
    for(int i=0;i<N;i++)
        cin >> v[i];

	solve();

	return 0;
}