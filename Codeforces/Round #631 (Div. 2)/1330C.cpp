#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld; 

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define endl "\n"
#define space " " 

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
#define MAXN 200010

int T,N,M,X;
int v[MAXN];

void solve(){

    //Colocando todos os intervalors

    vector<int> ans(M);

    FOR(i,0,M){
        int posM = N - v[i] +1;

        if(i+1 > posM) {
            cout << -1 << endl;
            return;
        } 

        ans[i] = i+1;
    }

    int aux = N;
    //Caso ainda tenho espaço sobrando deslizo com o restante
    for(int i = M-1; i >=0 ;i--){
        if(ans[i] + v[i] > aux) break;

        if(!i) {
            cout << -1 << endl;
            return;
        }

        ans[i] = aux - v[i] +1;

        aux = aux - v[i];
    }

    FOR(i,0,sz(ans))    cout << ans[i] << " \n"[i == sz(ans)-1];
}

int main(){

    optimize;
    
    cin >> N >> M;

    FOR(i,0,M){
        cin >> v[i];
    }
    solve();

	return 0;
}