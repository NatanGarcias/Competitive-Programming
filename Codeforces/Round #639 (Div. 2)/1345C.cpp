#include<bits/stdc++.h>
using namespace std;

// Template 1 
typedef long long ll;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define pii pair<int,int>
#define fi first 
#define se second 
#define pb push_back
#define sz(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define FOR(x,a,n) for(int x= (int)(a);(x) < int(n);(x)++)

#define MAXN 200010

ll T,N,M;
int v[MAXN];

int mod(int a, int b){

    if(a >= 0) return a%b;
    
    int aux = abs(a)%b;
    
    if(!aux) return 0;
    else return b - aux;
}

void solve(){

    set<ll> s;

    FOR(i,0,N){
        ll aux = mod(i + v[ mod(i,N) ] , N);   
    
        if(s.find(aux) ==  s.end()){
            s.insert(aux);
        }else{
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;

}

int main(){

    cin >> T;

    while(T--){
		cin >> N;

        FOR(i,0,N) cin >> v[i];

		solve();
    }

	return 0;
}