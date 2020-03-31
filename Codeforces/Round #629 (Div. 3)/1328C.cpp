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

#define FOR(x,a,n) for(int x= (int)(a);(x) < int(n);(x)++)
#define ms(x,a) memset(x,a,sizeof(x))

#define PI 3.141592653589793238462643383279502884
#define INF 0x33ffffff
#define INFLL 0x33ffffffffffffff

#define mod %1000000007

#define MAXN 200010

string s;
ll T,N;

void solve(){

    string a;
    string b;
    bool entrei = false;

    FOR(i,0,N){
        if(!i){
            a.push_back('1');
            b.push_back('1');
        }else{
            if(s[i] == '2'){
                if(entrei){
                    a.push_back('0');
                    b.push_back('2');
                }else{
                    a.push_back('1');
                    b.push_back('1');
                }
            }else if(s[i] == '1'){
                if(!entrei){
                    a.push_back('1');
                    b.push_back('0');
                    entrei = true;
                }else if (entrei){
                    a.push_back('0');
                    b.push_back('1');
                }
            }else{
                a.push_back('0');
                b.push_back('0');
            };
        }
    }

    cout << a << endl << b << endl;
}
int main(){

	cin >> T;

	while(T--){
		cin >> N;		
        cin >> s;       
        solve();            
	}

	return 0;
}