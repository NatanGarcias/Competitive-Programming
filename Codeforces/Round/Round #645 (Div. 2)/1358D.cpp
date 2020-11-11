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
ll v[MAXN], prefix[MAXN], acum[MAXN];

ll sum(ll x){
    return x*(x+1)/2;
}

ll sumI(ll y, ll x){
    return sum(x) - sum(y);
}

void solve(){

    for(int i=0;i<N;i++){
        if(!i) {
            prefix[i] = v[i];
            acum[i] = sum(v[i]);
        }
        else  {
            prefix[i] = v[i] + prefix[i-1];
            acum[i] = sum(v[i]) + acum[i-1];
        }
    }   

    ll ans = 0, aux = 0;

    for(int i=0;i<N;i++){
        aux = 0;

        //Olhar para o ano passado
        if(M > prefix[i]){
            K = M - prefix[i];

            int p = upper_bound(prefix,prefix + N, prefix[N-1] - K) - prefix;

            aux += acum[N-1] - acum[p];
            K -= (prefix[N-1] - prefix[p]);

            aux += sumI(v[p] - K, v[p]); 

            aux += acum[i];
        }
        else{
            int p = upper_bound(prefix,prefix + N, prefix[i] - M) - prefix;

            aux += acum[i] - acum[p];
            K = M - (prefix[i] - prefix[p]);

            aux += sumI(v[p] - K, v[p]); 
        }
        ans = max(ans, aux);
    }

    cout << ans << endl;
}

int main(){

	optimize;
	
    cin >> N >> M;

    for(int i=0;i<N;i++) cin >> v[i]; 

    solve();

	return 0;
}