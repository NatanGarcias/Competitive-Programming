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
#define MAXN 15

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K;
int nums[MAXN], esq[MAXN], dir[MAXN];
string s;

void preCalc(){

    nums[0] = 6; esq[0] = 2; dir[0] = 2;
    nums[1] = 2; esq[1] = 0; dir[1] = 2;
    nums[2] = 5; esq[2] = 1; dir[2] = 3;
    nums[3] = 5; esq[3] = 0; dir[3] = 2;
    nums[4] = 4; esq[4] = 3; dir[4] = 2;
    nums[5] = 5; esq[5] = 3; dir[5] = 1;
    nums[6] = 6; esq[6] = 2; dir[6] = 1;
    nums[7] = 3; esq[7] = 0; dir[7] = 2;
    nums[8] = 7; esq[8] = 2; dir[8] = 2;
    nums[9] = 6; esq[9] = 3; dir[9] = 2;
}

void solve(){

    int x = s[0] - '0';
    int y = s[1] - '0';
    int desc = 0;

    if(x != 1 && dir[x] == esq[y]){
        if(esq[y] == 2) desc = 2;
        else if(esq[y]) desc = 1;
    }

    cout << nums[x] + nums[y] - desc << endl;    
}

int main(){

	optimize;
	
	cin >> T;

    preCalc();
    
    while(T--){
		cin >> s;
		
		solve();
    }

	return 0;
}