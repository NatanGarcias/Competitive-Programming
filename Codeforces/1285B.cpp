#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld; 

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

#define pii pair<int,int>
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
#define MAXN 100010

ll T,N,M,K,A,B,C;
ll v[MAXN];

void solve(){

    ll sum = 0;
    FOR(i,0,N) sum+=v[i];

    ll sum2 = 0;

    ll maior = -INFLL, menor = INFLL;

    bool ok = false;
    int p = -1;

    FOR(i,0,N){
        menor = min(menor, v[i]);
        sum2 += v[i];

        if(sum2 > maior){ 
            maior = sum2;
            p = i;
        }

        if(sum2 <= 0){
            sum2 = 0;
            ok = true;
        }
    }
    
    if(ok){
        if(sum > maior) cout << "YES\n";
        else cout << "NO\n";
    }else if(p == N-1) cout << "YES\n";
    else cout << "NO\n";
    
}

int main(){

    cin >> T;

    while(T--){
        cin >> N;

        FOR(i,0,N) cin >> v[i];

        solve();
    }

	return 0;
}