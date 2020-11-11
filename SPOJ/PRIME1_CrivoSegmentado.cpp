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

bool p[MAXN];
vector<ll> primos;

void crivo(ll n){

    p[0] = true, p[1] = true;

    for(ll i=2;i<=n;i++){
        if(!p[i]){
            for(ll j = i*i;j<=n;j+=i)
                p[j] = true;
        }
        primos.pb(i);
    }

}

bool parte[MAXN];
void crivoSeg(ll l ,ll r){

    for(int i=0;i<primos.size();i++){
        //Achar o menor multiplo dele no intervalo l-r
        ll prime = primos[i] * ( (l+primos[i]-1) /primos[i]);
        
        for(int j = prime ; j<=r ;j += primos[i])
            parte[j-l] = true;
    }
}

void solve(){

    if(M <= 100000){
        for(ll i=N; i<=M;i++) if(!p[i]) cout << i << endl;
    }
    else{
        ms(parte, 0);

        crivoSeg(N,M);

        for(ll i=0; i<=M-N;i++) if(!parte[i]) cout << i+N << endl;
    }
}

int main(){

    optimize;

	crivo(100000);
	
	cin >> T;

    for(int i=0;i<T;i++){
		cin >> N >> M;

		solve();
        
        if(i != T-1) cout << endl;
    }

	return 0;
}