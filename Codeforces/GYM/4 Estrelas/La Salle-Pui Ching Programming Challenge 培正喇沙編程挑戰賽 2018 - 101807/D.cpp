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
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
string s, ans;
int sinal, num, x, pot;

void f(){
    if(!x) return;

    if (sinal == -1)        ans.pb('-');
    else if(sinal ==  1)    ans.pb('+');

    if(num == 0) num = 1;
    
    int potC = pot;
    
    if(!potC) potC = 1;

    int a = num * potC;

    string aux = to_string(a);

    ans += aux;

    if(pot > 1) ans.pb('x');

    aux = to_string(pot - 1);

    if(pot > 2) ans += aux;
}

void solve(){

    int i = 0;
    
    N = s.size();

    while(i < N){
        sinal = 0, num = 0, x = 0, pot = 0;

        if(s[i] == '+')         sinal = 1, i++;
        else if(s[i] == '-')    sinal = -1, i++;

        while(i < N && s[i] >= '0' && s[i] <= '9'){
            num *= 10;
            num += (s[i] - '0');
            i++;
        }

        if(i < N && s[i] == 'x') i++, x = 1;

        while(i < N && s[i] >= '0' && s[i] <= '9'){
            pot *= 10;
            pot += (s[i] - '0');
            i++;
        }

        f();
    }

    if(ans.empty()) cout << "0\n";
    else            cout << ans << endl;
}

int main(){

	optimize;
    
    getline(cin, s);

    solve();

	return 0;
}