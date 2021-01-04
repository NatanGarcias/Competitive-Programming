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
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;
ll qtd11, minAns;
vector<pii> v[4];
int nums[MAXN];

int menor(vector<int> &ptr){

    pii ans(INF,INF);
    int pos = -1;

    for(int i=0;i<4;i++){
        if(ptr[i] < v[i].size() && ans >= v[i][ptr[i]]){
            ans = v[i][ptr[i]];
            pos = i;
        }
    }

    return pos;
}

void imp(){
    cout << -1 << endl;
    exit(0);
}

pii p(pii a){
    return pii(-a.fi, -a.se);
}

void melhor(){
    for(int i=0;i<4;i++) sort(all(v[i]));

    vector<pii> resp[4];
    vector<int> ptr(4,0);
    
    ll ans = 0, l11 = max(0LL,2*M-K), l01;

    l01 = M - l11;

    //Adicionando os l11
    if(v[0].size() < l11) imp();
    
    for(;ptr[0] < l11; ptr[0]++) {
        resp[0].pb(v[0][ptr[0]]);
        ans += v[0][ptr[0]].fi;
    }

    while(ptr[0] < v[0].size() && (v[1].size() < l01 || v[2].size() < l01) ) {
        l01--;
        resp[0].pb(v[0][ptr[0]]);
        ans += v[0][ptr[0]].fi;
        ptr[0]++;
    }

    while(ptr[0] < v[0].size() &&  ptr[0] + v[1].size() + v[2].size() + v[3].size() < K) {
        l01--;
        resp[0].pb(v[0][ptr[0]]);
        ans += v[0][ptr[0]].fi;
        ptr[0]++;
    }

    //Adicionando os 01 e 10
    if(v[1].size() < l01 || v[2].size() < l01) imp();

    for(;ptr[1] < l01; ptr[1]++, ptr[2]++){
        resp[1].pb(v[1][ptr[1]]);
        resp[2].pb(v[2][ptr[2]]);
        ans += v[1][ptr[1]].fi;
        ans += v[2][ptr[2]].fi;
    }

    //Adicionando os outros livros 
    priority_queue<pii> sob, others;

    for(int i=1;i<4;i++){
        for(int j = ptr[i];j < v[i].size();j++){
            sob.push(p(v[i][j]));
        }
    }

    while(!sob.empty() && ptr[0] + ptr[1] + ptr[2] + others.size() < K){
        ans += -sob.top().fi;
        others.push(p(sob.top()));
        sob.pop();
    }

    minAns = ans;
    qtd11 = ptr[0];

    //A cada iteração add um livro 11 e removo um 01 e um 10 e depois add outro qualquer que seja o mais barato
    for(;ptr[1] && ptr[0] < v[0].size(); ptr[0]++){
        ptr[1]--, ptr[2]--;
        
        sob.push(p(resp[1][ptr[1]]));
        ans -= resp[1][ptr[1]].fi;
        resp[1].pop_back();

        sob.push(p(resp[2][ptr[2]]));
        ans -= resp[2][ptr[2]].fi;
        resp[2].pop_back();

        resp[0].pb(v[0][ptr[0]]);
        ans += v[0][ptr[0]].fi;

        pii u = p(sob.top());
        sob.pop();
        others.push(u);
        ans += u.fi;

        while(others.top() > p(sob.top())){
            pii aux = others.top();
            pii aux2 = p(sob.top());

            ans -= aux.fi;
            ans += aux2.fi;

            others.pop();
            sob.pop();

            others.push(aux2);
            sob.push(p(aux));
        }
        
        if(ans < minAns) {
            qtd11 = resp[0].size();
            minAns = ans;
        }
    }
}

void construir(){
    //Remonto a resposta já que tenho a qtdd de l11 que participaram dela
    vector<pii> resp;
    vector<int> ptr(4,0);
    ll ans = 0;

    for(;ptr[0] < qtd11; ptr[0]++){
        resp.pb(v[0][ptr[0]]);
        ans += v[0][ptr[0]].fi;
    }

    for(int i = qtd11; i < M; i++, ptr[1]++, ptr[2]++){
        resp.pb(v[1][ptr[1]]);
        resp.pb(v[2][ptr[2]]);
        
        ans += v[1][ptr[1]].fi;
        ans += v[2][ptr[2]].fi;
    }

    while(resp.size() < K){
        int pos = menor(ptr);

        ans += v[pos][ptr[pos]].fi;
        resp.pb(v[pos][ptr[pos]]);
        ptr[pos]++;
    }

    cout << ans << endl;

    for(int i=0;i<resp.size();i++){
        if(!i)  cout << resp[i].se+1;
        else    cout << " " << resp[i].se+1;
    }
    cout << endl;
}

void solve(){
    
    melhor();
    construir();
}

int main(){

	optimize;
	
	cin >> N >> K >> M;

    for(int i=0;i<N;i++){
        int a,b,t;

        cin >> t >> a >> b;
        
        if(a && b){
            v[0].pb(pii(t,i));
        }
        else if(a){
            v[1].pb(pii(t,i));
        }
        else if(b){
            v[2].pb(pii(t,i));
        }else{
            v[3].pb(pii(t,i));
        }

        nums[i] = t;
    }
	
    solve();

	return 0;
}