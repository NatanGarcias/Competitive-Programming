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
int A[MAXN], B[MAXN];
string s;

void clear(){
	memset(A, 0, sizeof(int) * N);
	memset(B, 0, sizeof(int) * N);
}

void menor(){
	
	s.pb('<');

	for(int i = 0, cnt = 1, cnt2 = N; i < N ; i++){

		int j = i, k, aux;

		while(j < N-1 && s[j] == '>') j++;

		k = j;

		while(k < N-1 && s[k] == '<') k++;

		aux = k-j;

		while(i != j){
			A[i++] = cnt2--;
		}

		while(i != k){
			A[i++] = cnt2-- - aux;
			aux -=2;
		}

		A[i] = cnt2-- - aux;
	}
}

void maior(){

	for(int i = 0, cnt = 1, cnt2 = N; i < N ; i++){

		if(s[i] == '<'){
			B[i] = cnt++;
		}
		else{
			
			int j = i, k, aux;

			while(j < N-1 && s[j] == '>') j++;

			k = j;

			while(k < N-1 && s[k] == '<') k++;

			aux = k-j;

			while(i != j){
				B[i++] = cnt2--;
			}

			while(i != k){
				B[i++] = cnt++;
			}
			i--;
		}
	}
}

void print(){

	cout << A[0];
	for(int i=1;i<N;i++){
		cout << " " << A[i];
	}
	cout << endl;

	cout << B[0];
	for(int i=1;i<N;i++){
		cout << " " << B[i];
	}
	cout << endl;
}

void solve(){

	clear();
	menor();
	maior();
	print();

}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
		cin >> N >> s;
		
		solve();
    }

	return 0;
}