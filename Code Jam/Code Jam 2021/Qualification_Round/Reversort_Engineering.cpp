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
#define MAXN 123

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */
//Subtasks 1 - AC
//Subtasks 2 - AC

ll T,N,M,K;
vector<int> A;

bool f(){

	A.clear();

	if(M < N-1) return 0;

 	for(int i=1;i<=N;i++) A.pb(i);

 	int ptr = 0, ptr2 = N-1;
 	int menor = 1, maior = N, qtd = 0;

 	M = M - (N-1);

 	bool lado = false;

 	while(ptr <= ptr2){
		//cerr << pii(menor,maior) << " " << pii(ptr, ptr2) << " " << M << " ";
 		if(!lado){
			//cerr << 1 << endl;
 			if(M >= N - qtd - 1) {
				M = M - (N - qtd - 1) ;
 				A[ptr2--] = menor++;
 				lado ^= 1;
 			}
 			else {
 				A[ptr2--] = maior--;
 			}
 		}
 		else{
			//cerr << 2 << endl;
 			if(M >= N - qtd - 1) {
				M = M - (N - qtd - 1);
 				A[ptr++] = menor++;
 				lado ^= 1;
 			}
 			else {
 				A[ptr++] = maior--;
 			}
 		}

 		qtd++;

		//cerr << A << endl << endl;
 	}

 	return !M;
}

void solve(int caso){

    if(f()){
        cout << "Case #" << caso << ": ";
        for(int i=0;i<N;i++) cout << A[i] << " \n"[i==N-1];
    }
    else{
        cout << "Case #" << caso << ": IMPOSSIBLE\n";
    }
	
}

int main(){

	optimize;
	
	cin >> T;

    for(int i=1;i<=T;i++){
		cin >> N >> M;
		
		solve(i);
    }

	return 0;
}