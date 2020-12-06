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
string s;

void solve(){

    string ansC, ansF, ansM;

    int ptr = 0, ptr2 = N-1;

    while(ptr < N && s[ptr] == '0'){
        ansC += '0';
        ptr++;
    }
    
    while(ptr2 >= 0 && s[ptr2] == '1'){
        ansF += '1';
        ptr2--;
    } 

    for(int i=ptr;i<=ptr2;i++){
        if(i == ptr) ansM.pb(s[i]);
        else{
            if(s[i] != ansM.back()) {
                ansM.pb(s[i]);
            }
            else{
                while(!ansM.empty() && ansM.back() == s[i]){
                    ansM.pop_back();
                }
                ansM.pb(s[i]);
            }
        }
    }

    string aux;
    if(ansM.empty()) aux = "";
    else if(ansM.size() & 1) aux = "01";
    else                aux = "0";

    cout << ansC + aux + ansF << endl;
}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
		cin >> N;

        cin >> s;
		
		solve();
    }

	return 0;
}