#include<bits/stdc++.h>
using namespace std;

int main(){
	int win;
	int a,b,c;
	cin >> a >> b>> c ;
	if(a==b){
		if(b<c)
			win =1;
		else
			win =-1;
	}
	else if(a>b){
		if(b<=c)
			win =1;
		else if(b-c<a-b)
			win =1;
		else
			win =-1;
	}
	else if (b>a){
		if(b>=c)
			win =-1;
		else if(c-b<b-a)
			win = -1;
		else
			win = 1;
	}
	if(win == 1)
		cout <<":)"<< endl;
	else
		cout << ":(" << endl;

}