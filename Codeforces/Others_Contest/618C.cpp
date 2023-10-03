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

struct Star{
	ll x,y,id;

	Star(ll _x, ll _y, ll _id) : x{_x}, y{_y}, id{_id} {}

	bool operator<(const Star &a){
		if(x != a.x) return x < a.x;
		if(y != a.y) return y < a.y;
		return id < a.id;
	}
};

vector<Star>star;

ll area(ll a, ll b, ll c, ll d, ll e, ll f){
	return abs( (a*d - b*c ) +  (b*e - a*f) + (c*f - d*e));
}

ll dist(ll a, ll b, ll c, ll d){
	return (c-a)*(c-a) + (d-b)*(d-b);
}

void solve(){

	ll pos = 1, menor = 0;
	bool ok = true;

	FOR(i,1,T){
		ll aux = dist(star[0].x,star[0].y,star[i].x,star[i].y);
		if(ok){
			ok = false;
			menor = aux;
			pos = i;
		}else if(menor > aux){
			menor = aux;
			pos = i;
		}
	}

	ll pos2 = 2;
	ok = true;

	FOR(i,1,T){
		if(i == pos) continue;
		ll aux = area(star[0].x,star[0].y,star[pos].x,star[pos].y,star[i].x,star[i].y);
		if(ok && aux !=0){
			ok = false;
			menor = aux;
			pos2 = i;
		}else if(menor > aux && aux !=0){
			menor = aux;
			pos2 = i;
		}
	}
    cout << star[0].id << " " << star[pos].id << " " << star[pos2].id << endl;
}

int main(){

	optimize;

	cin >> T;

	FOR(i,0,T){
		int a,b;

		cin >> a >> b;

		star.pb(Star(a,b,i+1));
    }
	solve();

	return 0;
}