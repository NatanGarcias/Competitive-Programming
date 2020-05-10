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
map<string,int> mapa;
string s;

void pre(){

	mapa["B#"] = 0;
	mapa["C"] =  0;

	mapa["C#"] = 1;
	mapa["Db"] = 1;
	
	mapa["D"] =  2;

	mapa["D#"] = 3;
	mapa["Eb"] = 3;

	mapa["E"] =  4;
	mapa["Fb"] = 4;

	mapa["F"] =  5;
	mapa["E#"] = 5;

	mapa["Gb"] = 6;
	mapa["F#"] = 6;

	mapa["G"] =  7;

	mapa["G#"] = 8;
	mapa["Ab"] = 8;
	
	mapa["A"] =  9;

	mapa["A#"] = 10;
	mapa["Bb"] = 10;

	mapa["B"] =  11;
	mapa["Cb"] = 11;
}

struct KMP{
    int m;
    vector<int> q;
    vector<int> lps;
    
    KMP(vector<int> &_q) : q{_q} {
        m = q.size();
        pre_process();
    }

    void pre_process(){
        lps.assign(m+1,-1);

        for(int i=0, j=-1; i<m ; ){
            while(j>=0 && q[i] != q[j]) j = lps[j];
            lps[++i] = ++j; 
        }
    }

    bool match(vector<int> &p){
        vector<int> ans;

        ll n = p.size();

        if(n < m) return false;

        for(int i=0,j=0; i<n ; ){
            while( j>=0 && p[i] != q[j]) j = lps[j];
            i++; j++;

            if(j == m){
                ans.push_back(i-j);
                j = lps[j];
            }
        }

        if(ans.empty()) return false;
        else return true;
    }
};


void solve(vector<int> &seq, vector<int> &chave){

	FOR(i,0,12){

		KMP kmp(chave);
		vector<int> aux(N);

		FOR(j,0,N) aux[j] = (seq[j] + i)%12;  

		if(kmp.match(aux)){
			cout << 'S' << endl;
			return;
		}
	
	}
	cout << 'N' << endl;
}

int main(){

	pre();

    while(cin >> N >> M){
		if(!N && !M) break;

		vector<int> seq(N);
		vector<int> chave(M);

		FOR(i,0,N){
			cin >> s;

			int aux = mapa[s];

			seq[i] = aux;
		}

		FOR(i,0,M){
			cin >> s;

			int aux = mapa[s];

			chave[i] = aux;
		}

		solve(seq,chave);
    }

	return 0;
}