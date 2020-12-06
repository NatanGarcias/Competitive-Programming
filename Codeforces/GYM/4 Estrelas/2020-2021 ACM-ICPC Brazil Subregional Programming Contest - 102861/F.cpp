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

#define sz(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;

int g[2], p[2];
bool saque;
string s;

void query(bool fim){
    if(fim){
        if(g[0] == 2)
            cout << g[0] << " (winner) - " << g[1] << endl; 
        else
            cout << g[0] << " - " << g[1] << " (winner)" << endl; 
    }
    else{
        if(!saque){
            cout << g[0] << " (" << p[0] << "*) - " << g[1] << " (" << p[1] << ')' << endl;
        }
        else{
            cout << g[0] << " (" << p[0] << ") - " << g[1] << " (" << p[1] << "*)" << endl;
        }
    }
}

void atualiza(int j){
    if(p[j] == 9 || (p[j] >= 4 && p[j] - p[j^1] >= 1)){
        p[j] = 0;
        p[j^1] = 0;

        g[j]++;
    }
    else{
        p[j]++;
    }
}

void solve(){

    //saque false é na esquerda

    int n = s.size();

    for(int i = 0; i < n ; i++){
        if(i == n-1 && s[i] == 'Q'){
            query(1);
        }
        else if(s[i] == 'Q'){
            query(0);
        }
        else if(s[i] == 'S'){
            atualiza(saque);
        }
        else{
            saque ^= 1;

            atualiza(saque);
        }
    }
}

int main(){

	optimize;
	
    cin >> s;
    
    solve();
    
	return 0;
}