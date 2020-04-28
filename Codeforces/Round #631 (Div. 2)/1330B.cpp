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

int T,N,M,X;
int v[MAXN];

bool vai[MAXN];
bool vem[MAXN];

void solve(){

    vector<pii> sol;
    multiset<int> ms;
    int maior = -1;
    
    FOR(i,0,N){
        if(ms.find(v[i]) == ms.end()){
            maior = max(maior, v[i]);
            ms.insert(v[i]);
        }else{
            break;
        }
        
        if(maior == i+1){  
        	vai[i] = true;
        }
    }

    ms.clear();
    maior = -1;

    FOR(i,0,N){
    	int j = N -1 -i;
        if(ms.find(v[j]) == ms.end()){
            maior = max(maior, v[j]);
            ms.insert(v[j]);
        }else{
            break;
        }
        
        if(maior == i+1){  
        	vem[j] = true;
        }
    }

    FOR(i,0,N-1){
    	if(vai[i] && vem[i+1])
    		sol.pb(pii(i+1,N-i-1));
    }

    cout << sz(sol) << endl;

    FOR(i,0,sz(sol)){
        cout << sol[i].fi << " " << sol[i].se << endl;
    }

}

int main(){

	optimize;

	cin >> T;

    while(T--){
    	
    	ms(vai,0);
    	ms(vem,0);

		cin >> N;

        FOR(i,0,N){
            cin >> v[i];
        }
        solve();
    }

	return 0;
}