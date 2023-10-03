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
#define FOR(x,a,n) for(int x= (int)(a);(x) < int(n);(x)++)
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 1010
#define MAXM 10010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
int v[MAXN];
ll dp[MAXN][2*MAXM];

const int zero = 10000;

void solve(){

	ll ans = 0;

    //Para cada posição
	FOR(i,0,N){

        //Marco que eu consigo uma substring de soma 1 para o tamanho i (substring vazia)
        dp[i][zero]++;
        
        //Para cada valor que eu estou
        FOR(j,0,20001){
            if(dp[i][j]){
                ll aux = 0;

                //Atualizo a quantidade de vezes que chego naquele posição na dp
                dp[i+1][ j + v[i] ] = (dp[i+1][ j + v[i] ] + dp[i][j]) %mod;
                dp[i+1][ j - v[i] ] = (dp[i+1][ j - v[i] ] + dp[i][j]) %mod;
            }
        }

        //Adiciono a resposta a quantidade se substrings de soma 0 eu tenho
        ans += dp[i+1][zero];
        ans %= mod;
	}

	cout << ans << endl;
}

int main(){

    cin >> N;

    FOR(i,0,N) cin >> v[i];

    solve();

	return 0;
}