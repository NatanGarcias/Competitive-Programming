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
#define MAXN 110
#define MAXM 1010

ll T,N,M,K,A,B;

ld f(int x){
    
    ld m = (N+M)/2.0;
    
    m = (x-1)*m + N;
    m = m/((x) * 1.0);

    return fabs(m - ld(K) );
}

int ternarySearch(){

	int l = 1, r = 500001 , eps = 10E-13;

	while(r-l > 2){

		int m1 = l + (r-l)/3.0;
		int m2 = l + 2.0*( (r-l)/3.0 );

        int m3 = (m1-1)*2 +1;
        int m4 = (m2-1)*2 +1;

		ld f1 = f(m3);
		ld f2 = f(m4);

        if(f1 <= f2){
			r = m2 -1;
		}else{
			l = m1;
		}
	}

    int resp;
    ld dif = 1E10;

    FOR(i,l,r+1){
        ld aux = f( (i-1)*2 +1);

        if(aux < dif){
            resp = i;
            dif = aux;
        }
    }

    return resp;
}



void solve(){

    if(N == K){
        cout << 1 << endl;
        return;
    }else if( ld(K) - (ld(N+M))/2.0  < 1E-6){
        cout << 2 << endl;
        return;
    }
    
    int ans = ternarySearch();

    cout << (ans-1)*2 +1 << endl;
}

int main(){

	cin >> T;

    while(T--){
		cin >> N >> M >> K;

		solve();
    }

	return 0;
}