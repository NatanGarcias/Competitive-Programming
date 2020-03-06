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

#define FOR(x,n) for(int x=0;(x) < int(n);(x)++)
#define FOR1(x,n) for(int x=1;(x) <= int(n);(x)++)

#define MAXN 200010

ll N,M,T;

pii v[MAXN];
multiset<pii> ms;

void solve(){

	sort(v,v+T);

    ll ans = 0;

    ll i;
    ll cont = 0;

    while(cont < T){
    	i = v[cont].fi;

    	while(cont < T && i >= v[cont].fi){
		
			ms.insert({ -v[cont].se,v[cont].fi });
    		cont++;
    	}
		
		while(cont < T && !ms.empty() && i < v[cont].fi){
    		
    		auto it = ms.begin();
    		
    		ans += ( (*it).fi * (i-(*it).se) );
    	
    		i++;

    		ms.erase(ms.begin());
    	}
    }

    while(!ms.empty()){
    	auto it = ms.begin();
    		
    	ans += ( (*it).fi * (i-(*it).se) );
    	
    	i++;

    	ms.erase(ms.begin());
    }

    cout << -ans << endl;

}

int main(){

	cin >> T;

	FOR(i,T){
        cin >> v[i].fi;
    }

	FOR(i,T){
        cin >> v[i].se;
    }

    solve();
	
    return 0;
}