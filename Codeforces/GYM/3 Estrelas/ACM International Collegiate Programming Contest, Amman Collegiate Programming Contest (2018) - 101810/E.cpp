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
ll v[MAXN];
ll pref[MAXN], suf[MAXN];

void solve(){

    ll ans;

    pref[0] = v[0];

    for(int i=1;i<N;i++){
        pref[i] = pref[i-1] * v[i];
        pref[i] %= mod;  
    }

    suf[N-1] = v[N-1];

    for(int i=N-2;i>=0;i--){
        suf[i] = suf[i+1] * v[i];
        suf[i] %= mod;  
    }

    //Calculo todos os vizinhos / 2
    ans = (N * pref[N-1]) %mod;

    //Desconto as arestas que estão na borda / 2
    for(int i=0;i<N;i++){
        if(!i)              ans = ( ( ans - ( (suf[i+1])  %mod ) ) + mod) % mod ;
        else if(i == N-1)   ans = ( ( ans - ( (pref[i-1])  %mod ) ) + mod) % mod ;
        else                ans = ( ( ans - ( (pref[i-1]*suf[i+1]) %mod ) ) + mod) % mod ;
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