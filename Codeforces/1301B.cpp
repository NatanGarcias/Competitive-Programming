#include<bits/stdc++.h>
using namespace std;

#define MAXN 100010
#define INF 0x3f3f3f3f
#define ll int

ll N,n;
ll v[MAXN];

ll f(ll x){

    ll menor = -1;

    for(int i=0;i<n-1;i++){
        if(v[i] == -1 && v[i+1] == -1){
            menor = max(0,menor);
        }
        else if(v[i] == -1){
            menor = max(menor,abs(x - v[i+1]));
        }else if(v[i+1] == -1){
            menor = max(menor,abs(x - v[i]));
        }else{
            menor = max(menor,abs(v[i] - v[i+1]));
        }
    }
    return menor;
}

int bb(){

    ll l = 0, r = INF ;

	while(abs(l-r) > 0){

		ll m1 = l + (r-l)/3.0;
		ll m2 = l + 2.0*( (r-l)/3.0 );

        //cout << l << " " << m1 << " " << m2 << " " << r << endl;
        
        // f calcula o valor da função no ponto requerido
		ll f1 = f(m1);
		ll f2 = f(m2);
        //cout << f1 << " " << f2 << endl;
		//Para encontrar o minimo da funcao basta colocar f1 <= f2 na condição
		if(f1 <= f2){
			r = m2;
		}else if(f1 == f2){
            r = m2;
        }else{
			l = m1+1;
		}
	}
	return l;
}

int main(){
    cin >> N;
    
    while(N--){
        cin >> n;

        memset(v,0,sizeof(v));

        for(int i=0;i<n;i++){
            cin >> v[i];
        }

        ll ans = bb();
        cout << f(ans) << " " << ans << endl;
    }
    return 0;
}