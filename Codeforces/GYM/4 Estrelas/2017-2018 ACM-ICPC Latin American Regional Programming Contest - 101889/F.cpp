#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;

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

struct Hash{
    size_t operator()(const pii &a) const{
        return a.fi ^ a.se;
    }
};

vector<ll> comp;
unordered_map<pii,ll, Hash> mapa;
ll seg[4*MAXN];

void update(int p, ll value) { // set value at position p
    for(seg[p] = max(value,seg[p += M]) ; p > 1; p >>= 1) seg[p>>1] = max(seg[p], seg[p^1]); // Merge
}

ll query(int l, int r) {
    ll res = 0;
    for(l += M, r += M+1; l < r; l >>= 1, r >>= 1) {
        if(l&1) res = max(res,seg[l++]); // Merge
        if(r&1) res = max(res, seg[--r]); // Merge
    }
    return res;
}

struct Node{
	ll b,f,c;

	Node(){};
	Node(ll _b, ll _f, ll _c) : b(_b), f(_f), c(_c) {};

	bool operator<(const Node &a)const{
		if(b != a.b) return b < a.b;
		return f > a.f;
	}
};

vector<Node> v;

void solve(){

    N = mapa.size();

    v.reserve(N);
    comp.reserve(2*N);

    int cnt = 0;
    for(auto &i : mapa){
        ll a = i.fi.fi, b = i.fi.se, c = i.se;

        v.emplace_back(a,b,c);
        
        comp.push_back(a);
        comp.push_back(b);
    }

    sort(all(v));
    sort(all(comp));

  	comp.resize(unique(all(comp)) - comp.begin());

    for(auto &x : v){
    	x.b = lower_bound(all(comp), x.b) - comp.begin();
    	x.f = lower_bound(all(comp), x.f) - comp.begin(); 
    }

    M = comp.size();

    for(int i=0;i<N;i++){
        ll b = v[i].b, f = v[i].f, c = v[i].c;

        ll aux = 0;

        if(f > 0) aux = query(0,f-1);

        update(f,aux + c);
    }

    cout << query(0,M) << endl;
}

int main(){

	optimize;
	
	cin >> N;

	for(int i=0;i<N;i++){
        int a, b, c;

        cin >> a >> b >> c;

        mapa[pii(a,b)] += c;
    }	

	solve();
    
	return 0;
}