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
ll A,B,C,D;

ll sum(ll a){
    return (a* (a+1LL))/2LL;
}

void solve(){

    ll ans = 0;

    for(ll i=A;i<=B;i++){
        for(ll j=max(B,C-i+1);j<=C;j++){
            ll aux = i+j;

            if(aux > D){
                ans += (D-C+1) * (C-j+1);
                break;
            }
            else if(aux > C){
                ll temp = D-C+2;
                temp -= (aux-C);

                ll temp2 = C-j+1;

                ans += sum( aux-C + min(temp,temp2) -1) - sum(aux-C -1);

                j += min(temp,temp2) -1;
            }
        }
    }

    cout << ans << endl;
}

int main(){

    cin >> A >> B >> C >> D;

	solve();
    
	return 0;
}