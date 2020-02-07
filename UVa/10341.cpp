#include<bits/stdc++.h>
using namespace std;

#define ld long double
ld euler = exp(1);

ld fa(ld p, ld q, ld r, ld s, ld t, ld u, ld x){
	return p*pow(euler,-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}
int main(){
	
	ld a,b,c,d,e,f,g,h;
	while(cin >>a >>  b >> c >> d >> e>> f){
		g = 0.0;
		h = 1.0;
		ld erro = 10E-12;
		ld aux1,aux2;
		aux1 = fa(a,b,c,d,e,f,g);
		aux2 = fa(a,b,c,d,e,f,h);
		if(aux1*aux2 >0){
			cout << "No solution" << endl;
			continue;
		}
		else if(fabs(aux1)<erro){
			printf("%.4Lf\n",g);
			continue;
		}
		else if(fabs(aux2)<erro){
			printf("%.4Lf\n",h);
			continue;
		}
		ld err = 10;
		ld prox;
		while(err > erro){
			aux1 = fa(a,b,c,d,e,f,h);
			aux2 = fa(a,b,c,d,e,f,g);
			prox = (aux1*g - aux2*h) /(aux1 - aux2);
			err = fabs(prox-h);
			g = h;
			h = prox;
		}
		printf("%.4Lf\n",prox);
	}
}	