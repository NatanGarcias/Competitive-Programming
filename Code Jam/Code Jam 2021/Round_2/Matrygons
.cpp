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
#define MAXN 1123456

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;

bool p[MAXN];
vector<int> primos;

void crivo(){

    for(ll i=2;i<MAXN;i++){
        if(i == 4) primos.pb(4);
        if(!p[i]){
            if(i != 2) primos.pb(i);
            for(ll j=i*i;j<MAXN;j+= i) p[j] = true;
        }
    }
}

int f(int m){
    int aux = 0;
    for(int i = 30;i>=0;i--){
        if( m & (1LL << i) ) aux++;
    }

    return aux;
}

vector<int> fatoracao(int n){

    vector<int> fat;

    for(int i=0;i<primos.size() && primos[i] <= n;i++){
        int j = primos[i]; 
        while(n > 1 && !(n % j) ){
            fat.pb(j);
            n /= j;
        }
    }
    
    return fat;
}

int fatoracao2(int n){

    if(n == 2) return 1;
    vector<int> fat;

    for(int i=0;i<primos.size() && primos[i] <= n;i++){
        int j = primos[i]; 
        while(n > 1 && !(n % j) ){
            fat.pb(j);
            n /= j;
        }
    }

    return fat.size();
}

void solve(int caso){

    vector<int> fat = fatoracao(N);

    int ans = 1;

    for(int i=1;i<fat.size();i++){
        ans += fatoracao2(fat[i] - 1);
    }

	cout << "Case #" << caso << ": " << ans << endl;
}

int main(){

	optimize;

    crivo();

	cin >> T;

    for(int l=1;l<=T;l++){
		cin >> N;
		
		solve(l);
    }

	return 0;
}