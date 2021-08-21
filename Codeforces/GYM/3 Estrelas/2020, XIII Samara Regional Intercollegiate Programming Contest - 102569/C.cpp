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
#define MAXN 500010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;

vector<int> A, B, comp;
vector<pii> pt;
int bit[MAXN];

void init(){
    ms(bit, 0);
}

void update(int x, int v){
    for(; x < MAXN ; x += x&-x ) bit[x] += v;
}

int query(int x){
    int sum = 0;

    for(; x > 0 ; x -= x&-x ) sum += bit[x];

    return sum;
}

int queryI(int l, int r){
    return query(r) - query(l);
}

bool f(int x){

    init();

    ll j = 0, cnt = 0;

    for(int i = 0 ; i < N ; i++) {
        // Removendo os pontos que já não estão dentro do quadrado
        while(j < i && pt[i].fi - pt[j].fi > x){
            update(comp[j], -1);
            j++;
        }

        int l = pt[i].se - x;
        int r = pt[i].se + x;

        int l2 = lower_bound(all(B), l) - B.begin();
        int r2 = upper_bound(all(B), r) - B.begin();

        cnt += queryI(l2, r2);
        
        //Add o ponto atual
        update(comp[i], 1);
    }
    return cnt >= K;
}

int bb(){
    int l = 0, r = INF;

    while(l < r){
        int m = (l+r)/2;

        if(f(m))    r = m;
        else        l = m + 1;
    }

    return l;
}

void solve(){
    int ans = bb();
    cout << ans << endl;
}

int main(){

	optimize;
	
	cin >> N >> K;

    for(int i = 0, u, v ; i < N ; i++){
        cin >> u >> v;
        
        pt.emplace_back(u + v, v - u);
    }

    sort(all(pt));
    for(auto &i : pt) A.pb(i.se), B.pb(i.se);

    sort(all(B));
    B.resize(unique(all(B)) - B.begin());

    for(auto &i : A) comp.pb(lower_bound(all(B), i) - B.begin() + 1);

	solve();
    
	return 0;
}