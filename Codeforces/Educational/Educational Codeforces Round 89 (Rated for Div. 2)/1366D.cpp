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
#define MAXN 500010
#define MAXM 10000100

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
int nums[MAXN];
pii ans[MAXN];

ll _tam_crivo;
bool v[MAXM];
int fact[MAXM];

void crivo(ll limite) { 
    
    v[1] = 1;
    _tam_crivo = limite+1;

    for (ll i = 2; i <= _tam_crivo; i++){
        if(!v[i]){
            fact[i] = i;   
            for (ll j = i*i; j <= _tam_crivo;j+=i){
                if(!fact[j]) fact[j] = i;
                v[j] = 1;
            }
        }
    }
}

void fator(int p,int x){

    vector<int> fat;
    int last = -1;
    while(fact[x]){
        if(last != fact[x]){
            fat.pb(fact[x]);
            last = fact[x];
        }
        x /= fact[x];
    }

    if(sz(fat) < 2 ) return;
    
    ll aux = 1;
    for(auto i : fat){
        if(i == *(fat.begin())) continue;
        aux *= i;
    }

    ans[p].fi = *(fat.begin());
    ans[p].se = aux;
}

void solve(){      
    
    ms(ans, -1);

    FOR(i,0,N){
        int x = nums[i];
        fator(i,x);
    }

    FOR(i,0,N) cout << ans[i].fi << " \n"[i==N-1];
    FOR(i,0,N) cout << ans[i].se << " \n"[i==N-1];
}

int main(){

    optimize;

    crivo(10000100);

    cin >> N;
    
    FOR(i,0,N) cin >> nums[i];

	solve();
    
	return 0;
}