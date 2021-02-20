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
string s;
const ld EPS = 1e-9; 

void solve(){

	string s2;

	s2 = s;

	for(ld x = 0.0; x <= 2; x += 0.1){
		
		stack<ld> pilha;
		stringstream ss;
		
		ss << s2;
		ss >> N;
	
		for(int i=0;i<N;i++){
			ss >> s;

			if(s == "+"){
				ld a = pilha.top();
				pilha.pop();

				ld b = pilha.top();
				pilha.pop();

				pilha.push(a + b);
			}
			else if(s == "-"){
				ld a = pilha.top();
				pilha.pop();

				ld b = pilha.top();
				pilha.pop();

				pilha.push(b - a);
			}
			else if(s == "*"){
				ld a = pilha.top();
				pilha.pop();

				ld b = pilha.top();
				pilha.pop();

				pilha.push(a * b);
			}
			else if(s == "x"){
				pilha.push(x);
			}
			else if(s == "sin"){
				ld a = pilha.top();
				pilha.pop();

				pilha.push( sin(a) );
			}
			else if(s == "cos"){
				ld a = pilha.top();
				pilha.pop();

				pilha.push( cos(a) );
			}
			else if(s == "tan"){
				ld a = pilha.top();
				pilha.pop();

				pilha.push( tan(a) );
			}
		}

		if( fabs(pilha.top()) > EPS){
			cout << "Not an identity\n";
			return;
		}
	}

	cout << "Identity\n";
}

int main(){

	while(getline(cin,s)){
		if(s[0] == '0') 	break;
	
		solve();
	}

	return 0;
}