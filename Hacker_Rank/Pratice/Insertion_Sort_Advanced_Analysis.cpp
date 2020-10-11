#include<bits/stdc++.h>
using namespace std; 

long long int a;

void merge(long long int *v, long long int p, long long int q, long long int r){ //Intercala
	long long int tam= r-p;
	long long int aux[tam];
	long long int i = p; //Cursor 1
	long long int j = q; //Cursor 2
	long long int k = 0; //Cursor para aux
	while(i<q && j<r){
		if(v[i] <= v[j])
			aux[k++] = v[i++];
		else{
            a+=q-i;
			aux[k++] = v[j++];
        }
	}
	while(i < q) //Dois while para preencher o restante
		aux[k++] = v[i++];
	while(j < r)
		aux[k++] = v[j++];
	for(k=0;k < tam; k++) //transferindo o ordenado p/ o original
		v[p+k] = aux[k];
}
void mergeSort(long long int *v, long long int p, long long  int r){ //Divide and conquer
	if(p< r-1){
		long long int meio= (p+r)/2;
		mergeSort(v,p,meio);
		mergeSort(v,meio,r);
		merge(v,p,meio,r); /* intercala */
	}
}
int main(){
	int z;
    cin >> z;
    for(int i=0;i<z;i++){
        a=0;
        int z1;
        cin >> z1;
        long long  int b[z1];
        for(int i=0;i<z1;i++)
            scanf("%lld",&b[i]);
        mergeSort(b,0,z1);
        cout << a << endl;;
    }
	return 0;
}