#include<bits/stdc++.h>
using namespace std;

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
#define ms(x) memset(x,0,sizeof(x))
#define ms2(x) memset(x,-1,sizeof(x))

#define PI 3.141592653589793238462643383279502884
#define FOR(x,n) for(int x=0;(x) < int(n);(x)++)
#define FOR1(x,n) for(int x=1;(x) <= int(n);(x)++)

#define INF 0x3fffffff
#define INFLL 0x3fffffffffffffff

#define mod %998244353

#define MAXN 200010

int T,N,M;
string S;

string palin(string s){
    string aux;

    string com(s.begin(), s.begin()+sz(s)/2);
    string fim(s.begin()+sz(s)/2, s.end());

    reverse(all(fim));

    if(sz(s)%2){
        fim.pop_back();
    }

    if(com == fim){
        return s;
    }
    
    return aux;
}

string esq(){
    
    string aux;
    string maior;
    string comeco,fim;

    for(int i=0;i<sz(S);i++){
        aux += S[i];

        string temp = palin(aux);
    
        if( sz(temp) > sz(maior)){
            maior = temp;
        }
    }
    return maior;

}

string dir(){
    
    string aux;
    string maior;
    string comeco,fim;

    for(int i=sz(S)-1;i>=0;i--){
        aux += S[i];

        string temp = palin(aux);

        if( sz(temp) > sz(maior)){
            maior = temp;
        }
    }

    return maior;
}

int pre(){
    
    int cont =0 ;
    
    while( S[cont] == S[ sz(S) - 1 - cont] && cont < sz(S)/2){
        cont++;
    }
    return cont;
}

void solve(){

    int k = pre();

    string s3(S.begin() + k, S.end()-k);
    string s4(S.begin(), S.begin() + k);
    string s5 = s4;

    reverse( all(s5));
    S = s3;

    string s = esq();
    string s2 = dir();
    
    if(sz(s) > sz(s2)){
        cout << s4+s+s5 << endl;
    }else{
        cout << s4+s2+s5 << endl;
    }
}

int main(){
    
	cin >> N;

	FOR(i,N){
        cin >> S;
        solve();
	}
    
	return 0;
}