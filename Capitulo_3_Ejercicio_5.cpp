#include <iostream>
using namespace std;
int main()
{
	float val1, val2, menor, mayor, suma, resta1, resta2, multiplica, divi1, divi2;
	cout << "Este es un programa para dos numeros, muestra cual es el mayor, cual el menor, la suma de estos, la diferencia entre ellos, su multiplicacion y su division\n";
	cout << "Ingrese el valor 1: ";
	cin >> val1;
	cout << "Ingrese el valor 2: ";
	cin >> val2;
	cout << "\n";
	if (val1 > val2)
	{
		menor = val2;
		mayor = val1;
	}
	else
	{
		menor = val1;
		mayor = val2;
	}
	double suma = val1 + val2;
	double resta1 = val1 - val2;
	double resta2 = val2 - val1;
	double multiplica = val1 * val2;
	double divi1 = val1 / val2;
	double divi2 = val2 / val1;

	cout << "El numero mayor es: " << mayor << "\n";
	cout << "El numero menor es: " << menor << "\n";
	cout << "La resta de " << val1 << " menos " << val2 << " es: " << resta1 << "\n";
	cout << "La resta de " << val2 << " menos " << val1 << " es: " << resta2 << "\n";
	cout << "La multiplicacion de estos numeros es: " << multiplica << "\n";
	cout << "La division de " << val1 << " entre " << val2 << " es: " << divi1 << "\n";
	cout << "La division de " << val2 << " entre " << val1 << " es: " << divi2 << "\n";

	cin.ignore();
	cin.get();
	return 0;
}