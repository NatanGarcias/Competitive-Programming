#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
  
  int main ()
  {
	double a, b, c, d , e ,media, media2  ;
	
	cin >> a >> b >> c >> d;
	
	media = (a*2+b*3+c*4+d )/10;
	
	cout << fixed << setprecision(1) << "Media: " << media << endl;
	
	if ( media >=7 )
		cout << "Aluno aprovado." << endl;
	else if (media <5)
        cout << "Aluno reprovado." << endl;
    else if (media >= 5 && media<=7)
	{
        cout << "Aluno em exame." << endl;		
		cin >> e ;
		media2 = ( media + e )/2;
		cout << "Nota do exame: " << fixed << setprecision(1) << e << endl;
		if (media2 >=5)
			cout << "Aluno aprovado." << endl;
		else 
			cout << "Aluno reprovado." << endl;
		cout << "Media final: " << fixed << setprecision(1) << media2 << endl;
	}
	
	return 0;
  }
  
  
  
  
  
  
  
  
  
  
  
  
  