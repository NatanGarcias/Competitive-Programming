#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define endl "\n"
#define FOR(x,n) for(int x=0;(x) < int(n);(x)++)
#define sz(x) (ull) x.size()
#define all(x) x.begin(),x.end()
#define mod %1000000009
#define m 1000000009
#define MAXN 1000010
#define primo1 53
#define primo2 31

int T,N,M;
string S;
ull p[MAXN];

void preCalc(){
	
	p[0] = primo1;

	for(int i=1;i<MAXN;i++){
		p[i] = (p[i-1] * primo1) mod;
	}

}

struct Hash{
	vector<ull> h;

	Hash(const string &s){
	
		h.resize(sz(s));

		for(int i=0;i<sz(s);i++){
			if(!i){
				h[i] = ( (ull)(s[i] - 'a' + 1) * p[i]) mod;  
			}else{
				h[i] = (h[i-1] + ( ( (ull)(s[i] - 'a' + 1) * p[i]) mod) ) mod;  
			}
			
		}
	}
	
	ull getHash(int l, int r){
		if(!h.size()) return 0;

		ull r1 = h[r];

		if(l){
			
			int w = sz(S) - l - 1;
			
			r1 = (r1 - h[l-1] + m) % m; 
			r1 = (r1 * p[w]) mod; 
			
			}else{
				r1 = (r1 * p[sz(S)-1]) mod; 
			}

		return r1;
	}
};

int pre(){
    
    int cont =0 ;
    
    while( S[cont] == S[ sz(S) - 1 - cont] && cont < sz(S)/2){
        cont++;
    }
    return cont;
}

string process(){
	string s(S);
	string s2(S);

	reverse(all(s2));

	Hash h1(s);
	Hash h2(s2);

	int n = sz(S);
	
	int tam = -1 ,pos = -1;

	for(int i=0;i<n;i++){

		if(h2.getHash(0,i) == h1.getHash(n-1-i,n-1)){
			pos = n-1-i;
			tam = i + 1;
		}
		if(h1.getHash(0,i) == h2.getHash(n-1-i,n-1)){
			pos = 0;
			tam = i + 1;
		}
	}

	if(tam == -1){
		return "";
	}
	string s3 = S.substr(pos,tam);
	return s3; 
}

void solve(){

    int k = pre();

    string s3(S.begin() + k, S.end()-k);
    string s4(S.begin(), S.begin() + k);
    string s5 = s4;

    reverse( all(s5));
    S = s3;

    string s = process();

    cout << s4+s+s5 << endl;
}

int main(){

	cin >> N;

    preCalc();

	FOR(i,N){
        cin >> S;
        solve();
	}
    
	return 0;
}