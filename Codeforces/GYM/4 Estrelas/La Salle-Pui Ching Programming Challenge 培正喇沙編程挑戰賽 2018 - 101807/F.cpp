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
pii A[MAXN];
int p[MAXN], nums[MAXN], ansB, ansW;

void solveB(int j){
    
    ansB = 1;

    for(int i=0;i<N;i++){
        if(j == i)                   nums[i] = 0;
        else if(p[i] + 0 > p[j] + 3) nums[i] = 1, ansB++;
        else if(p[i] + 1 > p[j] + 3) nums[i] = 2;
        else if(p[i] + 3 > p[j] + 3) nums[i] = 3;
        else                         nums[i] = 4;
    } 

    for(int i=0;i<N/2;i++){
        if(nums[ A[i].fi ] == 2 && nums[ A[i].se ] == 2)      ansB++;
        else if(nums[ A[i].fi ] == 3 && nums[ A[i].se ] == 2) ansB++;
        else if(nums[ A[i].fi ] == 2 && nums[ A[i].se ] == 3) ansB++;
    }
}

void solveW(int j){
    
    ansW = N;

    for(int i=0;i<N;i++){
        if(j == i)                nums[i] = 0;
        else if(p[i] + 0 >= p[j]) nums[i] = 1;
        else if(p[i] + 1 >= p[j]) nums[i] = 2;
        else if(p[i] + 3 >= p[j]) nums[i] = 3;
        else                      nums[i] = 4, ansW--;
    } 

    for(int i=0;i<N/2;i++){
        if(nums[ A[i].fi ] == 3 && nums[ A[i].se ] == 3) ansW--;
        else if(nums[ A[i].fi ] == 3 && nums[ A[i].se ] == 2) ansW--;
        else if(nums[ A[i].fi ] == 2 && nums[ A[i].se ] == 3) ansW--;
    }
}

void solve(){
    
    for(int i=0;i<N;i++){
        solveB(i);
        solveW(i);

        cout << ansB << " " << ansW << endl;
    }
}

int main(){

	optimize;
	
	cin >> N;

    for(int i=0;i<N/2;i++) cin >> A[i].fi >> A[i].se, A[i].fi--, A[i].se--;

    for(int i=0;i<N;i++) {
        int a;
        cin >> p[i] >> a >> a;
    }

    solve();

	return 0;
}