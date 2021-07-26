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
#define MAXN 110
#define MAXM 10

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */

ll T,N,M,K,A,B;
char m[MAXM][MAXN];
int ans;

void print(){
    if(ans == -1) cout << "Impossible" << endl;
    else{
        cout << "Possible" << endl;
        for(int j=0;j<3;j++){
            for(int i=0;i<N;i++) cout << m[j][i];
            cout << endl;
        }
    }
    exit(0);
}

void solve(){

    A--, B--;

    for(int j=0;j<3;j++) for(int i=0;i<N;i++) m[j][i] = '.';

    m[1][0] = 'X';
    m[0][A] = 'A';
    m[2][B] = 'B';
             
    if(!A || !B ) {
        if(A != B) ans = -1;
        print();
    }

    if(A == B) print();
    if(abs(A-B)&1) ans = -1, print();

    int qtd = abs(B-A) / 2;

    if(A == 1 || B == 1) if(qtd == 1) ans = -1, print();

    for(int i = min(A,B) -1 ;i< min(A,B) -1  + qtd;i++) if(i) m[1][i] = '*';

    if(A > B) m[2][B-1] = '*';
    else      m[0][A-1] = '*';
 
    print();
}

int main(){

	optimize;
	
	cin >> N >> A >> B;
		
	solve();
    
	return 0;
}