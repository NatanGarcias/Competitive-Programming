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

#define all(x) x.begin(),x.end()
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */
//Subtasks 1 - AC
//Subtasks 2 - AC

ll T,N,M,K;
vector<string> A;
ll ans;

void f(int i){

    string a,b,c;

    a = A[i-1];
    b = A[i];
    c = a;

    //Copio o prefixo do numero que vem antes
    c.resize(b.size());

    //Se elas são iguais
    if(a == b){
        ans++;

        while(b.size() <= a.size()) b.pb('0');

        A[i] = b;

        return;
    }
    //Se o prefixo é maior
    else if(c > b){
        ans += a.size() - b.size() + 1;

        while(b.size() <= a.size()) b.pb('0');

        A[i] = b;

        return;
    }
    //Prefixo é igual
    else if(c == b){
        bool ok = false;

        for(int j = b.size();j<a.size();j++){
            if(a[j] != '9') {
                ok = true;
                break;
            }
        }

        if(ok){
            ans += a.size() - b.size();

            string d(a.begin() + b.size(), a.end()), e;

            for(int j=d.size()-1;j>=0;j--){
                if(d[j] == '9'){
                    d[j] = '0';
                }
                else{
                    d[j] = (char( ((int)d[j]) + 1) );
                    break;
                }
            }

            e = b + d;

            A[i] = e;

            return;
        }
        else{
            ans += a.size() - b.size() + 1;

            while(b.size() <= a.size()) b.pb('0');

            A[i] = b;

            return;
        }
    }
    //Prefixo é menor
    else{
        ans += a.size() - b.size();

        while(b.size() < a.size()) b.pb('0');

        A[i] = b;

        return;
    }
}

void solve(int caso){

    ans = 0;

    for(int i=0;i<N-1;i++){
        bool ok = false;
        
        if(A[i].size() < A[i+1].size() ) ok = true;
        
        if(A[i].size() == A[i+1].size() && A[i] < A[i+1]) ok = true;

        if(ok) continue;

        f(i+1);
    }

    cout << "Case #" << caso << ": " << ans << endl;
}

int main(){

	optimize;
	
	cin >> T;

    for(int i=1;i<=T;i++){
		cin >> N;

        A.resize(N);

        for(int j=0;j<N;j++) cin >> A[j];
    
		solve(i);

        A.clear();
    }

	return 0;
}