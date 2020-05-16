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

ll T,N,M,U;
vector<pair<string,string>> par;
int qual;

void solve(int caso){

    set<char> l;
    vector<vector<char>> mapa(11);

    FOR(i,0,10000){

        if(l.size() < 10){
            FOR(j,0,par[i].se.size()){
                l.insert(par[i].se[j]);
            }
        }
        if(par[i].fi.size() == par[i].se.size()){
            mapa[ (int) (par[i].fi[0] - '0') ].pb(par[i].se[0]);
        }
    }

    set<char> usei;
    vector<char> ans(10);

    FOR(i,1,10){
        FOR(j,0,sz(mapa[i])){
            if( usei.find(mapa[i][j]) == usei.end() ){
                usei.insert(mapa[i][j]);
                ans[i] = mapa[i][j];
            }
        }
    }

    for(auto i : l){
        if(usei.find(i) == usei.end()){
            ans[0] = i;
            break;
        }
    }

    cout << "Case #" << caso << ": ";
    FOR(i,0,10){
        cout << ans[i];
    } 
    cout << endl;
}

void solve2(int caso){

    set<char> l;

    FOR(i,0,10000){
        FOR(j,0,par[i].se.size()){
            l.insert(par[i].se[j]);
        }
        if(l.size() >= 10 ) break;
    }
        
    map<char,int> mapa;
    map<int,char> mapa2;

    int cont = 0;

    for(auto i : l ){
        mapa[i] = cont;
        mapa2[ cont++ ] = i;
    }

    vector<pair<ll,int>> prob(10);
    
    FOR(i,0,10){
        prob[i].se = i; 
    }

    FOR(i,0,10000){
        prob[ mapa[ par[i].se[0]] ].fi++;
    }

    sort(all(prob));

    vector<char> ans(10);
    ans[0] = mapa2[ prob[0].se ];

    cont = 1;
    for(int i=9 ; i>=1;i--){

        ans[i] = mapa2[ prob[cont++].se ];    
    }

    cout << "Case #" << caso << ": ";
    FOR(i,0,10){
        cout << ans[i];
    } 
    cout << endl;

}

int main(){

	cin >> T;

    FOR(i,1,T+1){
        cin >> U;

        qual == 1;

        par.clear();
        par.resize(10000);

        FOR(i,0,10000){
            string s,s2;
            
            cin >> s >> s2;

            if(!i && s[0] == '-'){
                qual = 2;
            }

            par[i] = make_pair(s,s2);
        }

        if(qual == 1){
            solve(i);
        }else{
            solve2(i);
        }
    }

	return 0;
}