#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef unsigned long long ll;
typedef long double ld; 

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

#define pii pair<ll,ll>
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
#define MAXN 110

ll T,N,M,K,A,B;
string v[MAXN];

void solve(){

    sort(v,v+N);

    set<ll> nums;

    K = (1ULL << M);

    pii resp( (K+1ULL)/2ULL , (K+1ULL)/2ULL -1ULL);
    
    FOR(i,0,N){
        
        ll x = 0;
        
        for(int j = sz(v[i])-1;j>=0;j--) if(v[i][j] == '1') x+= (1ULL << (sz(v[i])-j-1));
        
        nums.insert(x);
        K--;

        if(resp.fi - (K+1ULL)/2ULL){    
            if(x >= resp.se){        

                ll cont = 0;
                
                while(nums.find(resp.se - (++cont)) != nums.end());
                resp.se = resp.se - cont;
            }
        }else{    
            if(x <= resp.se){        
                
                ll cont = 0;
                
                while(nums.find(resp.se + (++cont)) != nums.end());
                resp.se = resp.se + cont;
            }
        }
        resp.fi = (K+1ULL)/2ULL;
    }

    ll ans = 0;
    for(int i=M-1;i>=0;i--){
        if(resp.se & (1ULL << i)) cout << 1;
        else cout << 0;
    }
    cout << endl;
}

int main(){

	cin >> T;

    while(T--){
		cin >> N >> M;

        FOR(i,0,N) cin >> v[i];

        solve();
    }

	return 0;
}