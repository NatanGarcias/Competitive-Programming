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

#define sz(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 1010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
int ip, jp;

char m[MAXN][MAXN], ans[MAXN][MAXN];
int pre[MAXN][MAXN];

void preCalc(){

    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++){
            pre[i][j] = pre[i][j-1] + pre[i-1][j] - pre[i-1][j-1];
            
            if(m[i][j] == 'A') pre[i][j] += INF;
            else if(m[i][j] != '.') pre[i][j]++;
        }
    }
}   

int calc(pii c, pii f){
    return pre[f.fi][f.se] + pre[c.fi][c.se] - pre[f.fi][c.se] - pre[c.fi][f.se];
}

void colore(pii c, pii f){

    //Preenchendo Horizontalmente
    for(int i = c.fi;i <= f.fi;i++){

        char k = 0;
        int aux = c.se;
        bool first = true;

        for(int j = c.se;j<= f.se;j++){
            if(first && m[i][j] != '.') {
                k = (char) (m[i][j] - 'A' + 'a');

                for(int l= aux;l< j;l++) ans[i][l] = k;

                aux = j+1;
                
                first = false;
            }
            else if(m[i][j] != '.') k = m[i][j] - 'A' + 'a';
            else if(!first) ans[i][j] = k;
        }
    }

    //Preenchendo Verticalmente
    int aux = c.fi;
    bool first = true;

    for(int i = c.fi;i <= f.fi;i++){
        if(ans[i][c.se] != '.'){
            for(int l = i-1; l >=aux;l--){
                for(int j = c.se;j<= f.se;j++){
                    if(ans[l+1][j] <= 'Z')  ans[l][j] = ans[l+1][j] - 'A' + 'a';
                    else                    ans[l][j] = ans[l+1][j];
                }        
            }
            aux = i+1;
            first = false;
        }
        else if(!first){
            for(int j = c.se;j<= f.se;j++){
                if(ans[i-1][j] <= 'Z')  ans[i][j] = ans[i-1][j] - 'A' + 'a';
                else                    ans[i][j] = ans[i-1][j];
            }        
        }
    }

}

void print(){

    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++){
            cout << ans[i][j];
        }
        cout << endl;
    }
}

void preenche(pii c, pii f){

    //Pega a original
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++){
            ans[i][j] = m[i][j];
        }
    }

    //Preenche a do maior filho
    for(int i=c.fi+1;i<=f.fi;i++) {
        for(int j=c.se+1;j<=f.se;j++){
            if(ans[i][j] != 'A') ans[i][j] = 'a';
        }
    }

    //Quatros quadrados
    pii quad[4][2];

    quad[0][0] = pii(1,1);
    quad[0][1] = pii(c.fi,M); 

    quad[1][0] = pii(c.fi+1,1);
    quad[1][1] = pii(f.fi,c.se); 

    quad[2][0] = pii(c.fi+1,f.se+1);
    quad[2][1] = pii(f.fi,M); 

    quad[3][0] = pii(f.fi+1,1);
    quad[3][1] = pii(N,M); 

    for(int i=0;i<4;i++) {
        colore(quad[i][0], quad[i][1]);
    }
}

void solve(){

    vector<int> h,v;

    h.pb(1);
    h.pb(M);

    v.pb(1);
    v.pb(N);

    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            if(m[i][j] != '.' && m[i][j] != 'A'){
                if(ip > i) v.pb(i+1);
                else if(ip < i) v.pb(i-1);

                if(jp > j) h.pb(j+1);
                else if(jp < j) h.pb(j-1);
            }
        }
    }

    sort(all(h));
    sort(all(v));

    pii p[2];
    int maior = -1;

    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            for(int k=0;k<h.size();k++){
                for(int l=k+1;l<h.size();l++){
                    int aux = (v[j] - v[i] + 1) * (h[l] - h[k] + 1);

                    pii p1 = pii(v[i]-1,h[k]-1), p2 = pii(v[j],h[l]);

                    int aux2 = calc(p1 ,p2);
                    
                    if(aux2 == INF && aux > maior){
                        maior = aux;
                        p[0] = p1;
                        p[1] = p2;
                    }               
                }
            }
        }
    }

    preenche(p[0],p[1]);
    print();
}

int main(){

	optimize;
	
	cin >> N >> M;
		
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cin >> m[i][j];

            if(m[i][j] == 'A') {
                ip = i;
                jp = j;
            }
        }
    }

    preCalc();

	solve();

	return 0;
}