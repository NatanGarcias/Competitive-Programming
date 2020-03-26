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

int T,N,M;
multiset<int> ms;

void solve(){

    int ans = 0,a,b;

    priority_queue<int> pq;
    vector<pii> sol;
    vector<int> sol2;

    FOR(i,0,N-1){
        if(!(i%2)){
            if(ms.size() > 3){
                int f,g,h,j;

                auto it = ms.begin();
                f = (*it);
                it++;
                g = (*it);
                it++;
                auto it2 = ms.end();
                it2--;
                j = (*it2);
                it2--;
                h = (*it2);
                
                if(2*f + g + h + j < f + 3*g + j){
                    break;
                }
                else{
                    auto it = ms.begin();
                    
                    a = (*it);

                    ms.erase(it);
                    
                    it = ms.begin();

                    b = (*it);

                    ms.erase(it);
                    sol.pb(pii(a,b));
                }
            }else{
                auto it = ms.begin();
                
                a = (*it);

                ms.erase(it);
                
                it = ms.begin();

                b = (*it);

                ms.erase(it);
                sol.pb(pii(a,b));
            }
        }else{
            auto it = ms.end();

            it--;
            
            a = (*it);

            ms.erase(it);
            
            it = ms.end();
            it--;

            b = (*it);

            ms.erase(it);

            swap(a,b);
            sol.pb(pii(a,b));
        }
        if(i!=N-2){
            ans += max(a,b);
            
            pq.push(-a);
            pq.push(-b);

            int c = pq.top();
            pq.pop();

            ans = ans - c;
            
            sol2.pb(-c);
            ms.insert(-c);
        }else{
            ans += max(a,b);
        }
    }

    while(ms.size()){

        auto it = ms.begin();
        
        int a = *(it);

        it++;

        int b = *(it);

        ans +=b;

        ms.erase(it);
        if(ms.size() == 1){
            ms.erase(ms.begin());
        }else{
            ans+=a;
            sol2.pb(a);
        }
        sol.pb(pii(a,b));
    }

    cout << ans << endl;
    FOR(i,0,N-1){
        cout << sol[i].fi << " " << sol[i].se << endl;
        if(i != N-2){
            cout << sol2[i] << endl;
        }
    }
}

int main(){

	cin >> T;

	while(T--){
        cin >> N;

        int a;

        if(N == 0){
            cout << 0 << endl;
            if(T){
                cout << endl;
            }   
            continue;
        }else if(N==1){
            cin >> a;
            cout << a  << endl << a << endl;
            if(T){
                cout << endl;
            }
            continue;
        }
        
        ms.clear();

        FOR(i,0,N){
            cin >> a;
            ms.insert(a);
        }
        solve();
        if(T){
            cout << endl;
        }
	}

	return 0;
}