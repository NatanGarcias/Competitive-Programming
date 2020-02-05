#include<bits/stdc++.h>
using namespace std;

int main(){
    double a,b;
    string c,d;
    int k;
    vector<string > f;
    while(cin >> a){
        if(a<0){
            cin >> c >> b;
            getline(cin,d);
            break;
        }
        cin >> c ;
        scanf("%lf " ,&b);
        getline(cin,d);
        if((a*100/b)<1.0){
            f.push_back(d);
        }
        else{
            cout << d << " " << fixed << setprecision(1) << a;
            k = a/b*100;
            cout << " " << c << " " << setprecision(0) << a/b*100 << "%" << endl;
        }
    }
    //if(f.size()>0)
        cout << "Provides no significant amount of:"<< endl;
    for(int i=0;i<f.size();i++){
           cout << f[i] << endl;
        
    }
    return 0;
}