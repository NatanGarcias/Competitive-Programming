#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{

 double raio, pi, volume;
 
 cin >> raio;
 
pi = 3.14159;
volume = (4/3.0) * pi * (raio*raio*raio);

cout << fixed << setprecision(3) << "VOLUME = " << volume<< endl;

return 0;
}