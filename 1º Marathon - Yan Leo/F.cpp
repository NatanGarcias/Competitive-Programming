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

int X,Y,N,M;

void solve(){

    vector<pii> sol;

    sol.pb(pii(1,1));

    int x = 1, y =1;

    while(y < M){
        y++;
        sol.pb(pii(x,y));
    }  

    while(x < N){
        x++;
        sol.pb(pii(x,y));
    }  

    int sobe = true;
    while(true){
        y--;
        
        sol.pb(pii(x,y));

        if(sobe){
            while(x > 2){
                x--;
                sol.pb(pii(x,y));
            }
            sobe = false;
        }else{
            sobe = true;
            while(x < N){
                x++;
                sol.pb(pii(x,y));
            }
        }

        if(y==1){
            break;
        }   
    }

    int pos = 0;
    while( X != sol[pos].fi || Y != sol[pos].se ) pos++;

    FOR(i,pos,sz(sol)){
        cout << sol[i].fi << " " << sol[i].se << endl;
    }

    FOR(i,0,pos){
        cout << sol[i].fi << " " << sol[i].se << endl;
    }

    cout << X << " " << Y << endl;
}

int main(){

    optimize;
    
	cin >> N >> M;
	cin >> X >> Y;

    solve();
	return 0;
}