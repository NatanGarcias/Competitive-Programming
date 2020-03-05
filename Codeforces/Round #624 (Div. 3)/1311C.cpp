#include<bits/stdc++.h>
using namespace std;

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
#define ms(x) memset(x,0,sizeof(x))
#define ms2(x) memset(x,-1,sizeof(x))

#define PI 3.141592653589793238462643383279502884
#define FOR(x,n) for(int x=0;(x) < int(n);(x)++)
#define FOR1(x,n) for(int x=1;(x) <= int(n);(x)++)

#define INF 0x3fffffff
#define INFLL 0x3fffffffffffffff

#define mod %1000000007
#define MAXN 200010

int T,N,M;
int a ,b;
string s;

multiset<int> v;
bool vis[MAXN];
int c[26];
int d[26];

void solve(){

	int i = 1;

    int temp = 0;

    ms(d);
    ms(c);
    for(auto i : v){
        for(int j = temp; j<i;j++){
            d[ (int) s[j]-97 ] = d[ (int) s[j]-97 ] + 1;
        }
        
        FOR(j,26){
            c[j] += d[j];
        }
        temp = i;
        
    }

    FOR(l,a){
        c[ (int) s[l]-97 ]++; 
    }

    FOR(l,25){
        cout << c[l] << " "; 
    }cout << c[25] << endl;
}

int main(){

	cin >> T;

	while(T--){
        ms(vis);
        v.clear();

		cin >> a >> b;
		
		cin >> s;

        int aux;

		FOR(i,b){
            cin >> aux;

            v.insert(aux);
		}  

		solve();
	}

	return 0;
}