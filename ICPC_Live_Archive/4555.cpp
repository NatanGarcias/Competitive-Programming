#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,e,cont,j,tmp;
    bool ultimo;
    cin >> a;
    for(int m=0;m<a;m++){
        int b,c;
        cin >> b >> c;
        vector<int> d;
        cin >> e;
        d.push_back(e);
        cout << b << " " << (c/2)+1 << endl;
        cout << d[0];
        cont =1;
        for(int i=0;i<c-1;i++){
            cin >> e;
            d.push_back(e);
                j = d.size()-1;
                while (j>0 && d[j-1] > d[j]) {
                    tmp = d[j];
                    d[j] = d[j-1];
                    d[j-1] = tmp;
                    j--;
                }
            if(i%2==1){
                if(cont ==9){
                    ultimo = true;
                    cout <<" " << d[i/2+1] << endl;
                    cont =0;
                }
                else if(cont ==0){
                    ultimo = false;
                    cout << d[i/2+1];
                    cont++;
                }
                else{
                    ultimo = false;
                    cont++;
                    cout << " " << d[i/2+1];
                }
            }
        }
        if(!ultimo)
           cout << endl;
    }
    return 0;
}