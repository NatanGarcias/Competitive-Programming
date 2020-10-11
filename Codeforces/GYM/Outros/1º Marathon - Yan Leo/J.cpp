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
#define MAXN 1000010

int T,N,M,K;
int v[MAXN];
vector<set<pii>> m;

void imprimi(){
    FOR(i,0,N){
        if(!m[i].empty()){
            cout << i << ": ";
            for(auto j: m[i]){
                cout << j.fi << " " << j.se << " ** ";
            }
            cout << endl;
        }
    }
    cout << endl;
}

void solve(){

    m.resize(N);

    int a,b,c = 0;

    for(int i=0;i<N;){   
        while(i<N && v[c] == v[i]) i++;

        m [ v[c] ].insert(pii(c,i-1));
        c = i;
    }

    FOR(i,0,M){

        cin >> a;

        if(a == 2){
            cin >> b;

            b--;

            cout << m[b].size() << endl;
        }else{
            cin >> b >> c;

            b--; c--;

            if(v[b] == c) continue;
            else{
                //Retirando o elemento
                int cor = v[b];

                auto it = m[cor].lower_bound(pii(b,-INF));

                if(it == m[cor].end()) it--;
                if( (*it).fi > b) it--;

                if( (*it).fi == b && (*it).se == b){
                    m[cor].erase(it);
                }else if( (*it).fi == b){
                    int r = (*it).se;

                    m[cor].erase(it);

                    m[cor].insert(pii(b+1,r));

                }else if((*it).se == b){
                    int l = (*it).fi;
                    
                    m[cor].erase(it);

                    m[cor].insert(pii(l,b-1));
                }else{
                    int l = (*it).fi;
                    int r = (*it).se;

                    m[cor].erase(it);

                    m[cor].insert(pii(l,b-1));
                    m[cor].insert(pii(b+1,r));
                }

                //Inserindo o elemento
                int posA = -1, posB = -1;
                if(b == 0){
                    posB = v[b+1];
                }else if(b == N-1){
                    posA = v[b-1];
                }else{
                    posA = v[b-1];
                    posB = v[b+1];
                }

                if(posA == c && posB == c){
                    auto it2 = m[c].lower_bound(pii(b,-INF));

                    it2--;

                    int l = (*it2).fi;

                    m[c].erase(it2);

                    it2 = m[c].lower_bound(pii(b,-INF));

                    int r = (*it2).se;
                    
                    m[c].erase(it2);

                    m[c].insert({l,r});
                }else if(posA == c){
                    auto it2 = m[c].lower_bound(pii(b,-INF));

                    it2--;

                    int l = (*it2).fi;

                    m[c].erase(it2);

                    m[c].insert({l,b});
                }else if(posB == c){
                    auto it2 = m[c].lower_bound(pii(b,-INF));

                    int r = (*it2).se;
                    
                    m[c].erase(it2);

                    m[c].insert({b,r});
                }else{
                    m[c].insert({b,b});
                }

                v[b] = c;
            }
        }
    }

}

int main(){

    optimize;

    cin >> N >> M;

    int a;

    FOR(i,0,N){
        cin >> a;
        a--;

        v[i] = a;
    }

    solve();
}