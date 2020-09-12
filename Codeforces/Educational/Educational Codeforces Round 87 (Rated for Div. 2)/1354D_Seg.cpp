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

#define PI 3.141592653589793238462643383279502884
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007
#define MAXN 1000010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
int seg[4*MAXN];

int query(int p, int tl, int tr, int k){

    if(tl == tr) return tl;
    else{
        int tm = (tl+tr)/2;
        int e = p << 1;
        int d = (p << 1) +1;

        if(seg[e] >= k) return query(e,tl,tm,k);
        else return query(d,tm+1,tr,k - seg[e]);
    }
}

void update(int p, int tl, int tr, int a, int v){
    
    if(a > tr || a < tl) return;

    if(a <= tl && tr <= a){
        seg[p] += v;
        return;
    }
    else{
        int tm = (tl+tr)/2;
        int e = p << 1;
        int d = (p << 1) +1;

        update(e,tl,tm,a,v);
        update(d,tm+1,tr,a,v);

        seg[p] = seg[e] + seg[d];
    }
}

bool seg_empty(){
    return !seg[1];
}

void solve(){
    
    FOR(i,0,M){
        int a;
        cin >> a;

        if(a>0) update(1,1,N,a,1);
        else update(1,1,N,query(1,1,N,-a),-1);
    }   

    if(seg_empty()) cout << 0 << endl; 
    else cout << query(1,1,N,1) << endl;

}
int main(){

    optimize;
    
	cin >> N >> M;

    FOR(i,0,N){
        int a;
        cin >> a;
        update(1,1,N,a,1);
    }	

	solve();
    
	return 0;
}