#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;

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
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
pii A[MAXN][2];

bool f(ld x){
    
    ld sum = 0.0;

    for(int i=0;i<N;i++){
        ld aux = A[i][0].se - A[i][0].fi * x;
        ld aux2 = A[i][1].se - A[i][1].fi * x;

        if(aux < aux2) swap(aux, aux2);

        sum += aux;
    }

    return sum >= 0.0;
}

ld bb(){
    ld l = 0.0, r = 1E17;

    for(int i=0;i<100;i++){
        ld m = (l+r)/2.0L;

        if(f(m))    l = m;
        else        r = m;
    }

    return l;
}

void solve(){
    cout << fixed << setprecision(10) << bb() << endl; 
}

int main(){

	optimize;
	
	cin >> N;

	for(int i=0;i<N;i++){
        for(int j=0;j<2;j++){
            cin >> A[i][j].fi >> A[i][j].se;
        }
    }

	solve();

	return 0;
}