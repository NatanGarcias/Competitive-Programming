#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld; 
typedef unsigned long long ull; 

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
#define MAXM 2029
#define MAXL 20

ull N,T,M;
vector<ull> v;

vector<ull> k_ele;
vector<bool> vis;

bool solve(ull a){
    
    int cont = sz(k_ele)-1;

    while(cont >= 0){
        if(vis[cont]) {
            cont--;
            continue;
        }
        else if(a == 0){
            break;
        }else if(a >= k_ele[cont]){
            vis[cont] = true;  
            a -= k_ele[cont];
        }
        cont--;
    }

    if(a == 0){
        return true;
    }else{
        return false;
    }
}

void pre(){

	k_ele.pb(0);
	k_ele.pb(1);

	ull cont = 1;
	while(true){
		cont *= M;

		if(cont <= 10000000000000010 && cont > 0){
			k_ele.pb(cont);
		}else{
			break;
		}
	}

}

void solve(){

	FOR(i,N){
		if(!solve(v[i])){
			cout << "NO" << endl;
            return;
        }
	}
	cout << "YES" << endl;
}

int main(){

	cin >> T;

	while(T--){
		cin >> N >> M;

		v.clear();
		v.resize(N);

        k_ele.clear();

		FOR(i,N){
			cin >> v[i];
		}

        pre();

        vis.clear();
        vis.assign(sz(k_ele), false);

        sort(all(v));

		solve();
	}

	return 0;
}