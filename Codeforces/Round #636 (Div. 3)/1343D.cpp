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
#define MAXN 200010

ll T,N,M,K;
ll v[MAXN];

void solve(){
    vector<ll> resp(2*K+3,0);
    vector<ll> resp2(2*K+3,0);

    ll ans = 0;
    int pares = N/2;

    FOR(i,0,N/2){
        int pos = N - i - 1;
        if(v[i] > K && v[pos] > K){
            ans +=2;
            pares--;
        }else if(v[i] > K || v[pos] > K){
            ans+=1;
            pares--;
        }else{
            resp[ v[i] + v[pos] ]++;

            int men = min(v[i], v[pos]) + 1;
            int mai = max(v[i], v[pos]) + K;
            resp2[men]++;
            resp2[mai+1]--;
        }
    }    

    int maior = -INF;
    ll sum = 0;

    FOR(i,0,2*K+3){
        sum += resp2[i];

        if(resp[i] - (pares - sum) > maior){
            maior = resp[i] - (pares - sum);
        } 
    }

    cout << ans + ( pares - maior) << endl;
}

int main(){

    optimize; 

	cin >> T;

    while(T--){
		cin >> N >> K;

        FOR(i,0,N){
            cin >> v[i];
        }

		solve();
    }

	return 0;
}