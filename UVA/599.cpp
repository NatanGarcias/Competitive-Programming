#include<bits/stdc++.h>
using namespace std;

int a,b;

bool f( vector<vector<int>> &v){
    
    int c=0;
    
    for(int i=0;i<b;i++){
        c=0;
        for(int j=0;j<a;j++){
            if(v[j][i])
                c++;    
        }
        if(c!=2){
            return false; 
        } 
    }
    return true;

}

bool colunasIgual(vector<vector<int>> & v,int c,int d){
	bool igual = true;
	for(int i=0;i<a;i++){
		if(v[i][c] != v[i][d])
			igual = false;
	}
	return igual;
}

bool g(vector<vector<int>> & v){

    for(int i=0;i<b-1;i++){
    	for(int j=i+1;j<b;j++){
    		if(colunasIgual(v,i,j))
    			return false;
    	}
    }
    return true;

}

int main (){

    int n;
    cin >> n;

    for(int i=0;i<n; i++){

        cin >> a >> b;
     
        vector<vector<int>> v(a,vector<int> (b,0));

        for(int j=0;j<a;j++){
            for(int k=0;k<b;k++){
                cin >> v[j][k];
            }
        }

        if(f(v) && g(v))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;        
    }

}
