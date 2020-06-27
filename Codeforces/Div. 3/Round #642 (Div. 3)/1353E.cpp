#include<bits/stdc++.h>
using namespace std;

// Template 1
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
#define INF 0x3fffffff
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007
#define MAXN 1000090

int T,N,M,K;
int v[MAXN];
int dp[MAXN];
bool ok[MAXN];
string s;

int solve(int pos){

	if(pos + M >= N) return v[N-1] - v[pos];

	int aux = 0;

	if(s[pos] == '0') aux = 1;

	if(!ok[pos]){
		dp[pos] = aux + min(v[pos + M -1] - v[pos] + solve(pos+M), v[N-1] - v[pos]);
		ok[pos] = true;
	}

	return dp[pos];
}

void solve(){

	memset(dp,0, sizeof(int)*N);
	memset(ok,0, sizeof(bool)*N);

    int c = 0 , f = N-1;

    while(s[c] == '0' && c < N-1) c++;
    while(s[f] == '0' && f >= 0) f--;

    if(c>=f){
        cout << 0 << endl;
        return;
    }

    string s2(s.begin()+c, s.begin()+f+1);
    
    s = s2;    
    N = s.size();

    int cont = 0;
    
    FOR(i,0,N){
        if(s[i] == '1') cont++;
        v[i] = cont;
    }

    int ans = INF;
    cont = 0;

    for(int i=0;i<N;i++){
    	if(s[i] == '1'){
    		ans = min(ans, cont + solve(i));
    		cont++;
    	}
    }

    if(ans == INF) cout << 0 << endl;
    else cout << ans << endl;
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
