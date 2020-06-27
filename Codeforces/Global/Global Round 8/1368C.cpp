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

void solve(){

    set<pii> ans;

    for(int i=0;i<N+N-1 + 2;i++){
        ans.insert(pii(0,i));
    }
    
    int cont = 0, alt = 1,cop;
    while(cont < N){
        if(alt%4 == 0);
        else if(alt%2 == 0){
            ans.insert(pii(-2,alt));
            ans.insert(pii(2 ,alt));
            cop = alt;
        }else{
            ans.insert(pii(-1,alt));
            ans.insert(pii(1 ,alt));

            ans.insert(pii(-2,alt));
            ans.insert(pii(2 ,alt));
            cop = alt;
            cont++;
        }
        alt++;
    }

    if(N&1){
        ans.insert(pii(0,N+N+1));
        ans.insert(pii(1,N+N+1));
        ans.insert(pii(2,N+N+1));
        ans.insert(pii(2,N+N));

        FOR(i,-5,1) ans.insert(pii(i,-1));
        FOR(i,-1,cop+1) ans.insert(pii(-5,i));
        FOR(i,-5,-2) ans.insert(pii(i,cop));
    }else{
        FOR(i,0,5) ans.insert(pii(i,N+N+1));
        for(int i=-1;i<=N+N+1;i++) ans.insert(pii(5,i));
        FOR(i,0,5) ans.insert(pii(i,-1));
    }
    cout << ans.size() << endl;
    for(auto i : ans) cout << i.fi << " " << i.se << endl;
}

int main(){

    optimize;

	cin >> N;

    solve();

	return 0;
}