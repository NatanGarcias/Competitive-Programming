#include<bits/stdc++.h>
using namespace std;

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
#define ms(x) memset(x,0,sizeof(x))
#define ms2(x) memset(x,-1,sizeof(x))

#define PI 3.141592653589793238462643383279502884
#define FOR(x,a,n) for(int x= (int)(a);(x) < int(n);(x)++)

#define INF 0x3fffffff
#define INFLL 0x3fffffffffffffff

#define mod %1000000007

#define MAXN 200010

ll v[MAXN];
int T,N,M;
vector<pii> m;

void pre(){

    m.push_back({-1,+1});
    m.push_back({-1,0});
    m.push_back({0,-1});
    m.push_back({+1,-1});
    m.push_back({+1,0});
    m.push_back({0,+1});
    
    int ans = 2;
    int cont = 0;

    v[0] = 1;

    while(ans < 100010){
        v[++cont] = ans;

        ans +=(6*(cont));
    }

}

void imprimi(pii p){
    cout << p.fi << " " << p.se << endl;
}

void anda(int i, pii &p){
    p.fi += m[i].fi;
    p.se += m[i].se;
}

void andar(int c, pii &p){

    int maior = p.fi+1;
    int t = p.fi+1;

    int r = t-1;
    int i = 0;

    while(c > 0){

        while(c > 0 && r>0){
            c--;
            r--;
            anda(i, p);
        }
        
        if(r == 0){
            r = t;
            i++;
        }

    }

    imprimi(p);
}

void solve(){

    if(T == 1){
        cout <<"0 0" << endl;
        return;
    }

    int pos = 0;
    int c = T;

    while(v[++pos] <= c);

    pos--;
    c -= v[pos];    

    pii p = make_pair(pos-1,1);
    
    andar(c,p);
}

int main(){

    pre();

    while(cin >> T){
        solve();
    }   

	return 0;
}