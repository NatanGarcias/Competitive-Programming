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
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007
#define MAXN 2100

ll T,N,M,K;
string s;

ll dp[MAXN][MAXN];

void calc(){

    dp[0][0] = 1;
    
    FOR(i,1,2010){  
        FOR(j,0,i+1){
            ll aux = 0;

            if(j > 0) aux = dp[i-1][j-1];
            
            if(j < i) aux =  (aux + dp[i-1][j+1]) %mod;
            
            dp[i][j] = aux;
        }
    }
}

void solve(){
    
    int saldo = 0, menor = 0;

    FOR(i,0,sz(s)){
        if(s[i] == '(') saldo++;
        else saldo--;
        menor = min(menor,saldo);
    }

    calc(); 

    ll ans = 0;

    menor *= -1;

    for(int i=0;i<=N-M;i++){
        for(int j=menor;j<=i;j++){
            int tamQ = N-M-i;
            int balQ = saldo+j;

            if(balQ > tamQ) continue;
            
            ll aux = (dp[tamQ][balQ] * dp[i][j]) %mod;

            ans = (ans + aux) %mod; 
        }
    }
    cout << ans << endl;
}

int main(){

    optimize;

	cin >> N >> M;
	cin >> s;

	solve();
    
	return 0;
}