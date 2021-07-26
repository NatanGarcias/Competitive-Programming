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

int mov, impar;
bool esp;

void hanoi(int n, char a, char b, char c){

    if(n == 1){
        if(esp){
            esp = false;

            if(impar)   cout << "B C\n";
            else        cout << "C B\n";
        }
        else{
            cout << a << " " << c << endl;
        }
    }
    else{
        hanoi(n-1, a, c, b);
        cout << a << " " << c << endl;
        hanoi(n-1, b, a, c);
    }
}

void solve(){

    if(M < mov){
        cout << "N\n";
    }
    else{
        cout << "Y\n";

        while(M - 2 >= mov){
            cout << "A B\n";
            cout << "B A\n";

            M -= 2;
        }

        if(M > mov){
            esp = true;

            if(impar)   cout << "A B\n";
            else        cout << "A C\n";
        }

        hanoi(N, 'A', 'B', 'C');
    }
}

int main(){

	optimize;
	
	cin >> N >> M;
    
    mov = (1 << N) - 1;
    impar = N&1;

	solve();
    
	return 0;
}