#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    int k;
    bool err;
    while(cin >> a){
        vector<int> v;
        for(int i=0;i<a;i++){
            cin >> k;
            v.push_back(k);
        }
        vector<int> ordenar;
        for(int i=0;i<a-1;i++)
            ordenar.push_back(abs(v[i] - v[i+1]));
        
        sort(ordenar.begin(),ordenar.end());
        err = false;
        for(int i=0;i<ordenar.size();i++){
            if(i+1!=ordenar[i])
                err = true;
        }   
        if(err)
            cout << "Not jolly" << endl;
        else
            cout << "Jolly" << endl;
    }
    return 0;
}