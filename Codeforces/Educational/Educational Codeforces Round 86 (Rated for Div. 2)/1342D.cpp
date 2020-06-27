#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld; 

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

#define pii pair<int,int>
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
#define MAXN 200010

ll T,N,M,Q,L,R;
multiset<int> ms;
set<int> s;
int v[MAXN];

void solve(){

    int caixas = -INF;
    int qttd = N;

    for(auto i : s){
        caixas = max( caixas, (int) (qttd + v[i] - 1 )/v[i] );

        qttd -= ms.count(i);        
    }

    vector<vector<int>> ans(caixas);

    auto it = ms.end();

    FOR(i,0,sz(ms)){
        it--;

        ans[ i % caixas ].pb( (*it) );
    }

    cout << caixas << endl;

    FOR(i,0,caixas){
        cout << ans[i].size();
        FOR(j,0,ans[i].size()){
            cout << " " << ans[i][j];
        }cout << endl;
    }
}

int main(){
    
    optimize;
    
    cin >> N >> M; 

    int a;
    FOR(i,0,N) {
        cin >> a;
        ms.insert(a);
        s.insert(a);
    }

    FOR(i,0,M){
        cin >> v[i+1];
    }

    solve();

	return 0;
}