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
#define INF 0x3f3f3f3f
#define MAXN 1010

ll N,C,A,B;
int v[MAXN];
int dp[MAXN];
bool ok[MAXN];

ll solve(vector<ll> &valores, set<pii> &pos, int p){

    if(p >= N) return 0;

    if(!ok[p]){
        dp[p] = min( solve(valores,pos, (*pos.lower_bound(pii(valores[p] + A, +INF))).se ) + A , 
                 solve(valores,pos, (*pos.lower_bound(pii(valores[p] + B, +INF))).se ) + B);
        ok[p] = true;
    }
    return dp[p]; 
}

void solve(){

    ll ans = INF;

    //Para cada ponto que escolher para começar
    for(int i=0;i<N;i++){
        memset(ok,0,sizeof(ok));

        vector<ll> valores(N,0);
        set<pii> pos;
        
        pos.insert(pii(INF,INF));
        ll sum = 0;
        int cont = 0;

        for(int j=i;j<N;j++){
            sum = v[j];

            pos.insert(pii(sum,cont));
            valores[cont++] = sum;
        }

        for(int j=0;j<i;j++){
            sum = v[j] + C;

            pos.insert(pii(sum,cont));
            valores[cont++] = sum;
        }

        ans = min( ans , solve(valores,pos,0));
    }

    cout << ans << endl;
}

int main(){

    optimize;

    cin >> N >> C >> A >> B;

    for(int i=0;i<N;i++) cin >> v[i];

    solve();

	return 0;
}