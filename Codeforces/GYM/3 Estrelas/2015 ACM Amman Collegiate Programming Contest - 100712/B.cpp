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
string str;
int sR[MAXN], sP[MAXN], sS[MAXN];

void solve(){

    for(int i = 0 ; i < N ; i++) {
        int r = 0, p = 0, s = 0;

        if(str[i] == 'R') r = 1;
        if(str[i] == 'P') p = 1;
        if(str[i] == 'S') s = 1;

        sR[i + 1] = sR[i] + r;
        sP[i + 1] = sP[i] + p;
        sS[i + 1] = sS[i] + s;
    }

    int ans = 0;

    for(int i = 0; i <= N ; i++){
        for(int j = 0; j <= N - i; j++){
            int  k = N - i - j;

            int aux = 0, aux2 = 0;
            aux += sS[i];
            aux += sR[j + i] - sR[i];
            aux += sP[N] - sP[j + i];

            aux2 += sR[i];
            aux2 += sP[j + i] - sP[i];
            aux2 += sS[N] - sS[j + i];

            if(aux > N - aux - aux2) ans++;
        }   
    }

    cout << ans << endl;
}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
		cin >> N >> str;

		solve();
    }

	return 0;
}