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
#define MAXN 15

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;

int n = 10, m = 10;
bool vis[MAXN][MAXN];

bool posValid(int x, int y){
    if(x < 1 || y < 1 || x > n || y > m) return false;
    return true;
}

void solve(){

}

int main(){

	optimize;
	
	cin >> N;
		
    for(int i=0;i<N;i++){
        int a,b,c,d;

        cin >> a >> b >> c >> d;

        int x,y;

        if(!a){
            for(int i=0;i<b;i++){
                if(!posValid(c,d+i) || vis[c][d+i]){
                    cout << "N\n";
                    exit(0);
                }
                else{
                    vis[c][d+i] = true;
                }
            }
        }
        else{
            for(int i=0;i<b;i++){
                if(!posValid(c+i,d) || vis[c+i][d]){
                    cout << "N\n";
                    exit(0);
                }
                else{
                    vis[c+i][d] = true;
                }
            }
        } 
    }   

    cout << "Y\n";

	return 0;
}