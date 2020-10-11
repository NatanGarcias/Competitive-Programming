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

#define mod 998244353LL
#define MAXN 1010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;

struct PT{
    int a, b, c;

    PT() {}
    PT(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {}

};

PT pt[MAXN];

ll dist(PT &p){
    return p.a*p.a + p.b*p.b + p.c*p.c;
}

void solve(){

    int id = -1;
    ll menor = INFLL;

    FOR(i,0,N) {
        ll aux = dist(pt[i]);
        if(menor > aux){
            id = i;
            menor = aux;
        }
    }

    cout << fixed << setprecision(3) << sqrt(dist(pt[id])) << endl;
}

int main(){

    optimize;
	
	cin >> N;

    FOR(i,0,N){
        cin >> pt[i].a >> pt[i].b >> pt[i].c;
    }		
    
    solve();

	return 0;
}