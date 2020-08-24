#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<double,double> pdd;

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
int T,N,M,K;
pdd v[MAXN];

const double eps = 1e-6;

double dist(pdd p, pdd q){
	return (p.fi-q.fi)*(p.fi-q.fi) + (p.se-q.se)*(p.se-q.se);
}

double f(double x){
	double d = -1;

	FOR(i,0,N){
		d = max(d, dist(pdd(x,0), v[i]));
	}

	return d;
}

pdd BT(){

	double l = -200000.0, r = 200000.0;

	while(abs(l-r) > eps){
		
		double m1 = l + (r-l)/3.0;
		double m2 = l + 2.0*(r-l)/3.0;

		double f1 = f(m1);
		double f2 = f(m2);

		if(f1 > f2){
			l = m1;
		}else{
			r = m2;
		}
	
	}

	return pdd(l, f(l));
}

void solve(){

	pdd ans = BT();

	printf("%.7lf %.7lf\n", ans.fi, sqrt(ans.se));
}	

int main(){

	optimize;
	
	while(scanf("%d", &N) == 1){
		if(!N) break;

		FOR(i,0,N) scanf("%lf %lf", &v[i].fi, &v[i].se);

		solve();
	}

	return 0;
}