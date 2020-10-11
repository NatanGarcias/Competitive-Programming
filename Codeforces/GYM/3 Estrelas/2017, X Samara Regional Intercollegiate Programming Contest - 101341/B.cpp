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

struct KMP{
    int m;
    string q;
    vector<int> lps;
    
    KMP(string &_q) : q{_q} {
        m = q.size();
        pre_process();
    }

    void pre_process(){
        lps.assign(m+1,-1);

        for(int i=0, j=-1; i<m ; ){
            while(j>=0 && q[i] != q[j]) j = lps[j];
            lps[++i] = ++j; 
        }
    }

    vector<int> match(string &p){
        vector<int> ans;

        ll n = p.size();

        if(n < m) return ans;

        for(int i=0,j=0; i<n ; ){
            while( j>=0 && p[i] != q[j]) j = lps[j];
            i++; j++;

            if(j == m){
                ans.push_back(i-j);
                j = lps[j];
            }
        }
        return ans;
    }
};

void solve(){

    string aux = "happiness";

    KMP kmp(aux);

    vector<int> ans = kmp.match(s);

    if(ans.size() == 0){
        cout << "YES\n";
        
        vector<int> l[26], dif;
        
        //7 0 15 8 13 4 18
        for(int i=0;i<s.size();i++){
            if( s[i] - 'a' != 7 &&  s[i] - 'a' != 0 && s[i] - 'a' != 15 && s[i] - 'a' != 8 &&  
                s[i] - 'a' != 13 &&  s[i] - 'a' != 4 &&  s[i] - 'a' != 18){
                    dif.push_back(i+1);
            }

            l[ s[i] - 'a' ].push_back(i+1);
        }

        for(int i=0;i<26;i++){
            if(l[i].size() >= 2){
                cout << l[i][0] << " " << l[i][1] << endl;
                return;
            }
        }

        if(dif.size() >= 2) {
            cout << dif[0] << " " << dif[1] << endl;
            return;
        }

        cout << "1 2\n";
        return;

    }
    else if(ans.size() == 1){
        cout << "YES\n";
        cout << ans[0]+1 << " " << ans[0]+2 << endl;
    }
    else if(ans.size() == 2){
        cout << "YES\n";
        cout << ans[0]+1 << " " << ans[1]+2 << endl; 
    }
    else if(ans.size() >= 3){
        cout << "NO\n";
    }

}

int main(){

	optimize;
	
	cin >> s;

	solve();
    
	return 0;
}