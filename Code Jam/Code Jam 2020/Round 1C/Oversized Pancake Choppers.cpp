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
#define FOR(x,a,n) for(int x=(int)(a);(x) < int(n);(x)++)
#define ms(x,a) memset(x,a,sizeof(x))

#define PI 3.141592653589793238462643383279502884
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007
#define MAXN 10010
#define EPS 1e-7
#define EPS2 1e-5

int T,N,M,K;
ll v[MAXN];

ll MDC(ll a, ll b)  { return b ? MDC(b,a%b) : a; }
ll MMC(ll a,ll b)  { return a*(b/MDC(a,b)); }

struct Rac{
	ll p,q;

	Rac(ll _p = 0LL , ll _q = 1LL) : p{_p}, q{_q} {
		ll m = MDC(p,q);

		p /= m;
		q /= m;
	}

	bool operator<(const Rac &a) const{
		ll m = MMC(q,a.q);

		ll u = (m/q) * p;
		ll v = (m/a.q) * a.p;

		if(u < v) return true;
		else return false;
	}
	bool operator<=(const Rac &a) const{
		ll m = MMC(q,a.q);

		ll u = (m/q) * p;
		ll v = (m/a.q) * a.p;

		if(u <= v) return true;
		else return false;
	}
	Rac operator+(Rac &a){
		ll m = MMC(q,a.q);

		p = (m/q)*p, q = m;
		a.p = (m/a.q)*a.p;

		return Rac(p+a.p, q);
	}
	Rac operator-(Rac &a){
		ll m = MMC(q,a.q);

		p = (m/q)*p, q = m;
		a.p = (m/a.q)*a.p;
	
		return Rac(p-a.p, q);
	}
	Rac operator*(Rac &a){ return Rac(p*a.p, q*a.q); }
	Rac operator/(Rac &a){ return Rac(p*a.q, q*a.p); }
	Rac operator/(const ll a){ return Rac(p, q*a); }
};

bool verifica(ld m){
	ll ans = 0;
	FOR(i,0,N) ans += ll( v[i]/m );
	return ans >= M;
}

ld bb(ll a){
	ld l = 1e-3 , r = ld(a);

	while(true){
		ld m = (l+r)/2.0;
		
		if(r-l < EPS) return m;
		else if(verifica(m)){
			l = m;
		}else {
			r = m - EPS;
		}
	}
}

void solve(int caso){

	ld maior = bb( v[N-1] * 1.0 );

	map<Rac,pii> mapa;

	FOR(i,0,N){
		FOR(j,1,M+1){
			ld p(v[i]/(j*1.0));

			if(p - EPS2 > maior) continue;
			
			Rac c(v[i],j);

			if(mapa.find(c) == mapa.end()){
				mapa[c] = pii(1,j);
			}else{
				pii aux = mapa[c];
				
				if(aux.se + j > M) mapa[c] = pii(aux.fi, aux.se + j);
				else mapa[c] = pii(aux.fi + 1, aux.se + j);
			}
		}
	}

	ll ans = 1;

	for(auto i : mapa) ans = max(ans, i.se.fi);

	cout << "Case #" << caso << ": " << M-ans << endl;	
}	

int main(){

	cin >> T;

    FOR(i,1,T+1){
		cin >> N >> M;
		
		FOR(j,0,N) cin >> v[j];

		sort(v,v+N);
		
		solve(i);
    }

	return 0;
}