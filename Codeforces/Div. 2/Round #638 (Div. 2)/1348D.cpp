#include<bits/stdc++.h>
using namespace std;

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
#define MAXN 200010

ll T,N,M,K;

void imprimi(vector<int> &resp){
    FOR(i,0,sz(resp)) cout << resp[i] << " \n"[i==sz(resp)-1];
}

void solve(){

    int ans = log2(N);

    cout << ans << endl;

    vector<int> resp(ans,0);
    
    if( !(N - (1 << ans)) ){
        FOR(i,1,ans){
            resp[i] = (1 << (i-1));
        }   
        imprimi(resp);
        return;
    }

    int falta = N - ans*2 -1;

    resp[0] = 1;

    int maior = 2;
 
    FOR(i,1,ans){

        int aux = falta / (ans-i);

        if(aux > maior){
            resp[i] = maior;
            falta -= maior*(ans-i);
            maior += maior;                
        }else if( (ans-i) * aux == falta ) {
            resp[i] = aux;
            falta = 0;
            break;
        }else{
            resp[i] = aux;
            falta -= aux*(ans-i);
            maior += aux;                
        }
    }

    imprimi(resp);
    return;
}

int main(){

    optimize;

	cin >> T;

    while(T--){
        cin >> N;

        solve();
    }

	return 0;
}