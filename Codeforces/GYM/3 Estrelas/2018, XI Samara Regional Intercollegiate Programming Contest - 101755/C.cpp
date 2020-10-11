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

struct PT{
    int a, b, id;

    PT() {}
    PT(pii &c, int _id) : a(c.fi) , b(c.se), id(_id) {} 
    
    bool operator<(const PT &c) const{
        if(b != c.b) return b < c.b;
        if(a != c.a) return a < c.a;
        return id < c.id;
    }
};

struct PT2{
    int a, b, id;

    PT2() {}
    PT2(int _a, int _b, int _id) : a(_a) , b(_b), id(_id) {} 
    
    bool operator<(const PT2 &c) const{
        if(b != c.b) return b > c.b;
        if(a != c.a) return a > c.a;
        return id < c.id;
    }
};

PT v[MAXN];

void solve(){

    sort(v,v+N);

    vector<int> ans;

    int i = 0;

    while(i < N){
        ans.pb(v[i].b);
        int t = v[i].b;
    
        while(i < N && (v[i].a <= t && v[i].b >= t)){
            i++;
        }
    }

    cout << ans.size() << endl;
    FOR(i,0,sz(ans)) cout << ans[i] <<  " \n"[i==sz(ans)-1];
    
}

int main(){

	optimize;
	
	cin >> N;

    FOR(i,0,N) {
        cin >> v[i].a >> v[i].b;
        v[i].id = i+1;
    }
    
    solve();
    
	return 0;
}