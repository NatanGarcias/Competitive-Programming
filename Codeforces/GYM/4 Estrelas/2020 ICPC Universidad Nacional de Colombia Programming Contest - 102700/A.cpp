#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<ld,ld> pii;

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

ld v[2][4];
pii dir[2];
ld tempoM[2];

const long double eps = 1E-9;

ld dist(ld a, ld b, ld c, ld d){
	return (a-c)*(a-c) + (b-d)*(b-d);
}

ld dist(ld t){

	ld a,b,c,d;

	if(t >= tempoM[0]){
		a = v[0][2];
		b = v[0][3];
	}
	else{
		a = v[0][0] + t*(dir[0].fi);
		b = v[0][1] + t*(dir[0].se);
	}

	if(t >= tempoM[1]){
		c = v[1][2];
		d = v[1][3];
	}
	else{
		c = v[1][0] + t*(dir[1].fi);
		d = v[1][1] + t*(dir[1].se);
	}

	return dist(a,b,c,d);
}

void pre(){
	dir[0].fi = v[0][2] - v[0][0];
	dir[1].fi = v[1][2] - v[1][0];

	dir[0].se = v[0][3] - v[0][1];
	dir[1].se = v[1][3] - v[1][1];

	ld norma[2];

	norma[0] = sqrt(dist(0.0,0.0,dir[0].fi,dir[0].se));
	norma[1] = sqrt(dist(0.0,0.0,dir[1].fi,dir[1].se));

	if(norma[0]) {
		dir[0].fi/= norma[0];
		dir[0].se/= norma[0];
	}
	if(norma[1]) {
		dir[1].fi/= norma[1];
		dir[1].se/= norma[1];
	}

	tempoM[0] = sqrt(dist(v[0][0],v[0][1],v[0][2],v[0][3]));
	tempoM[1] = sqrt(dist(v[1][0],v[1][1],v[1][2],v[1][3]));
}

ld bt(ld l, ld r){

	while(fabs(r-l) > eps){
		
		ld m1 = l + (r-l)/3.0;
		ld m2 = r - (r-l)/3.0;

		ld f1 = dist(m1);
		ld f2 = dist(m2);

		if(f1 > f2){
			l = m1;
		}
		else{
			r = m2;
		}
	}

	return dist(l);
}

void solve(){

	ld ans[2];

	pre();

	ans[0] = bt(0, min(tempoM[0], tempoM[1]) );

	ans[1] = bt( min(tempoM[0], tempoM[1]) , max(tempoM[0], tempoM[1]) );

	cout << fixed << setprecision(10) << min(sqrt(ans[0]),sqrt(ans[1])) << endl;
}

int main(){
	
	for(int i=0;i<4;i++) cin >> v[0][i];
	for(int i=0;i<4;i++) cin >> v[1][i];

	solve();

	return 0;
}