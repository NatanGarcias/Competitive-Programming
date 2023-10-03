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
//Subtasks 1 - AC
//Subtasks 2 - AC
//Subtasks 3 - WA

ll T,N,M,K;
vector<pair<string,ll>> A;

string inverti(string &s){

    string ans;

    for(int i=0;i<s.size();i++){
        if(s[i] == 'T') ans.pb('F');
        else            ans.pb('T');
    }

    return ans;
}

void solve(int caso){
    
    string s;
    ll p,q;

    q = 1;
    
    if(N == 1){
        if(A[0].se * 2 >= M) {
            s = A[0].fi;
            p = A[0].se;
        }
        else{
            s = inverti(A[0].fi);
            p = M - A[0].se;
        }
    }
    if(N == 2){

        if(A[0].se * 2 < M){
            A[0].fi = inverti(A[0].fi);
            A[0].se = M - A[0].se;
        }

        if(A[1].se * 2 < M){
            A[1].fi = inverti(A[1].fi);
            A[1].se = M - A[1].se;
        }

        if(A[1].se >= A[0].se){
            s = A[1].fi;
            p = A[1].se;
        }
        else{
            s = A[0].fi;
            p = A[0].se;
        }
    }

	cout << "Case #" << caso << ": " << s << " " << p << '/' << q << endl;
}

int main(){

	optimize;
	
	cin >> T;

    for(int l=1;l<=T;l++){
		cin >> N >> M;

        A.resize(N);

        for(int i=0;i<N;i++) cin >> A[i].fi >> A[i].se;

		solve(l);

        A.clear();
    }

	return 0;
}