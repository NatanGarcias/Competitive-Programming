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

#define all(x) x.begin(),x.end()
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 1234567

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
int dp[MAXN][2], bt;
vector<pii> adj[18];

void preCalc(){
    for(int i=0;i<=15;i+=3){
        adj[i].pb(pii(i+1,i+2));
        adj[i+1].pb(pii(i,i+2));
        adj[i+2].pb(pii(i,i+1));
    }

    adj[2].pb(pii(4,6));
    adj[4].pb(pii(2,6));
    adj[6].pb(pii(2,4));

    for(int i=5;i<=8;i+=3){
        adj[i].pb(pii(i+5,i+7));
        adj[i+5].pb(pii(i,i+7));
        adj[i+7].pb(pii(i,i+5));
    }
}

int solve(int i, int j){

    if(i == (1 << 18) - 1) return 0;

    if(~dp[i][j]) return dp[i][j];

    int aux;
    if(j) aux = INF;
    else  aux = -INF;

    for(int k=0;k<18;k++){
        if(i & (1 << k)) continue;

        int cnt = 0;
        for(int m=0;m<adj[k].size();m++){
            if( (i & (1 << adj[k][m].fi) ) && (i & (1 << adj[k][m].se) ) ){
                cnt++;
            }
        }

        if(j){
            if(cnt) aux = min(aux, solve(i | (1 << k), 1) - cnt);
            else    aux = min(aux, solve(i | (1 << k), 0) );   
        }
        else{
            if(cnt) aux = max(aux, solve(i | (1 << k), 0) + cnt);
            else    aux = max(aux, solve(i | (1 << k), 1) );
        }
    }

    return dp[i][j] = aux;
}

void solve(){
    if(solve(bt,0) > 0)         cout << "Andy wins\n";
    else if(solve(bt,0) < 0)    cout << "Ralph wins\n";
    else                        cout << "Draw\n";
}

int main(){

	optimize;
	
    preCalc();

    ms(dp, -1);

    while(cin >> N && N){
        bt = 0;

        for(int i=0;i<N;i++) {
            int a;
            cin >> a;
            
            a--;

            bt |= (1 << a); 
        }

		solve();
    }

	return 0;
}