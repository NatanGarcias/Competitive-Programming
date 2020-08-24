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

void drop(int a, int b){
    cout << "DROP " << a << " " << b << endl;
}

void take(int a, int b){
    cout << "TAKE " << a << " " << b << endl;
}

void move(int a){
    cout << "MOVE 1->2 " << a << endl;
}

void solve(){

    string s;
    int m;

    int ptr = 0, ptr2 = 0;

    FOR(i,0,N){
        cin >> s >> m;
    
        if(s[0] == 'D'){
            ptr += m;
            drop(1,m);
        }else{
            if(ptr2 >= m){
                take(2,m);
                ptr2 -= m;
            }else{
                if(ptr2) {
                    take(2,ptr2);
                    m -= ptr2;
                    ptr2 = 0;
                }

                move(ptr);
                
                ptr2 = ptr-m;
                ptr = 0;

                take(2,m);
            }
        }
    }
}

int main(){

	optimize;
    
    bool ok = false;
    while(cin >> N){
        if(ok && N) cout << "\n";

        solve();

        ok = true;
    }

	return 0;
}