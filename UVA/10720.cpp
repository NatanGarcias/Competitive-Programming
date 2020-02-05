#include<bits/stdc++.h>
using namespace std;

int a,b;

bool cmp(const int &a, const int &b){
    if(a>b)
        return true;
    else 
        return false;
}

bool g(vector<int> &v){

    for(int i=0;i<a;i++){

        sort(v.begin(),v.end(),cmp);
        b = v[0];
        
        if(b<=0)
            return true;
        else{
            v.erase(v.begin());
            for(int j=0;j<b;j++){
                if(j>v.size() || !v[j])
                    return false;
                else 
                    v[j]--;
            }
        }
    }
    return false;
}

void f(vector<int>&v){
    if(g(v))
        cout << "Possible" << endl;
    else
        cout << "Not possible" << endl;
}

int main (){
    
    while(cin >> a){
        if(a==0)
            return 0;
        vector<int> v(a);

        for(int i=0;i<a;i++)
            cin >> v[i];

        f(v);
    }    
}
