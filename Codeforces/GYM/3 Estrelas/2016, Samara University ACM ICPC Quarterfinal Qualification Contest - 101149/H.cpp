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
#define FOR(x,a,n) for(int x= (int)(a);(x) < int(n);(x)++)
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
string s;

void solve(){
    
    int eq = 0, per = 0;
    
    N = s.size();

    for(int i=N-1;i>=0;i--){
        if(s[i] == '(') eq++;
        else if(s[i] == ')') eq--;
        else per++;
    }

    int eq2 = 0;

    FOR(i,0,N){

        if(s[i] == '?'){
            if(eq2<=0 || per > eq) s[i] = '(';
            else s[i] = ')'; 

            if(s[i] == '(') eq++;
            else if(s[i] == ')') eq--;
            
            per--;
        }

        if(s[i] == '(') eq2++;
        else if(s[i] == ')') eq2--;

        if(eq2< 0){
            cout << "Impossible\n";
            return;
        }
    }

    if(eq2){
        cout << "Impossible\n";
        return;
    }

    cout << s << endl;
}

int main(){

	optimize;
	
	cin >> s;

	solve();

	return 0;
}