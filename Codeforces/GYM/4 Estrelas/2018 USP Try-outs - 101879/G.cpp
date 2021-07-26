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
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;

pii seg[4 * MAXN];
vector<pii> guard;

void build(int p, int tl, int tr){

    if(tl == tr){
        seg[p] = guard[tl];
        return;
    }

    int tm = (tl+tr)/2;
    int e = (p << 1);
    int d = (p << 1) | 1;

    build(e,tl,tm);
    build(d,tm+1,tr);

    seg[p] = pii(max(seg[e].fi, seg[d].fi), min(seg[e].se, seg[d].se) );
}

pii query(int p, int tl, int tr, int a, int b){

    if(a > tr || b < tl) return pii(-INF,INF);
    
    if(a <= tl && b >= tr){
        return seg[p];
    }

    int tm = (tl+tr)/2;
    int e = (p << 1);
    int d = (p << 1) | 1;

    pii esq = query(e,tl,tm,a,b);
    pii dir = query(d,tm+1,tr,a,b);

    return pii(max(esq.fi, dir.fi), min(esq.se, dir.se) );
}

void update(int p, int tl, int tr, int a, int b, pii x){

    if(a > tr || b < tl) return ;
    
    if(a <= tl && b >= tr){
        seg[p] = x;
        return;
    }

    int tm = (tl+tr)/2;
    int e = (p << 1);
    int d = (p << 1) | 1;

    update(e,tl,tm,a,b,x);
    update(d,tm+1,tr,a,b,x);

    seg[p] = pii(max(seg[e].fi, seg[d].fi), min(seg[e].se, seg[d].se) );
}

void solve(){

    build(1,1,N);

    for(int i=0;i<M;i++){
        int a,b,c;
        char k;

        cin >> k;

        if(k == '?'){
            cin >> a >> b;

            pii ans = query(1,1,N,a,b);
            
            cout << max(0, ans.se - ans.fi + 1) << endl;
        }
        else{
            cin >> a >> b >> c;

            update(1,1,N, a, a, pii(b,c));
        }
    }
}

int main(){

	optimize;
	
	cin >> N >> M;
    
    guard.resize(N+1);

    for(int i=1;i<=N;i++) cin >> guard[i].fi >> guard[i].se;

	solve();

	return 0;
}