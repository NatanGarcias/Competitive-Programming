#include<bits/stdc++.h>
using namespace std;

#define FOR(x,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define INF 0x3f3f3f3f
#define endl "\n"
#define space " "

int N,n;
string s;

void grid(){

    pii atual = make_pair(0,0);

    int menor = INF;
    int t = 0, a = -1, b = -1;

    map<pii,int> m;

    m[atual] = t;    
    
    FOR(i,n){
        t++;
        if(s[i] == 'L'){
            atual.first--;
        }else if(s[i] == 'R'){
            atual.first++;
        }else if(s[i] == 'D'){
            atual.second--;
        }else {
            atual.second++;
        }

        if(m.find(atual) == m.end()){
            m[atual] = t;
        }else{
            if(menor > t-m[atual]){
                menor = t-m[atual];
                b = t;
                a = m[atual];
            }
            m[atual] = t;
        }
    }

    if(a == -1)
        cout << -1 << endl;
    else 
        cout << a+1 << space << b << endl;
}

int main(){

    cin >> N;

    while(N--){
        cin >> n >> s;

        grid();
    }
    return 0;
}