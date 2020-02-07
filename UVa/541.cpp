#include<bits/stdc++.h>
using namespace std;
int main(){
    int a;
    x:
    y:
    while(cin >> a){
        if(a==0)
          break;

        int b[a][a] = {{0}};

        for(int i=0;i<a;i++){
            for(int j=0;j<a;j++){
              cin >> b[i][j];
            }
        }
        int cont;
        int guard =0;
        int guard2 =0;
        for(int i=0;i<a;i++){
            cont =0;
            for(int j=0;j<a;j++){
              if(b[i][j])
                cont++;
            }
            if(cont%2){
                if(!guard)
                  guard = i;
                else{
                  cout << "Corrupt" << endl;
                  goto x;
                }
            }
        }
        for(int i=0;i<a;i++){
            cont =0;
            for(int j=0;j<a;j++){
              if(b[j][i])
                cont++;
            }
            if(cont%2){
                if(!guard2)
                  guard2 = i;
                else{
                  cout << "Corrupt" << endl;
                  goto y;
                }
            }
        }
        if(guard && guard2)
          cout << "Change bit (" << guard+1 << "," << guard2+1 <<  ")" << endl;
        else
          cout << "OK" << endl;
      }
    return 0;
}