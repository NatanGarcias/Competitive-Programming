#include<bits/stdc++.h>
using namespace std;

// Template 1
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld; 

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

#define pii pair<int,int>
#define fi first 
#define se second 
#define pb push_back

#define sz(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define FOR(x,a,n) for(int x= (int)(a);(x) < int(n);(x)++)
#define ms(x,a) memset(x,a,sizeof(x))

#define PI 3.141592653589793238462643383279502884
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007
#define MAXN 100010

ll T,N,M,K;
int v[MAXN];
int v2[MAXN];

void solve(){

    int sum = 0;

    int c = 0, cont = 0;

    int ptr,ptr2,tm = INF;

    for(int i=1;i<=N;i++){
        
        int a;

        if(sum < M){
            a = v[i-1];

            if(!v2[a]) sum++;

            v2[a]++;
            
            if(sum == M){
                if((i-(c+1)) < tm){
                    ptr = c+1;
                    ptr2 = i;
                    tm = (i-(c+1));
                }
            }

        }else{
            int nums = v2[v[cont]];

            v2[v[cont]]--;

            if(nums == 1) sum--;

            c++;
            cont++;

            if(sum == M){
                if((i-1-(c+1)) < tm){
                    ptr = c+1;
                    ptr2 = i-1;
                    tm = (i-1-(c+1));
                }
            }
            i--;
        }   
	}

    for(int i=cont;i<=N;i++){
        int nums = v2[v[cont]];

        v2[v[cont]]--;

        if(nums == 1) sum--;

        c++;
        cont++;

        if(sum == M){
            if((N-(c+1)) < tm){
                ptr = c+1;
                ptr2 = N;
                tm = (N-(c+1));
            }
        }else break;
    }

    if(tm == INF) cout << -1 << " " << -1 << endl;
    else  cout << ptr << " " << ptr2 << endl;
}

int main(){

    optimize;

	cin >> N >> M;
	
    FOR(i,0,N) cin >> v[i];
	solve();
    
	return 0;
}