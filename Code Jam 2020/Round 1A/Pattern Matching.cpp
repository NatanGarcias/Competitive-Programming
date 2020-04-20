#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld; 

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define endl "\n"
#define space " " 

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
#define MAXN 55

ll T,N,M;
string v[MAXN];
string com, fim, meio;

void processC(string s){

	if(com.empty()){
		com = s;
	}else if(sz(com) == sz(s)){
		if(com != s) com = "* "; 
	}else if(sz(com) > sz(s)){
		FOR(i,0,sz(s)){
			if(com[i] != s[i]) com = "* "; 
		}
	}else if(sz(com) < sz(s)){
		FOR(i,0,sz(com)){
			if(com[i] != s[i]) com = "* "; 
		}
		if(com != "* ") com = s;
	}
}

void processF(string s){
	if(fim.empty()){
		fim = s;
	}else if(sz(fim) == sz(s)){
		if(fim != s) fim = "* "; 
	}else if(sz(fim) > sz(s)){
		int comeco = sz(fim) - sz(s);
		FOR(i,0,sz(s)){
			if(fim[i+comeco] != s[i]) fim = "* "; 
		}
	}else if(sz(fim) < sz(s)){
		int comeco = sz(s) - sz(fim);
		FOR(i,0,sz(fim)){
			if(fim[i] != s[i+comeco]) fim = "* "; 
		}
		if(fim != "* ") fim = s;
	}
}

void solve(int caso){

	com.clear(), fim.clear();
	meio.clear();

	FOR(i,0,N){
		string temp = v[i];

		vector<int> posA;

		bool beg = true;
		
		string aux;
		
		FOR(j,0,sz(temp)){
			if(!j && temp[j] == '*'){
				beg = false;
			}else if(temp[j] =='*'){
				if(beg){
					processC(aux);
					aux.clear();
					beg = false;
				}else{
					meio += aux;
					aux.clear();
				}
			}else{
				aux += temp[j];
			}
		}
		if(!aux.empty()) 	processF(aux);
	}

	if(com == "* " || fim == "* "){
		cout << "Case #" << caso << ": *" << endl; 
	}else{
		cout << "Case #" << caso << ": " << com+meio+fim << endl; 
	}
}

int main(){

	cin >> T;

    FOR(i,1,T+1){
		cin >> N;

		FOR(i,0,N){
			cin >> v[i];
		}

		solve(i);
    }
	return 0;
}