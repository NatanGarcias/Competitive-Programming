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

string A,B;

void maior(){
    cout << ">\n";
    exit(0);
}

void menor(){
    cout << "<\n";
    exit(0);
}

void igual(){
    cout << "=\n";
    exit(0);
}

void solve(){

    N = A.size();
    M = B.size();

    for(int i=0;i<N;i++){
        if(A[i] >= 'a' && A[i] <= 'z'){
            if(A[i] > B[i]) maior();
            else if(B[i] > A[i]) menor(); 
        }
        else{
            string C,D;

            int ptr = i, ptr2 = i;
            
            while(ptr < N && A[ptr] >= '0' && A[ptr] <= '9') {
                C.push_back(A[ptr]);
                ptr++;
            }

            while(ptr2 < M && B[ptr2] >= '0' && B[ptr2] <= '9') {
                D.push_back(B[ptr2]);
                ptr2++;
            }

            if(C.size() != D.size()){
                if( C.size() > D.size() ) maior();
                else menor();
            }

            if(C > D) maior();
            else if(D > C) menor();

            i = ptr -1;
        }
    }

    igual();
}

int main(){

	optimize;
	
    cin >> A >> B;

	solve();
    
	return 0;
}