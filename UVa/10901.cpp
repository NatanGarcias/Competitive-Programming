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
#define FOR(x,a,n) for(int x= (int)(a);(x) < int(n);(x)++)

#define INF 0x3fffffff
#define INFLL 0x3fffffffffffffff

#define mod %1000000007

#define MAXN 200010

int T,N,M,C;
multiset<pii> esq;
multiset<pii> dir;

void imprimi(vector<int> &sol){

    FOR(i,0,sz(sol)){
        cout << sol[i] << "\n";
    }
}

void solve(){
    int t = 100000;

    vector<int> sol(M);

    bool lado = true;

    multiset<pii> esq2;
    multiset<pii> dir2;

    auto it = esq.begin();
    auto it2 = dir.begin();

    if(!esq.empty()){
        t = min(t,(*it).fi);
    }

    if(!dir.empty()){
        t = min(t,(*it2).fi);
    }

    int pula = 0;
    while(true){
        
        if(pula == 3) break;

        while( it != esq.end() && (*it).fi <= t){
            esq2.insert(*it);
            it++;
        }

        while( it2 != dir.end() && (*it2).fi <= t){
            dir2.insert(*it2);
            it2++;
        }
        
        if(esq2.empty() && dir2.empty()){
            int temp = 10000;

            if(esq2.empty() && it != esq.end() && dir2.empty() && it2 != dir.end()){
                t = min((*it2).fi,(*it).fi);
            }else if(esq2.empty() && it != esq.end()){
                t = min(temp,(*it).fi);
            }
            else if(dir2.empty() && it2 != dir.end()){
                t = min(temp,(*it2).fi);
            }
        
            while( it != esq.end() && (*it).fi <= t){
                esq2.insert(*it);
                it++;
            }

            while( it2 != dir.end() && (*it2).fi <= t){
                dir2.insert(*it2);
                it2++;
            }            
        }

        if(lado){
            lado = false;
            
            if(esq2.empty()){
                t = t+T;
                pula++;
                continue;
            }
            pula = 0;

            int cont = 0;

            vector<int> prox;

            while(!esq2.empty() && cont < N && (*esq2.begin()).fi <= t ){
                
                cont++;
                auto itr = esq2.begin();
                prox.pb((*itr).se);
                esq2.erase(esq2.begin());
            }

            t = t+T;
            FOR(i,0,sz(prox)){
                sol[ prox[i] ] = t; 
            }
        }
        else{
            lado = true;
            
            if(dir2.empty()){
                pula++;
                t = t+T;
                continue;
            }
            
            pula = 0;
            int cont = 0;
            vector<int> prox;

            while(!dir2.empty() && cont < N && (*dir2.begin()).fi <= t){
                
                cont++;
                auto itr = dir2.begin();
                prox.pb((*itr).se);
                dir2.erase(dir2.begin());
            }

            t = t+T;

            FOR(i,0,sz(prox)){
                sol[ prox[i] ] = t; 
            }
        }
    }

    imprimi(sol);
}

int main(){

	cin >> C;

    int a;
    string s;

    while(C--){
        cin >> N >> T >> M; 
        esq.clear();
        dir.clear();

        FOR(i,0,M){
            cin >> a >> s;
            if(s == "left"){
                esq.insert(pii(a,i));
            }else{
                dir.insert(pii(a,i));
            }
        }
        solve();

        if(C){
            cout << endl;
        }
    }

	return 0;
}