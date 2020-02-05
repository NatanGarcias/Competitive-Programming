#include<bits/stdc++.h>
using namespace std;

int e[103][103];

int main ()
{
    int b,c,t=0;
    char d;
    for(;;){   
        t++; 
        cin >> b >> c;
        if(b==0 && c==0)
            break;
        
        for(int i=1;i<103;i++)
            for(int j=1;j<103;j++){
                e[i][j] = 0;
            }
    
        for(int i=1;i<=b;i++)
            for(int j=1;j<=c;j++){
                cin >> d;
                if(d =='*')
                    e[i][j] = 9;
            }

        for(int i=1;i<=b;i++){
            for(int j=1;j<=c;j++){
                for(int k=-1;k<2;k++){
                    for(int l=-1;l<2;l++){
                        if(e[i+k][j+l]==9)
                            if(e[i][j]!=9)
                                e[i][j]++;
                    }
                }
            }
        }
        if(t!=1)
            cout << endl;
        cout << "Field #" << t << ':' << endl;
        
        for(int i=1;i<=b;i++){
            for(int j=1;j<=c;j++){
                if(e[i][j]==9)
                    cout << '*';
                else
                    cout << e[i][j];
            }
            cout << endl;
        }
    }
    return 0; 
}