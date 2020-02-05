#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,m;
    int OndeEstou,Linhas;
    while(cin >> a >> b >> c){
        Linhas = 0;
        OndeEstou =0;
        string d[a];
        for(int i=0;i<a;i++)
            cin >> d[i];
        
        for(int i=0;i<a;i++){
            m = d[i].size();
            if(OndeEstou==0)
                Linhas++;
            if(m + OndeEstou <=c){
                OndeEstou+= m+1;
            }
            else{
                OndeEstou =0;
                i--;
            }
        }
        if(Linhas%b!=0)
            cout << Linhas/b+1 << endl;
        else
            cout << Linhas/b << endl;
        
    }
    return 0;
}