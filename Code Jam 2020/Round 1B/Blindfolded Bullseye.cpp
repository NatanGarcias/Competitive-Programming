#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define FOR(x,a,n) for(int x= (int)(a);(x) < int(n);(x)++)
#define endl "\n";
#define erro 0x3f3f3f3f3f3f3f3f

ll T,A,B;
string s;
ll menor = -10e8, maior = 10e8;
ll c = 0, f = maior*2;

ll verifica(ll x, ll y){
    cout << x - maior << " " << y - maior << endl;
    cin >> s;

    if(s[0] == 'C'){
        return 2;
    }else if(s[0] == 'H'){
        return 1;
    }else{
        return 0;
    }
}

ll bb(ll posX, ll posY){

    ll l = c, r = posX;
    
    while(true){
        ll m = (l+r)/2;
        if(l == r){
            return m;
        }

        ll aux = verifica(m,posY);
        if(aux == 2) return erro;
        else if(aux == 1){
            r = m;
        }else {
            l = m+1;
        }
    }
}

ll bb2(ll posX, ll posY){

    ll l = posX, r = f;

    while(true){
        ll m = (l+r+1)/2;

        if(l == r){
            return m;
        }
        ll aux = verifica(m,posY);
        if(aux == 2) return erro;
        else if(aux ==1){
            l = m;
        }else {
            r = m-1;
        }
    }
}

ll bb3(ll posX, ll posY){

    ll l = posY, r = f;

    while(true){
        ll m = (l+r+1)/2;

        if(l == r){
            return m;
        }

        ll aux = verifica(posX,m);
        if(aux == 2) return erro;
        else if(aux ==1){
            l = m;
        }else {
            r = m-1;
        }
    }
}


ll bb4(ll posX, ll posY){

    ll l = c, r = posY;

    while(true){
        ll m = (l+r)/2;

        if(l == r){
            return m;
        }
        ll aux = verifica(posX,m);
        if(aux == 2) return erro;
        else if(aux ==1){
            r = m;
        }else {
            l = m+1;
        }
    }
}

void solve(){

    ll posX, posY = A -1;
    bool achei = false;

    while(posY <= maior){
        posX = A-1;
        while(posX <= maior){
            cout << posX - maior << " " << posY - maior << endl;
            cin >> s;

            if(s[0] == 'C'){
                return;
            }else if (s[0] == 'H'){
                achei = true;
                break;
            }
            posX += A;
        }
        if(achei) break;
        posY += A;
    }

    ll Esq,Dir,Cima,Baixo;

    Esq = bb(posX,posY);
    if(Esq == erro) return;
    
    Dir = bb2(posX,posY);
    if(Dir == erro) return;

    posX = Esq;

    Cima = bb3(posX,posY);
    if(Cima == erro) return;

    Baixo = bb4(posX,posY);
    if(Baixo == erro) return;

    for(int i = -2 ; i<= 2 ;i++){
        for(int j = -2 ; j<= 2 ;j++){
            cout << ((Esq + Dir)/2)+i - maior << " " <<  ((Cima + Baixo)/2)+j - maior << endl;
            cin >> s;
            if(s[0] == 'C') return;
        }   
    }
}

int main(){

	cin >> T >> A >> B;

    FOR(i,0,T){
        solve();
    }

    return 0;
}