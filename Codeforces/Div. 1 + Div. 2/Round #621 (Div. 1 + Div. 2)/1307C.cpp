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

#define PI 3.141592653589793238462643383279502884
#define FOR(x,n) for(int x=0;(x) < int(n);(x)++)
#define FOR1(x,n) for(int x=1;(x) <= int(n);(x)++)

#define INF 0x3fffffff
#define INFLL 0x3fffffffffffffff

#define mod %1000000007
#define MAXN 200010

vector<vector<int>> v(26);

ll quantos(int a, int b){
    
    ll ans = 0;
    ll jP = 0;

    for(int i=0;i<v[a].size();i++){
        for(int j=jP;j<v[b].size();j++){

            if(v[a][i] >= v[b][j]) {
                jP++;
            }
            else{
                ans+= v[b].size() - j; 
                j = v[b].size();
            }
        }
    }
    return ans;
}

int main(){

    string s;

    cin >> s;
    
    FOR(i,sz(s)){
        v[ ((int)s[i]) -97 ].push_back(i);
    }

    ll maior = -1;
    ll aux, aux2;

    FOR(i,sz(v)){
        aux = v[i].size();
        maior = max(maior, aux);
    }

    FOR(i,sz(v)){
        FOR(j,sz(v)){
            if(v[i].size() == 0 || v[j].size() == 0) continue;

            aux = quantos(i,j);
            maior = max(maior,aux);
        }
    }
    cout << maior << endl;

  	return 0;
}