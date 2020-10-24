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

vector<tuple<ll,ll,ll>> v;
vector<ll> v1;
vector<pii> p1;

map<pii,ll> mapa, pos;
map<ll,ll> mapa2;

ll seg[4*MAXN];

ll query(int p, int tl, int tr, int a, int b){

    if(a > tr || b < tl) return 0;

    if(a <= tl && b >= tr) return seg[p];

    int tm = (tl+tr)/2;
    int e = (p << 1);
    int d = (p << 1) +1;

    return max( query(e,tl,tm,a,b), query(d,tm+1,tr,a,b) );
}

void update(int p, int tl, int tr, int a, int b, ll z){

    if(a > tr || b < tl) return;

    if(a <= tl && b >= tr) {
        seg[p] += z;
        return;
    }

    int tm = (tl+tr)/2;
    int e = (p << 1);
    int d = (p << 1) +1;

    update(e,tl,tm,a,b,z);
    update(d,tm+1,tr,a,b,z);

    seg[p] = max(seg[e], seg[d]);
}

void solve(){

    N = mapa.size();

    v.resize(N);
    v1.resize(N);
    p1.resize(N);

    int cnt = 0;
    for(auto i : mapa){
        ll a = i.fi.fi, b = i.fi.se, c = i.se;

        v[cnt] = make_tuple(a,-b,c);
        v1[cnt] = b;
        p1[cnt++] = pii(b,a);
    }

    sort(all(v));
    sort(all(v1));
    sort(all(p1));
    
    //Calculando a posição de cada pair na seg
    for(int i=0;i<N;i++) pos[ pii(p1[i].se, p1[i].fi) ] = i+1;
    
    //Calculando até onde posso fazer a consulta com aquela altura na seg
    for(int i=0;i<N;i++)
        if(mapa2.find(v1[i]) == mapa2.end())
            mapa2[ v1[i] ] = i+1;

    for(int i=0;i<N;i++){
        ll aux = 0;
        ll a = get<0>(v[i]), b = -get<1>(v[i]), c = get<2>(v[i]);

        ll pQ = mapa2[b];
        ll pS = pos[pii(a,b)];

        aux = query(1,1,N,1, pQ -1 );

        update(1,1,N, pS, pS , aux + c);
    }

    cout << query(1,1,N,1,N) << endl;
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