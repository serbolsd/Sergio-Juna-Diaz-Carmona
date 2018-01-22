#include <iostream>
#include <string>
using namespace std;
int main()
{
	int numero;
	string resultado;
	cout << "Ingrese el numero que quiere revisar para saber si es o no par:\n";
	cin >> numero;
	if (numero % 2 == 0)
	{
		resultado = "par";
	}
	else
	{
		resultado = "impar";
	}
	cout << "\n";
	cout << "El numero " << numero << " es " << resultado;
	cin.ignore();
	cin.get();
	return 0;
}