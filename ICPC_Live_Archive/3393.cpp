#include<bits/stdc++.h>
using namespace std;

int main(){
    double a,b,c,d;
    while(cin >> a >> b >> c >> d){
        if(a==0 && b ==0 && c==0 && d==0){
            break;
        }
        if(a<b)
            swap(a,b);
        if(c<d)
            swap(c,d);
        
        if(a<c && b<d){
            cout << "100%" << endl;
        }
        else{
            int porcentagem = 1;    
            while(a*porcentagem/100.0<=c && b*porcentagem/100.0<=d){
                    //cout << a*porcentagem/100.0 <<" "  << b*porcentagem << endl; 
                    porcentagem++;
            }
            cout << porcentagem-1 << '%' << endl;
        }
    }
    return 0;
}