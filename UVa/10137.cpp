#include<bits/stdc++.h>
using namespace std;

int main(){
   int a;
   char k;
   while( cin >> a){
        if(a==0)
            break;
        int z[a];
        int g,h;
        int media =0;
        for(int i=0;i<a;i++){    
            cin >> g >> k >>  h;
            z[i] = g*100 + h;
            media += z[i];
        } 
        int media2;
        if(media%a!=0)
            media2 = (media/a)+1;
        else
            media2 = media/a;
        media/= a;

        int mudar =0;
        int mudar2 = 0;
        for(int i=0;i<a;i++){
            if(z[i]>media2)
                mudar += z[i] - media2;
            
            if(z[i]<media)
                mudar2 += media - z[i];
        }
        int mudar3;
        mudar>mudar2?mudar3=mudar:mudar3=mudar2;  
        cout << '$' << (mudar3/100) << '.' << setw(2) << setfill('0') << (mudar3%100) << endl;
   }
       return 0;
}