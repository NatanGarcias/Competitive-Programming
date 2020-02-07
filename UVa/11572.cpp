#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b,d;
	cin >> a;
	for(int i=0;i<a;i++){
		scanf("%d",&b);
		vector<int> c;
		if(b==0){			
			cout << '0' << endl;
			continue;
		}
		for(int j=0;j<b;j++){
			scanf("%d",&d);
			c.push_back(d);
		}
		int max2=0;
		for(int k=0;k<b;k++){
			unordered_map<int,int> aux;
			aux[c[k]] = k;
			for(int k1=k+1;k1<b;k1++){
				if(aux.find(c[k1])==aux.end())
					aux[c[k1]] = k1;
				else{
					k = aux[c[k1]];
					break;
				}
			}
			if(b-k<max2)
				break;
			if(aux.size()>max2)
				max2 = aux.size();
		}
		printf("%d\n",max2);
	}
	return 0;
}