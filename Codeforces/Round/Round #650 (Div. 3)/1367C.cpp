#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

#define fi first 
#define se second 
#define pb push_back

#define sz(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
string s;

int v[MAXN], v2[MAXN];

void solve(){

    int d = INF;

    for(int i=0;i<N;i++){
        if(s[i] == '1'){
            v[i] = 0;
            d = -1;
        }
        else{
            if(d == INF) v[i] = INF;
            else         v[i] = ++d;
        }
    }
    
    d = INF;

    for(int i=N-1;i>=0;i--){
        if(s[i] == '1'){
            v2[i] = 0;
            d = -1;
        }
        else{
            if(d == INF) v2[i] = INF;
            else         v2[i] = ++d;
        }
    }
    
    int ans = 0;
    d = M;

    for(int i=0;i<N;i++){
        if( (v[i] >= M) && (v2[i] >= M) && d >= M){
            ans++;
            d = 0;
        }
        else{
            d++;
        }
    }

    if(ans == 0){
        bool ok = true;

        for(int i=0;i<N;i++){
            if(s[i] != '0') ok = false;
        }

        ans = ok;
    }
    cout << ans << endl;
}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
		cin >> N >> M;

        cin >> s;

		solve();
    }

	return 0;
}