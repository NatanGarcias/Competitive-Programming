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

struct Sith{
    int a,b,c;

    Sith() {}
    Sith(int _a, int _b, int _c) :a(_a), b(_b), c(_c) {}
};

Sith S[MAXN];

bool luta(const Sith &p, const Sith &q){
    int ans = 0;
    if(p.a > q.a) ans++;
    if(p.b > q.b) ans++;
    if(p.c > q.c) ans++;

    return ans >=2; 
}

void solve(){

    int ptr = 0;

    FOR(i,1,N){ 
        if( luta(S[ptr], S[i]) ){
            ptr = i;
        }
    }

    FOR(i,0,N){ 
        if(i != ptr && luta(S[ptr], S[i]) ){
            cout << 0 << endl;
            return;
        }
    }

    cout << 1 << endl;
    cout << ptr+1 << endl;
}

int main(){

	optimize;
	
	cin >> N;

    FOR(i,0,N) cin >> S[i].a >> S[i].b >> S[i].c;
		
	solve();

	return 0;
}