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

ll T,N,M;
vector<int> v;


void solve(){

    vector<int> sol;
    int primos[] = {2,3,5,7,11,13,17,19,23,29,31};
    
    map<int,int> m;

    set<int> resp;

    
    int cont = 0;
    FOR(i,0,N){
        FOR(j,0,12){
            if(!(v[i] % primos[j])){
                if(resp.find(j+1) != resp.end()){
                    sol.pb( j+1 );
                } else{
                    sol.pb( j+1 );
                    m [ j+1 ] = ++cont;
                    resp.insert(j+1);
                }
                j = 12;
            }
        }    
    }

    cout << sz(resp) << endl;
    FOR(i,0,sz(sol)){
         cout << m[sol[i]] << " \n"[i==sz(sol)-1];
    }

}

int main(){

	cin >> T;

    while(T--){
        cin >> N;

        v.clear();
        v.resize(N);

        FOR(i,0,N){
            cin >> v[i];
        }

        solve();
    }
	return 0;
}