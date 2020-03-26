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

ll T;
vector<int> v;
string s;

void trata(){

    vector<int> c;
    map<int,int> m;

    FOR(i,0,sz(v)){
        c.pb(v[i]);
    }

    sort(all(c));

    FOR(i,0,sz(v)){
        m[c[i]] = i; 
    }

    FOR(i,0,sz(v)){
        v[i] =  m[v[i]];
    }
}

void le(){
    
    stringstream ss;

    ss << s;
    
    int a;
    
    while(ss >> a){
        v.push_back(a);
    }

    trata();
}

void imprimi(){

    FOR(i,0,sz(v)){
        cout << v[i] << " ";
    }
    cout << endl;
}

void solve(){
    vector<int> sol;
    
    int n = sz(v);

    for(int i=n-1 ; i ; i--){
        
        if(v[i] == i){
            continue;
        }else{
            if(v[0] != i){
                int pos = 0;
                while(v[pos++] != i);
                pos--;

                sol.pb(n - pos);
                
                reverse(v.begin(), v.begin() + pos + 1);

            }
            sol.pb(n - i);
            reverse(v.begin(), v.begin() + i + 1);
        }        
    }

    cout << s << endl;
    FOR(i,0,sz(sol)){
        cout << sol[i] << " ";
    }
    cout << 0 << endl;

}

int main(){

    while(getline(cin,s)){
        v.clear();
        le();
        solve();
    }

 	return 0;
}