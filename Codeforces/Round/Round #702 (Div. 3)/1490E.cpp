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
ll sum[MAXN];

bool f(int x){

	ll aux = sum[x+1];

	while(x + 1 < N){
		if(aux >= A[x + 1].fi){
            x++;
			aux = sum[x + 1];
        }
		else return false;
	}

	return true;
}

int bb(){
	int l = 0, r = N;

	while(l < r){
		int m = (l+r)/2;

		if(f(m)) 	r = m;
		else 		l = m + 1; 
	}

    return l;
}
void solve(){

	sort(A,A+N);

	for(int i=0;i<N;i++) sum[i+1] = sum[i] + A[i].fi;

	int ans = bb();

	cout << N - ans << endl;

    vector<int> ordem;

    for(int i=ans;i<N;i++) ordem.pb(A[i].se);

    sort(all(ordem));

    cout << ordem[0] + 1;
    for(int i=1;i<ordem.size();i++) cout << " " << ordem[i] + 1;
    cout << endl;
}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
		cin >> N;

		for(int i=0;i<N;i++) {
			cin >> A[i].fi;
			A[i].se = i;
		}
		
		solve();
    }

	return 0;
}