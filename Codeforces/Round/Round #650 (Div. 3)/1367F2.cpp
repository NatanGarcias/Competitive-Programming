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

int v[MAXN], v2[MAXN], comp[MAXN];

int bb(int x, int y, vector<vector<int>> &pos){
    if(y < 0) return -1;
    
    int p = lower_bound(all(pos[y]), x) - pos[y].begin();

    if(!p) return -1;
    return pos[y][p-1];
}

void solve(){

    sort(v2,v2+N);
    int n = unique(v2,v2+N) - v2;

    vector<int> dp(N,0), dp2(N,0);
    vector<int> ocor(N,0), qtd(N,0);
    vector<vector<int>> pos(n,vector<int>());

    for(int i=0;i<N;i++) {
        comp[i] = lower_bound(v2,v2+n,v[i]) - v2;
        qtd[ comp[i] ]++;
        pos[ comp[i] ].pb(i);
    }

    int ans = 0;

    //dp[i] maior subsequencia classificada até a posição i
    //dp2[i] maior até a posição i que usa o máximo de elementos até a posição i

    for(int i=0;i<N;i++){

        //Calculando dp
        //Caso ainda tenha v[i]-1 depois dele
        if(comp[i] > 0 && qtd[comp[i]-1] != ocor[comp[i]-1]){
            //dp igual ao máximo entre a quantidade de vezes que v[i]-1 apareceu, 
            //e a dp da última ocorrencia de v[i];
            
            dp[i] = ocor[comp[i] -1] + 1;

            if(ocor[comp[i]]){
                int aux = bb(i,comp[i], pos);

                if(~aux) dp[i] = max(dp[i], dp[aux] + 1);
            }
        }
        else{
            //dp igual ao máximo entre a dp na última ocorrência de v[i]
            //e a dp2 da última ocorrencia de v[i]-1    ;
            
            int aux = bb(i, comp[i], pos);
            int aux2 = bb(i, comp[i]-1, pos);

            dp[i] = 1;
            if(~aux) dp[i] = max(dp[i], dp[aux] + 1);
            if(~aux2) dp[i] = max(dp[i], dp2[aux2] + 1);
        }

        //Calculando dp2
        //Primeira vez que v[i] aparece
        if(!ocor[comp[i]]){
            //dp2 igual ao máximo entre a quantidade de vezes que v[i]-1 apareceu, 
            //e a dp2 da última ocorrencia de v[i];

            dp2[i] = 1;
            if(comp[i] > 0 && qtd[comp[i]-1] != ocor[comp[i]-1])
                dp2[i] = max(dp2[i],ocor[comp[i]-1] + 1);
            else{            
                int aux = bb(i,comp[i]-1, pos);

                if(~aux) dp2[i] = max(dp2[i], dp2[aux] + 1);
            }
        }
        else{
            //dp2 é igual a a dp2 na última ocorrência de v[i], +1
            int aux = bb(i, comp[i], pos);

            dp2[i] = 1;
            if(~aux) dp2[i] = max(dp2[i], dp2[aux] + 1);
        }

        ocor[ comp[i] ]++;
        ans = max(ans, dp[i]);
    }

    cout << N - ans << endl;
}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
		cin >> N;

        for(int i=0;i<N;i++){
            cin >> v[i];
            v2[i] = v[i];
        }

		solve();
    }

	return 0;
}