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

ll MDC(ll a, ll b) { return b ? MDC(b, a%b) : a; }
ll MMC(ll a, ll b) { return a * (b/MDC(a,b)); }

struct Planeta{
    ll x,y,z;
    ll vx,vy,vz;

    Planeta(){}
    Planeta(ll _x, ll _y, ll _z) : x(_x), y(_y), z(_z) {}
};

vector<Planeta> p;
set<tuple<ll,ll,ll>> s;

void concerta(ll &a, ll &b, ll &c){
    a *= -1;
    b *= -1;
    c *= -1;
}

void arruma(ll &a, ll &b, ll &c){
    ll mdc = MDC(abs(a),abs(b));

    mdc = MDC(mdc,abs(c));

    a /= mdc;
    b /= mdc;
    c /= mdc;

    if(a <= 0 && b <= 0 && c <= 0) concerta(a,b,c);
    else if(a <= 0 && b <= 0 && c >= 0) concerta(a,b,c);
    else if(a <= 0 && b >= 0 && c <= 0) concerta(a,b,c); 
    else if(a <= 0 && b >= 0 && c >= 0) concerta(a,b,c);
}

void diretor(int i){
    ll a = p[i].x - p[0].x;
    ll b = p[i].y - p[0].y;
    ll c = p[i].z - p[0].z;

    arruma(a,b,c);

    p[i].vx = a;
    p[i].vy = b;
    p[i].vz = c;
}

void solve(){
    
    for(int i=1;i<N;i++){
        diretor(i);
    }

    for(int i=1;i<N;i++){
        s.insert(make_tuple(p[i].vx,p[i].vy,p[i].vz));
    }

    cout << (int)s.size() << endl;
}

int main(){

	optimize;
	
	cin >> N;

    for(int i=0;i<N;i++){
        int a,b,c;
        
        cin >> a >> b >> c;

        p.emplace_back(a,b,c);
    }

	solve();
    
	return 0;
}