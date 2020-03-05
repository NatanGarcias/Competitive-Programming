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
#define FOR(x,n) for(int x=0;(x) < int(n);(x)++)
#define FOR1(x,n) for(int x=1;(x) <= int(n);(x)++)

#define INF 0x3fffffff
#define INFLL 0x3fffffffffffffff

#define mod %1000000007

#define MAXN 200010
#define MAXM 2029
#define MAXL 20

ll N,M,T;

int v[MAXN];
int v2[MAXN];
string s;

ll diminui(string &s, int x){

    ll ans = 0;
    char k = (char)x;

    vector<int> tira;

    for(int i = 0;i< s.size();i++){
        if(s[i] == (char)k){
            if(i>0){
                if(s[i-1] == k-1){
                    tira.push_back(i);
                }
            }
            if(i <= s.size()){
                if(s[i+1] == (char)(k-1)){
                    tira.push_back(i);
                }
            }
        }
    }

    int cont = 0;

    for(int i=0;i<tira.size();i++){
        if(i>0 && tira[i] == tira[i-1]) continue;
        s.erase(s.begin() + tira[i] - cont);
        ans++;
        cont++;
    }

    return ans;

}


void solve(){
    ll ans = 0;
    
    for(int i = 122;i>=97;i--){
        for(int j = 122;j>= i;j--){
            if(s.empty()){ 
                return;
            }
            ll temp = ans;
            ans +=diminui(s,j);
            while(temp != ans){
                temp = ans;
                ans +=diminui(s,j);
            }
        }
    }
    cout << ans << endl;

}
int main(){

	cin >> T;

    cin >> s;

    solve();

	return 0;
}