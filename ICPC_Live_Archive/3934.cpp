#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int a,b;
	
	while(cin >> a >> b){
		if(a== 0 && b ==0)
			break;
		
		int c[a],d[b];
		
		for(int i=0;i<a;i++)
			cin >> c[i];
		for(int i=0;i<b;i++)
			cin >> d[i];
		
		sort(c,c+a);
		sort(d,d+b);
		
		if(c[0] >= d[1])
			cout << 'N' << endl;
		else
			cout << 'Y' << endl;
	}
	return 0;
}