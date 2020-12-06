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
#define MAXN 55

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K,A,B;

ll c[MAXN], ans;

ll comb(ll n , ll k){

    if(k > n) return 0LL;

    ll r = min(k,n-k);
    
    ll x = 1, y = 1;

    if(!r) return 1;

    while(r){
        x *= n;
        y *= r;

        ll aux = __gcd(x,y);

        x /= aux;
        y /= aux;

        n--;
        r--;
    }
    
    return x;
}

ll solve(ll i, ll q, ll peso){

    if(q == K) return 1LL;
    if(i == N) return 0LL;

    if(peso < c[i]) return solve(i+1,q,peso);
    else{
        ll aux = solve(i+1,q+1,peso-c[i]);

        aux += comb(N-i-1, K-q);

        return aux;   
    }
}

void solve(){

    sort(c,c+N);
    reverse(c,c+N);

    cout << solve(0,0,B) - solve(0,0,A-1LL) << endl;
}

int main(){

	optimize;
	
	cin >> N >> K;
    
    for(int i=0;i<N;i++) cin >> c[i];

    cin >> A >> B;

	solve();
    
	return 0;
}