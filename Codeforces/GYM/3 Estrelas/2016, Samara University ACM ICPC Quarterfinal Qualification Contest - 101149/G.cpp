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
#define FOR(x,a,n) for(int x= (int)(a);(x) < int(n);(x)++)
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL
#define MAXN 200010

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll T,N,M,K;

struct Zorc{
    int id, a,b;

    Zorc() {}
    Zorc(int _id, int _a, int _b) : id(_id), a(_a), b(_b) {}

    bool operator<(const Zorc& p) const{
        if(a != p.a) return a>p.a;
        if(b != p.b) return b>p.b;
        return id < p.id;
    } 
};

struct Item{
    int id, a,b;

    Item() {}
    Item(int _id, int _a, int _b) : id(_id), a(_a), b(_b) {}

    bool operator<(const Item& p) const{
        if(a != p.a) return a>p.a;
        if(b != p.b) return b>p.b;
        return id < p.id;
    } 
};

struct Item2{
    int id, a,b;

    Item2() {}
    Item2(int _id, int _a, int _b) : id(_id), a(_a), b(_b) {}

    bool operator<(const Item2& p) const{
        if(b != p.b) return b<p.b;
        if(a != p.a) return a<p.a;
        return id < p.id;
    } 
};

Zorc Z[MAXN];
Item I[MAXN];
int ans[MAXN];

set<Item2> sI2;

void solve(){

    if(N > M){
        cout << -1 << endl;
        return;
    }
    
    sort(Z,Z+N);
    sort(I,I+M);

    int ptr = 0;

    FOR(i,0,N){
        int t = Z[i].a;

        while(ptr < M && I[ptr].a >= t){
            
            Item2 aux(I[ptr].id, I[ptr].a, I[ptr].b);
            
            sI2.insert(aux);
            ptr++;
        }

        Item2 aux(-INF, Z[i].a, Z[i].b);
        auto it = sI2.lower_bound(aux);

        if(it == sI2.end()){
            cout << -1 << endl;
            return;
        }

        ans[Z[i].id] = (*it).id+1;

        sI2.erase(it);
    }

    FOR(i,0,N) cout << ans[i] << " \n"[i==N-1];
}

int main(){

	optimize;
	
	cin >> N;

    FOR(i,0,N){
        cin >> Z[i].a >> Z[i].b;
        Z[i].id = i;
    }

    cin >> M;

    FOR(i,0,M){
        cin >> I[i].a >> I[i].b;
        I[i].id = i;
    }

    solve();

	return 0;
}