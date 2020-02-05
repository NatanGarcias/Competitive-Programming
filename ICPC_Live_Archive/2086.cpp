#include<bits/stdc++.h>
using namespace std;

#define all(v) v.begin(),v.end()

int main(){
    string s;
    while(getline(cin,s)){
        stringstream ss;
        ss << s;
        string a;
        vector<int> lie;
        vector<int> num;
        vector<string> str;
        while(ss >> a){
            if(a[0]== '.')
                goto x;
            a.pop_back();
            if((a[0]>='0' && a[0]<='9') || a[0] =='-'){
                lie.push_back(1);
                num.push_back(atoi(a.c_str()));
            }
            else{
                lie.push_back(0);
                str.push_back(a);
            }
        }

        int z[str.size()];
        
        vector <string> str2;
        
        for(int i=0;i<str.size();i++){
            z[i] = i;
            str2.push_back(str[i]);
        }

        for(int i=0;i<str.size();i++){
            transform(all(str2[i]),str2[i].begin(), ::tolower);
        }

        for(int i=1;i<str2.size();i++){
        string elementoInserir=str2[i];
		
        int elementoInserir2=z[i];
		int j= i-1;
		
        while(j>=0 && str2[j]>elementoInserir){
            z[j+1] = z[j];
			str2[j+1]=str2[j];
			j--;
		}
		
        str2[j+1]=elementoInserir;
        z[j+1] = elementoInserir2;
	}
        sort(all(num));
        int k,j,i;
        k=j=0;
        for(i=0;i<lie.size()-1;i++){
            if(lie[i]){
                cout << num[j++] << ", ";
            }
            else{
                cout << str[z[k++]] << ", ";
            }
        }
        if(lie[i])
            cout << num[j++] << '.' << endl;
        else
            cout << str[z[k++]] << '.' << endl;;
    }
    x:
    return 0;
}