#include <iostream>
using namespace std;
int main()
{
	double millakm = 1.609;
	double millas;
	double kilometros;
	cout << "Escribe las millas que quieres convertir a kilometros: \n";
	cin >> millas;
	cout << "Estas millas en kilometros equivalen a: \n";
	kilometros = millas * millakm;
	cout << kilometros << "Kilometros";
	cin.ignore();
	cin.get();
	return 0;
}