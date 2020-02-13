#include<bits/stdc++.h>
using namespace std;

#define FOR(x,n) for(int x=0;x<n;x++)
#define FOR1(x,n) for(int x=1;x<=n;x++)
#define endl "\n"
#define space " "

#define MAXN 1024010

int N,n,k,t;
char c;
string s,s2;

struct Pirata{
    Pirata(){}
    Pirata(int l, int r, int x){
        x = l;
        f = r;
        x = q;
    }
    int c,f,q;
};

int v[4*MAXN];
Pirata seg[4*MAXN];
char lazy[4*MAXN];

void build(int p, int tl, int tr){

    if(tl == tr){
        seg[p].c = tl;
        seg[p].f = tr;
        seg[p].q = v[tl];
    }else{
        int tm = (tl+tr)/2;
        int e = 2*p;
        int d = 2*p+1;

        build(e,tl,tm);
        build(d,tm+1,tr);
        
        seg[p].c = seg[e].c;
        seg[p].f = seg[d].f;
        seg[p].q = seg[e].q + seg[d].q;
    }
}

void push(int p , int tl, int tr){
    
    int e = 2*p;
    int d = 2*p+1;

    if(lazy[p] == 'F'){
        seg[p].q = seg[p].f - seg[p].c + 1;
        
        lazy[e] = lazy[d] = lazy[p];
        lazy[p] = (char)0;

    }else if(lazy[p] == 'E'){
        seg[p].q = 0;

        lazy[e] = lazy[d] = lazy[p];
        lazy[p] = (char)0;
        
    }else if(lazy[p] == 'I'){
        seg[p].q = seg[p].f - seg[p].c + 1 - seg[p].q;
        
        if(lazy[e] == 'I'){
            lazy[e] = (char)0;
        }else if(lazy[e] == 'F'){
            lazy[e] = 'E';
        }else if(lazy[e] == 'E'){
            lazy[e] = 'F';
        }else{
            lazy[e] = 'I';
        }

        if(lazy[d] == 'I'){
            lazy[d] = (char)0;
        }else if(lazy[d] == 'F'){
            lazy[d] = 'E';
        }else if(lazy[d] == 'E'){
            lazy[d] = 'F';
        }else{
            lazy[d] = 'I';
        }
        lazy[p] = (char)0;

    }
}

int query(int p, int tl, int tr, int a, int b){

    push(p,tl,tr);
    if(a > tr || b < tl){
        return 0;
    }else if(tl >= a && tr <= b){
        return seg[p].q;
    }else{
        int tm = (tl+tr)/2;
        int e = 2*p;
        int d = 2*p+1;

        return query(e,tl,tm,a,b) + query(d,tm+1,tr,a,b);
    }
}

void update(int p, int tl, int tr, int a, int b, char f){

    push(p,tl,tr);

    if(a > tr || b < tl){
        return;
    }else if(tl >= a && tr <= b){
        lazy[p] = f;
        push(p,tl,tr);
        return;
    }else{
        int tm = (tl+tr)/2;
        int e = 2*p;
        int d = 2*p+1;

        update(e,tl,tm,a,b,f);
        update(d,tm+1,tr,a,b,f);
        
        seg[p].c = seg[e].c;
        seg[p].f = seg[d].f;
        seg[p].q = seg[e].q + seg[d].q;
    }
}

int main(){

    cin >> N;   

    int cont = 0, cont2;    

    while(N--){
        
        memset(v,0,sizeof(v));
        memset(seg,0,sizeof(seg));
        memset(lazy,0,sizeof(lazy));
        
        s2.clear();

        s2 = 'A'; 

        cont2 = 0;
        
        cout << "Case " << ++cont << ":\n";
        
        cin >> k;

        FOR(i,k){
            cin >> t >> s;
            FOR(j,t){
                s2+= s;
            }
        }

        n = s2.size()-1;

        for(int i=1;i<s2.size();i++){
            if(s2[i] == '1')
                v[i] = 1;
            else if(s2[i] == '0')
                v[i] = 0;
        }

        cin >> k;

        int a,b;

        build(1,1,n);

        FOR(i,k){
            cin >> c >> a >> b;
            
            a++;b++;
            
            if(c == 'S'){
                cout << 'Q' << ++cont2 << ": ";
                cout << query(1,1,n,a,b) << endl;
            }else{
                update(1,1,n,a,b,c);
            }
        }
    }

    return 0;
}