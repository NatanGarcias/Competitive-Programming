#include<bits/stdc++.h>
using namespace std;

// Template 1 .. Natan
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
set<ll> s;

void pre(){

    ll sum = 1;
    ll valor = 1;
    ll sumA = 1;

    s.insert(0);
    s.insert(2);

    int i = 2;

    while(sum*2 + 1 <= 1000000000){
        sum = sum + i;

        s.insert(sum * 2 + valor);

        valor = sum;
        i++;
    }


}

void solve(){

    int ans = 0;

    while(N >= 2){
        auto it = s.upper_bound(N);

        if(it!= s.begin()) it--;

        if( N - (*it) == 0){
            ans++;
            break;
        }else{
            N = N - (*it);
            ans++;
        }
    }

    cout << ans << endl;
}

int main(){

	cin >> T;

    pre();

    while(T--){
		cin >> N;
		
		solve();
    }

	return 0;
}