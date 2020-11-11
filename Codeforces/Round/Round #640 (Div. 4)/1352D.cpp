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
#define MAXN 200010

ll T,N,M;
int v[MAXN];

void solve(){

    int ptr = 0;
    int ptr2 = N-1;

    int docesA = 0;
    int docesB = 0;

    int sumA = 0, sumB = 0;
    bool quem = true;

    int jogadas = 0;

    while(ptr <= ptr2){

        jogadas++;

        if(quem){
            int aux = 0;
            while(ptr <= ptr2 && aux <= docesB){
                aux += v[ptr];
                ptr++;
            }
            sumA += aux;

            docesA = aux;
        }else{
            int aux = 0;
            while(ptr <= ptr2 && aux <= docesA){
                aux += v[ptr2];
                ptr2--;
            }
            sumB += aux;

            docesB = aux;
        }

        quem = quem ^ 1;
    }

    cout << jogadas << " " << sumA << " " << sumB << endl;
}

int main(){

	cin >> T;

    while(T--){
		cin >> N;
		
        FOR(i,0,N) cin >> v[i];

		solve();
    }

	return 0;
}