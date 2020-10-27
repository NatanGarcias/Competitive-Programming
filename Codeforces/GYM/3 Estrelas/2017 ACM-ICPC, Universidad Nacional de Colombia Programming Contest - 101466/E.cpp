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
string s,s2;

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

    int match(string &p){
        int ans = 0;

        ll n = p.size();

        if(n < m) return ans;

        for(int i=0,j=0; i<n ; ){
            while( j>=0 && p[i] != q[j]) j = lps[j];
            i++; j++;

            if(j == m){
                ans++;
                j = lps[j];
            }
        }
        return ans;
    }
};

int bb(int x){

    int l = 1, r = x;
    
    while(l < r){
        int m = (l+r+1)/2;

        string s3(s2.begin(),s2.begin()+m);

        KMP kmp(s3);

        if( kmp.match(s) >= N){
            l = m;
        }
        else{
            r = m-1;
        }
    }

    return l;
}

void solve(){
    
    string s3(s2.begin(),s2.begin()+1);

    KMP kmp(s3);

    if( kmp.match(s) < N) {
        cout << "IMPOSSIBLE\n";
        exit(0);
    }
    else{
        string s4(s2.begin(),s2.begin()+bb(s2.size()));
        cout << s4 << endl;
    }
}

int main(){

	optimize;
    
    getline(cin,s);
    getline(cin,s2);

    cin >> N;

    solve();

	return 0;
}