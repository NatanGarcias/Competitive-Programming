#include<bits/stdc++.h>
using namespace std;

#define FOR(x,n) for(int x=0;x<n;x++)
#define FOR1(x,n) for(int x=1;x<=n;x++)

#define MAXN 100010
int n,k;
char c;
int v[MAXN], seg[4*MAXN];

void build(int p, int tl, int tr){

    if(tl == tr){
        seg[p] = v[tl];
    }else{
        int tm = (tl+tr)/2;
        int e = 2*p;
        int d = 2*p+1;

        build(e,tl,tm);
        build(d,tm+1,tr);

        seg[p] = seg[e] * seg[d];
    }
}

int query(int p, int tl, int tr,int a, int b){

    if(a > tr || b < tl){
        return 1;
    }else if(tl >= a && tr <= b){
        return seg[p];
    }else{
        int tm = (tl+tr)/2;
        int e = 2*p;
        int d = 2*p+1;

        return query(e,tl,tm,a,b) * query(d,tm+1,tr,a,b);
    }

}

void update(int p, int tl, int tr, int a, int b, int x){
    
    if(a > tr || b < tl){
        return;
    }else if(tl == tr){
        seg[p] = x;
    }else{
        int tm = (tl+tr)/2;
        int e = 2*p;
        int d = 2*p+1;

        update(e,tl,tm,a,b,x);
        update(d,tm+1,tr,a,b,x);

        seg[p] = seg[e] * seg[d];
    }
}

int main(){

    while(cin >> n >> k){

        memset(v,0,sizeof(v));
        memset(seg,0,sizeof(seg));

        FOR1(i,n){
            cin >> v[i];

            if(v[i] > 0) v[i] = 1;
            else if(v[i] < 0) v[i] = -1;
        }

        build(1,1,n);

        int a,b;

        FOR(i,k){
            cin >> c >> a >> b;

            if(c == 'C'){
                
                if(b > 0) b = 1;
                else if(b < 0)  b = -1;

                update(1,1,n,a,a,b);
            }else if(c == 'P'){
                int ans = query(1,1,n,a,b);

                if(ans > 0 ) cout << '+';
                else if(!ans) cout << 0;
                else cout << '-';
            }
        }
        cout << endl;
    }
    return 0;
}