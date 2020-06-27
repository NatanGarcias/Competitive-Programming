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
int v[10];

ll f(){
    ll ans = 1;

    FOR(i,0,10) ans *= v[i];
    
    return ans;
}

void solve(){

    FOR(i,0,10) v[i] = 1;

    ll cont = 1;
    int ptr = 0;

    while(cont < N){
        v[ptr]++;
        cont = f();    
        
        if(ptr == 9) ptr = 0;
        else ptr++;

    }

    FOR(i,0,10){
        FOR(j,0,v[i]){
            if(i == 0) cout << 'c';
            if(i == 1) cout << 'o';
            if(i == 2) cout << 'd';
            if(i == 3) cout << 'e';
            if(i == 4) cout << 'f';
            if(i == 5) cout << 'o';
            if(i == 6) cout << 'r';
            if(i == 7) cout << 'c';
            if(i == 8) cout << 'e';
            if(i == 9) cout << 's';
        }
    }
    cout << endl;

}

int main(){

	cin >> N;
    
    solve();

	return 0;
}