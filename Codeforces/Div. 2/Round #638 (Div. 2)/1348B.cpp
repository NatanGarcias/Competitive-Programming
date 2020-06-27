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

ll T,N,M,K;
int v[MAXN];
vector<int> sequencia;
set<int> s;
multiset<int> ms;

void solve(){

    if(sz(s) > K) {
        cout << -1 << endl;
        return;
    }else{
        
        vector<int> falta;

        FOR(i,1,N+1){
            if(s.find(i) == s.end()){
                falta.pb(i);
            }
        }

        int cont = 0;

        while(sz(sequencia) < K){
            sequencia.push_back(falta[cont++]);
        }

        cout << N* sz(sequencia) << endl;
        FOR(i,0,N){
            FOR(j,0,sz(sequencia)){
                if( i == N-1 && j == sz(sequencia)-1 ) cout << sequencia[j] << endl;
                else cout << sequencia[j] << " ";
            }
        }
    }

}

int main(){

    optimize;

	cin >> T;

    while(T--){
		cin >> N >> K;

        s.clear();
        sequencia.clear();

        FOR(i,0,N){
            cin >> v[i];

            if(s.find(v[i]) == s.end()) sequencia.push_back(v[i]);
            
            s.insert(v[i]);
            ms.insert(v[i]);
        }

		solve();
    }

	return 0;
}