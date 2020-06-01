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
#define MAXN 200010

ll T,N,M,K;

// Soma de 1 a N
ll bb(ll x){

	ll l = 1, r = (ll) 1e10;

	while(true){
		ll m = (l+r+1)/2;

        if(l>=r)
            return m;
        else if( ((m)*(m+1))/2 <= x)
            l = m;
        else
            r = m-1;
	}
}

// Soma de números pares de 2 a N
ll bbP(ll x, ll c){

	ll l = c, r = (ll) 1e10;

	while(true){
		ll m = (l+r+1)/2;

        if(l>=r)
            return m;
        else if( ((m)*(m+1)) <= x)
            l = m;
        else
            r = m-1;
	}
}

// Soma de números ímpares de 1 a N
ll bbI(ll x, ll c){

	ll l = c, r = (ll) 1e10;

	while(true){
		ll m = (l+r+1)/2;

        if(l>=r)
            return m;
        else if( m*m <= x)
            l = m;
        else
            r = m-1;
	}
}

void solve(int caso){

	if(N>= M)	K = N-M;
	else 		K = M-N;

	ll i = 0;

	if(K){
		i = bb(K);

		if(N >= M) N =  N - (i*(i+1))/2;
		else M =  M - (i*(i+1))/2;
	}
	
	bool mudei = false;
	
	if( ( !(i&1) && N>=M ) || ( i&1 && M>N )){
		swap(N,M);
		mudei = true;
	}

	ll iter = i, aux, a, temp;

	//N par
	aux = iter/2;

	K = N + aux*(aux+1);
	
	a = bbP(K,aux);
	
	temp = a*(a+1) - aux*(aux+1);

	if(N >= temp){
		N = N - temp;
		i = i + (a - aux);
	}

	//M impar
	aux = (iter+1)/2;
	
	K = M + aux*aux;

	a = bbI(K,aux);

	temp = a*a - aux*aux;
	
	if( M >= temp){
		M = M - temp;
		i = i + (a - aux);
	}

	if(mudei) swap(N,M);

	cout << "Case #" << caso << ": " << i << " " << N << " " << M << endl;
}

int main(){

	cin >> T;

    FOR(i,1,T+1){
		cin >> N >> M;
		
		solve(i);
    }

	return 0;
}