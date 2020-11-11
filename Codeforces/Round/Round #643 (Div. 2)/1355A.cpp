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

bool zero(ll a){

    while(a){
        if( !(a%10) ) return true;
        a /= 10;
    }

    return false;
}

ll minDigit(ll a){

    ll menor = 9;
    while(a){
        menor = min(menor, a%10);
        a /= 10;
    }

    return menor;
}

ll maxDigit(ll a){

    ll maior = 0;
    while(a){
        maior = max(maior, a%10);
        a /= 10;
    }

    return maior;
}

void yes(){
    cout << N << endl;
    return;
}

void solve(){

    for(ll i = 1; i<M ;i++){
        if(zero(N)) break; 

        N += minDigit(N) * maxDigit(N);
    }

    yes();
}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
		cin >> N >> M;
		
		solve();
    }

	return 0;
}