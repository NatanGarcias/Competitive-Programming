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
#define MAXN 2010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
int v[MAXN];
set<int> s;

void solve(){

    int cont = 0;

    while(++cont <= 2048){
        
        bool ok = true;

        FOR(i,0,N) {
            if(s.find(v[i] ^ cont) == s.end()){
                ok = false;
                break;
            }
        }

        if(ok){
            cout << cont << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main(){

	cin >> T;

    while(T--){
		cin >> N;

        s.clear();

        FOR(i,0,N){
            int a; cin >> a;
            
            v[i] = a;
            
            s.insert(a);
        }
		
		solve();
    }

	return 0;
}