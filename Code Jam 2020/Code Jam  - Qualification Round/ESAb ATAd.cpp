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
#define MAXN 101

int T,N,M,K,B;
int v[MAXN][MAXN];

void imprimi(vector<pair<bool,pii>> &iguais, vector<pair<bool,pii>> &diferentes){
    for(auto i: iguais){
        cout << i.fi << " " << i.se.fi << " ** " << i.se.se << endl;
    }
    for(auto i: diferentes){
        cout << i.fi << " " << i.se.fi << " -- " << i.se.se << endl;
    }
}

bool solve(int x){ 

    int caso = 1;
        
    vector<pair<bool,pii>> iguais;
    vector<pair<bool,pii>> diferentes;

    bool respI,respJ;
    int i = 1;
    int j = B;

    while(caso <= 150){
       if(caso%10 == 1 && caso != 1){
            if(!iguais.empty()){
                bool estado = iguais[0].fi;
                int pos = iguais[0].se.fi;
                bool depois;

                cout << pos << endl;
                cin >> depois;

                if(depois != estado){
                    FOR(k,0,sz(iguais)){
                        iguais[k].fi = !iguais[k].fi; 
                    }
                }
            }else{
                int lixo;
                cout << 1 << endl;
                cin >> lixo;
            }
            if(!diferentes.empty()){
                bool estado = diferentes[0].fi;
                int pos = diferentes[0].se.fi;
                bool depois;

                cout << pos << endl;
                cin >> depois;

                if(depois != estado){
                    FOR(k,0,sz(diferentes)){
                        diferentes[k].fi = !diferentes[k].fi; 
                    }
                }
            }else{
                int lixo;
                cout << 1 << endl;
                cin >> lixo;
            }
            caso +=2;
        }
        else if(i >=j){
            cout << i << endl;
            cin >> respI;
            caso++;
        }
        else{
            cout << i << endl;
            cin >> respI;
            cout << j << endl;
            cin >> respJ;
            caso +=2;

            if(respJ == respI){
                iguais.pb( make_pair(respI,pii(i,j)) );
            }else{
                diferentes.pb( make_pair(respI,pii(i,j)) );
            }
            i++;
            j--;
        }
    }

    vector<bool> sol(B+1);

    FOR(k,0,sz(iguais)){
        int pos, pos2, valor;
        
        valor = iguais[k].fi;
        pos = iguais[k].se.fi;
        pos2 = iguais[k].se.se;

        sol[pos] = valor;
        sol[pos2] = valor;
    }
    FOR(k,0,sz(diferentes)){
        int pos, pos2, valor;
        
        valor = diferentes[k].fi;
        pos = diferentes[k].se.fi;
        pos2 = diferentes[k].se.se;

        sol[pos] = valor;
        sol[pos2] = (!valor);
    }

    FOR(i,1,B+1){
        cout << sol[i];
    }cout << endl;

    char ans;

    cin >> ans;

    if(ans =='Y') return true;
    else return false;
}

int main(){

	cin >> T >> B;

    FOR(k,1,T+1){
        if(!solve(k)){
            return 0;
        }
    }
	return 0;
}