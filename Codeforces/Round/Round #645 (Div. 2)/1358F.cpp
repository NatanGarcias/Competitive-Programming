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
ll A[MAXN], B[MAXN];
string ans;
ll rep, op;
const ll LIM = 200000;

bool crescente(){
    for(int i=1;i<N;i++) if(B[i] <= B[i-1]) return false;
    return true;
}

bool decrescente(){
    for(int i=1;i<N;i++) if(B[i] >= B[i-1]) return false;
    return true;
}

bool equals(){
    for(int i=0;i<N;i++) if(A[i] != B[i]) return false;
    return true;
}

bool equalsReverse(){
    for(int i=0;i<N;i++) if(A[i] != B[N-1-i]) return false;
    return true;
}

void roolback(){
    for(int i=N-1;i>=1;i--) B[i] = B[i] - B[i-1];
}

void small(){
    cout << "SMALL\n";
    cout << op << "\n";
    cout << ans << "\n";
    exit(0);
}

void imp(){
    cout << "IMPOSSIBLE\n";
    exit(0);
}

void big(){
    cout << "BIG\n";
    cout << rep << endl;
    exit(0);
}

void solve2(){

    string p,r;
    
    if(A[0] > A[1]){
        p += 'R';
        op++;
        sort(A,A+N);
    }
    if(B[0] > B[1]){
        r += 'R';
        op++;
        sort(B,B+N);
    }   

    while(true){
        if(A[0] == B[0]){
            if( !( (B[1] - A[1]) % B[0]) ){
                ll aux = (B[1] - A[1]) / B[0];

                op += aux;
                rep += aux;
                if(rep <= LIM){
                    for(ll i=0;i<aux;i++) ans += 'P';
                    reverse(all(ans));
                    ans = p + ans + r;
                    small();
                }
                else{
                    big();
                }
            }
            else{
                imp();
            }
        } 
        else{
            if(!B[0]) imp();

            ll cnt = B[1]/B[0];
            
            op += cnt + 1;
            rep += cnt;

            if(rep <= LIM){
                for(ll i=0;i<cnt;i++) ans += 'P';
                ans += 'R';
            }

            B[1] %= B[0];

            swap(B[0],B[1]);
        }
    }
}

void solve3(){
    while(!equals()){
        if(equalsReverse()){
            op++;
            ans.push_back('R');
            reverse(all(ans));

            if(rep <= LIM) small();
            else big();
        }

        if(crescente()){
            rep++;
            op++;
            ans.push_back('P');
            roolback();
        }
        else if(decrescente()){
            op++;
            ans.push_back('R');
            reverse(B,B+N);
        }
        else{
            imp();
        }
    }

    reverse(all(ans));

    if(rep <= LIM) small();
    else big();
}

void solve(){

    if(N == 1) {
        if(A[0] == B[0])    small();
        else                imp();
    }
    else if(N == 2){
        solve2();
    }
    else{
        solve3();
    }

}

int main(){

	optimize;
	
    cin >> N;
    
    for(int i=0;i<N;i++) cin >> A[i];

    for(int i=0;i<N;i++) cin >> B[i];
    
    solve();
 
	return 0;
}