#include<bits/stdc++.h>
using namespace std;

int score;
int f,g,y,z,h= 1000;
vector<int> temp;
void escreve(int c[], int n){
	if(abs(10*temp[c[0]]+temp[c[1]]+ 10*temp[c[2]]+temp[c[3]] -100) < abs(h-100)){
		f = temp[c[0]];
		g = temp[c[1]];
		y = temp[c[2]];
		z = temp[c[3]];
		h = 10*temp[c[0]]+temp[c[1]]+ 10*temp[c[2]]+temp[c[3]];
 	}
}

void permutacoes(int n){
    int c[n];
    for(int i=0;i<n;i++)						//gera vetor com valores
        c[i]= i;
    
    do {
        escreve(c,n);
    } while (next_permutation(c,c+n)); 
}
int main(){
	string a;
	while(getline(cin,a)){
		if(a.empty()){
			cout << "score: " << score << endl;
			score = 0;
			temp.clear();
			continue;
		}
		for(int i=0;i<a.size();i++){
			temp.push_back(a[i]-48);
		}
		permutacoes(temp.size());
		cout << setfill('0') << setw(2) << 10*f+g << '+' << setfill('0') << setw(2) << 10*y+z  << '=' << setfill('0') << setw(3) << h << endl;
		
		vector<int>::iterator it = temp.begin();
		
		for(it= temp.begin();it!=temp.end();it++){
			if(*it == f){
				temp.erase(it);
				break;
			}
		}
		for(it= temp.begin();it!=temp.end();it++){
			if(*it == g){
				temp.erase(it);
				break;
			}
		}
		for(it= temp.begin();it!=temp.end();it++){
			if(*it == y){
				temp.erase(it);
				break;
			}
		}
		for(it= temp.begin();it!=temp.end();it++){
			if(*it == z){
				temp.erase(it);
				break;
			}
		}
		score+= abs(100 - h);
		h = 1000;
	}
	cout << "score: " << score << endl;
	return 0;
}