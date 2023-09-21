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

    ll T,N,M,K;

    int A[MAXN], B[MAXN];
    ll inv = 0, aux[MAXN];

    //Serve para ordenação estável e contagem de inversões (inv linha 21)
    void mergesort(int arr[], int l, int r) {
        
        if (l == r) return;
        
        int m = (l + r) / 2;
        
        mergesort(arr, l, m);
        mergesort(arr, m+1, r);
        
        int i = l, j = m + 1, k = l;
        
        while(i <= m && j <= r) {
            if (arr[i] > arr[j]) {
                aux[k++] = arr[j++];
                inv += j - k;
            }
            else aux[k++] = arr[i++];
        }
        while(i <= m) aux[k++] = arr[i++];
        for(i = l; i < k; i++) arr[i] = aux[i];
    }

    void print() {
        cerr << "A: ";
        for(int i = 0; i < N; i++) {
            cerr << A[i] << " ";
        }
        cerr << endl;
    }

    void f(vector<pii> &ops, int i, int j) {

        for(int k = 0; k < i; k++) aux[k] = A[k];
        for(int k = i; k < N - 2; k++) aux[k] = A[k + 2];

        A[j] =  A[i];
        A[j + 1] =  A[i + 1];

        for(int k = 0; k < j; k++) A[k] = aux[k];
        for(int k = j + 2; k < N; k++) A[k] = aux[k - 2];

        ops.push_back({i + 1, j});
        // cerr << pii(i,j) << endl;
        // print();
    }

    void solve() {

        cin >> N;

        for(int i = 0; i < N; i++) {
            cin >> A[i];
            B[i] = A[i];
        }

        // print();

        mergesort(B, 0, N - 1);

        if(inv & 1) {
            cout << "No\n";
            return;
        }

        vector<pii> ops;

        for(int i = 0; i < N - 1; i++) {
            if(A[i] == i + 1) continue;

            int p = i + 1;
            
            while(p < N && A[p] != i + 1) {
                p++;
            }

            if(p == i) continue;

            if(p == N - 1) {
                // cerr << pii(N - 2, N - 3) << " **\n";
                f(ops, N - 2, N - 3);
                p = N - 2;
            }

            // cerr << pii(p, i) << " *\n";
            f(ops, p, i);

            if(ops.size() > 2000) {
                cout << "No\n";
                return;
            }
        }
        
        cout << "Yes\n";
        cout << ops.size() << endl;
        for(int i = 0; i < ops.size(); i++) cout << ops[i].first << " " << ops[i].second << endl;
    }

    int main() {

        optimize;
        
        T = 1;
        
        //cin >> T;

        while(T--) {
            solve();
        }

        return 0;
    }
