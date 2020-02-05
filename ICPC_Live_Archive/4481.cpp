#include<bits/stdc++.h>
using namespace std;

int main(){
    char a[300];
    while(cin >> a){
        if(a[0] == '*')
            break;
        int tot =0;
        double cont =0.1;

        for(int i=0;a[i]!='\0';i++){
            if(a[i]== 'W')
                cont = cont+1.0;
            if(a[i]== 'H')
                cont= cont+0.5;
            if(a[i]== 'Q')
                cont = cont+0.25;
            if(a[i]== 'E')
                cont = cont+0.125;
            if(a[i]== 'S')
                cont = cont+0.0625;
            if(a[i]== 'T')
                cont = cont +0.03125;
            if(a[i]== 'X')
                cont +=0.015625;
            if(a[i]== '/'){
                if(cont ==1.1){
                    tot++;
                }
                cont =0.1;
            }  
        }
        cout << tot << endl;
    }
    return 0; 
}