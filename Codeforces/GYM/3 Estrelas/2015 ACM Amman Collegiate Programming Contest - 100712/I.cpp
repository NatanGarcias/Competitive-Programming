#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

#define fi first 
#define se second 
#define pb push_back

#define all(x) x.begin(),x.end()
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 2010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;

string s;
int rem[MAXN];

void solve(){

    for(int k = N - 1; k >= 1 ; k--){
        for(int i = 0; i <= 9 ; i++){
        
            int add = 0;
            ms(rem, 0);

            bool ok = true;

            for(int j = 0; j < N ; j++) {
                if(j + k <= N){
                    add -= rem[j];

                    int currDig = (s[j] - '0' + add) % 10;
                    int falta   = (10 - currDig + i) % 10;

                    add        += falta;
                    rem[j + k] += falta;
                }
                else{
                    add -= rem[j];
                    if( ((s[j] - '0' + add) % 10) != i) ok = false;   
                }
            }

            if(ok){
                cout << k << endl;
                return;
            }
        }
    }
}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
		cin >> s;

        N = s.size();
		
		solve();
    }

	return 0;
}