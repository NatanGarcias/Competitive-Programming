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
#define MAXN 200010
#define FOR(x,a,n) for(int x= (int)(a);(x) < int(n);(x)++)

ll T,N,M;

void solve(){

	if(N == 1 || M == 1){
		cout << "YES" << endl;
	}else if(M == 2 && N == 2){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
}

int main(){

	cin >> T;

    while(T--){
		cin >> N >> M;
		
		solve();
    }

	return 0;
}