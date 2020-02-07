#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    x:
    y:
    while(cin >> a >> b){
        if(!a && !b)
            break;
        int c[a];
        int d[b];
        for(int i=0;i<a;i++){
            cin >> c[i];
        }
        for(int i=0;i<b;i++){
            cin >> d[i];
        }
        sort(c,c+a);
        sort(d,d+b);
        int cont=0;
        int j=0;
        for(int i=0;i<b;i++){
            if(c[j]<=d[i]){
                cont+= d[i];
                j++;
            }
            if(j==a){
                cout << cont << endl;
                goto y;
            }
        }
        if(j!=a){
            cout <<"Loowater is doomed!" << endl;
            goto x;
        }
        cout << cont << endl;
    }
    return 0;
}
