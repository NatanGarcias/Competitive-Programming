#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld; 

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define space " " 

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

ll T,N,M,K;
string S;

void solve(){

    vector<vector<char>> m(K);
    
    FOR(i,0,N){
        m[ (i%K) ].pb(S[i]);
    }

    int ptr = 0;
    int ptr2 = K-1;

    while(ptr < ptr2){
        vector<char> aux(m[ptr]);
        
        FOR(i,0,sz(m[ptr2])){
            aux.pb(m[ptr2][i]);
        }

        m[ptr] = aux;
        ptr++;
        ptr2--;
    }

    ll ans = 0;
    
    int l[26];

    FOR(i,0,((K+1)/2)){
        ms(l,0);

        FOR(j,0,sz(m[i])){
            l[ (int) (m[i][j] - 'a') ]++;
        }

        int resp = 0;
        FOR(j,0,26){
            resp = max( resp , l[j]);
        }

        ans += (sz(m[i]) - resp);
    }

    cout << ans << endl;
}

int main(){

	cin >> T;

    while(T--){
        cin >> N >> K;

        cin >> S;
        solve();
    }
	return 0;
}