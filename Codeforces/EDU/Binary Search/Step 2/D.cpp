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

#define all(x) x.begin(),x.end()
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 1010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
ll A[MAXN], B[MAXN], C[MAXN];

bool verifica2(ll x, ll m, ll i){
    return m * A[i] + ( (m-1LL) /B[i]) * C[i] <= x;
}

ll bb2(ll x, ll i){

    ll l = 0LL, r = 15010;
    
    while(l < r){
        ll m = (l+r+1)/2LL;

	    if(verifica2(x, m, i))
            l = m;
        else
            r = m - 1LL;
    }

	return l;
}

bool verifica(ll x){
    
    ll cnt = 0;

    for(int i=0;i<M;i++){
        cnt += bb2(x,i);
    }

    return cnt >= N;
}

ll bb(){

    ll l = 0LL, r = INFLL;
    
    while(l < r){
        ll m = (l+r)/2LL;

	    if(verifica(m))
            r = m;
        else
            l = m + 1LL;
    }

	return l;
}

void solve(){
    ll ans = bb(); 

	cout << ans << endl;

    ll cnt = 0;

    for(int i=0;i<M;i++){
        ll aux = bb2(ans, i);

        if(aux + cnt > N) {
            aux = N - cnt;
            cnt = N;
        }
        else{
            cnt += aux;
        }

        if(i)   cout << " " << aux;
        else    cout << aux;
    }
    cout << endl;
}

int main(){

	optimize;
	
	cin >> N >> M;

    for(int i=0;i<M;i++){
        cin >> A[i] >> B[i] >> C[i];
    }
		
	solve();
    
	return 0;
}