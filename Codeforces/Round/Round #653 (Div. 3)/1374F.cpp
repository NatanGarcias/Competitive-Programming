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
vector<int> v;
vector<int> resp;

void print(bool imp){
    if(imp){
        cout << -1 << endl;
        return;
    }

    cout << resp.size() << endl;

    for(int i=0;i<resp.size();i++){
        if(!i)  cout << resp[i]+1;
        else    cout << " " << resp[i]+1;
    }
    cout << endl;
}

void shift(int i){
    swap(v[i], v[i+2]);
    swap(v[i+1], v[i+2]);
    resp.pb(i);
}

int repetido(){
    if(v[N-3] == v[N-1]) return N-3;

    for(int i=N-2;i>=0;i--) if(v[i] == v[i+1]) return i;
    return -1;
}

bool ordenado(){
    for(int i=N-2;i>=0;i--) if(v[i] > v[i+1]) return false;
    return true;
}

void solve(){

    for(int i=0;i<N-2;i++){
        int menor = INF, p = i;
        
        for(int j=i;j<N;j++){
            if(v[j] < menor) {
                p = j;
                menor = v[j];
            }
        }

        while(p != i){
            if(p == i+1){
                shift(i);
                shift(i);
                break;
            }else{
                shift(p-2);
                p = p-2;
            }
        }   
    }

    if(v[N-1] < v[N-2]){
        int aux = repetido();
        if(!(~aux)){
            print(1);
            return;
        }

        shift(aux);

        if(ordenado()){
            print(0);
            return;
        }

        shift(aux);

        for(int j=aux+1;j<N-2;j++){
            shift(j);
            shift(j);
        }
    }

    print(0);
}

int main(){

	optimize;
	
	cin >> T;

    while(T--){
		cin >> N;

        v.resize(N);

        for(int i=0;i<N;i++) cin >> v[i];
		
		solve();

        v.clear();
        resp.clear();
    }

	return 0;
}