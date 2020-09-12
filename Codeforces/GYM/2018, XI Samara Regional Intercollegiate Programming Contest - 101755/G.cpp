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
ll v[MAXN], seg[4*MAXN];

void build(int p, int tl, int tr){
    
    if(tl == tr) seg[p] = v[tl];
    else{
        int tm = (tl+tr)/2;
        int e = p << 1;
        int d = (p << 1) + 1;

        build(e,tl, tm);
        build(d,tm+1,tr);

        seg[p] = seg[e] + seg[d];
    }
}

ll query(int p, int tl, int tr, int a, int b){
    
    if(a > tr || b < tl) return 0;
    if(a <= tl && b >= tr) return seg[p];

    else{
        int tm = (tl+tr)/2;
        int e = p << 1;
        int d = (p << 1) + 1;

        return seg[p] = query(e, tl, tm, a ,b) + query(d, tm+1, tr, a ,b);
    }
}

void solve(){

    build(1,1,N);

    int pos = -1;
    ll ans = 0;

    queue<int> fila;

    for(int i=1;i<K;i++){
        if( abs(v[i] - v[i+K-1]) == 1)
            fila.push(i+K-1);
        else if(v[i] != v[i+K-1])
            pos = i;
    }

    if(pos == -1){
        ans += query(1,1,N,1,K) - (ll)fila.size();
    }

    for(int i = K+1;i<=N;i++){

        if(!fila.empty() && fila.front() < i-K+1) fila.pop();
      
        if(abs(v[i] - v[i-K+1]) == 1)
            fila.push(i-K+1);
        else if(v[i] != v[i-K+1])
            pos = i;

        cout << pos << " " << i << endl;
        if(pos < i-K+1){
            cout << "Hehe\n";
            cout << i-K+1 << " -- " << i << endl; 
            ans += query(1,1,N,i-K+1,i) - (ll)fila.size();
        }
    }

    cout << ans << endl;
}

int main(){

	optimize;
	
    cin >> N >> K;

    FOR(i,1,N+1) cin >> v[i];

	solve();

	return 0;
}