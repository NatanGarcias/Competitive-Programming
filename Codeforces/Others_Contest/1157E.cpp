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
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()

#define PI 3.141592653589793238462643383279502884
#define FOR(x,n) for(int x=0;(x) < int(n);(x)++)
#define FOR1(x,n) for(int x=1;(x) <= int(n);(x)++)

#define INF 0x7fffffff
#define INFLL 0x7fffffffffffffff

#define mod %1000000007
#define MAXN 200010

int main(){

    int N,aux;

    cin >> N;

    int v[N];
    multiset<int> s;

    FOR(i,N){
        cin >> v[i];
    }

    FOR(i,N){
        cin >> aux;
        s.insert(aux);

    }

    FOR(i,N){
        aux = N-v[i];
        
        auto itL = s.lower_bound(aux);
        
        if(itL == s.end()){
            cout << (v[i] + (*(s.begin())))%N << " \n"[i==N-1];
            s.erase(s.begin());
        }else{
            cout << (v[i] + (*itL))%N << " \n"[i==N-1];
            s.erase(s.find(*itL));
        }
    } 
   return 0;
}