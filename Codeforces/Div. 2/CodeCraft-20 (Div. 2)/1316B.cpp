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

int T,N,M;
string S;
vector<int> esc;
int v[MAXN];

void verifica(int k, vector<pair<string,int>> &sol){

    string s;

    if(sz(S)%2){
        if(k%2){
            for(int i=k-1;i<sz(S);i++){
                s+=S[i];
            }
            for(int i=k-2;i>=0;i--){
                s+=S[i];
            }
        }else{
            for(int i=k-1;i<sz(S);i++){
                s+=S[i];
            }
            for(int i=0;i<k-1;i++){
                s+=S[i];
            }
        }
    }else{
        if(k%2){
            for(int i=k-1;i<sz(S);i++){
                s+=S[i];
            }
            for(int i=0;i<k-1;i++){
                s+=S[i];
            }
        }else{
            for(int i=k-1;i<sz(S);i++){
                s+=S[i];
            }
            for(int i=k-2;i>=0;i--){
                s+=S[i];
            }
        }
    }
    
    sol.push_back({s,k});
}

void solve(){

    vector<pair<string,int>> sol;

    FOR1(i,sz(S)){
        verifica(i, sol);
    }

    sort(all(sol));

    cout << sol[0].fi << endl << sol[0].se << endl;
}

int main(){

    cin >> T;

    while(T--){
        cin >> N >> S;

        solve();
    }

	return 0;
}