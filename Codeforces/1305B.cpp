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

int T,N,M;

int v[MAXM];
int v2[MAXM];
string S;

void solve(){

    int ptr = 0;
    int ptr2 = sz(S)-1;

    vector<int> sol;
    int cont = 0;

    while(ptr<ptr2){
        while(ptr<ptr2 && S[ptr] != '('){
            ptr++;
        }
        while(ptr<ptr2 && S[ptr2] !=')'){
            ptr2--;
        }
        
        if(ptr >= ptr2){
            break;
        }else{
            cont+=2;

            sol.pb(ptr+ cont/2);
            sol.pb(ptr2 + cont/2);

            S.erase(S.begin()+ptr);
            S.erase(S.begin()+ptr2-1);

            ptr2-= 2;
        }
    }

    if(sol.empty()){
        cout << 0 << endl;
    }else{
        cout << 1 << endl;
        cout << cont << endl;
        sort(all(sol));

        for(int  i = 0 ; i< sz(sol) ; i++){
            cout << sol[i] << " \n"[i==sz(sol)-1];
        }
    }

}

int main(){

	cin >> S;

    solve();	
	return 0;
}