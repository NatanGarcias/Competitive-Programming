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
ll A[MAXN];

struct Pilha{
    vector<ll> s, val;

    Pilha(){
        val.pb(0LL);
    }

    bool empty() { return s.empty(); }
    ll gcd(){ return val.back(); }
    
    ll pop() { 
        ll x = s.back();
        s.pop_back();
        val.pop_back();
        return x;
    }

    ll push(ll x){
        s.push_back(x);
        val.push_back( __gcd(val.back(), x) );
    }
};

Pilha p, p2;

bool good(){
    ll u = p.gcd();
    ll v = p2.gcd();
    return (__gcd(u,v) == 1LL);
}

void remove(){
    if(p2.empty()){
        while(!p.empty()) p2.push(p.pop());
    }
    p2.pop();
}

void solve(){

    int l = 0, r = -1;
    int ans = INF;
    
    for(;r<N;){
        while( good() ){
            ans = min(ans, r-l+1);

            remove();
            l++;
        }
        p.push(A[++r]);
    }

    if(ans == INF)  cout << -1 << endl;
    else            cout << ans << endl;
}

int main(){
	
    optimize;

	cin >> N;
	
    for(int i=0;i<N;i++) cin >> A[i];

	solve();

	return 0;
}