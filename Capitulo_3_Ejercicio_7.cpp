#include <iostream>
#include <string>
using namespace std;
int main()
{
	string val2, val3, menor, mayor, medio;

	cout << "Este es un programa para acomodar 3 numeros de mayor a menor\n";
	cout << "Ingrese el valor 1: ";
	string val1;
	cin >> val1;
	cout << "Ingrese el valor 2: ";
	cin >> val2;
	cout << "Ingrese el valor 3: ";
	cin >> val3;
	cout << "\n";
	if (val1 == val2)
	{
		medio = val1;
		if (val2<val3)
		{
			menor = val2;
			mayor = val3;
		}
		else if (val2>val3)
		{
			menor = val3;
			mayor = val2;
		}
		else if (val2 == val3)
		{
			menor = val3;
			mayor = val2;
		}
	}
	else if (val1 == val3)
	{
		medio = val1;
		if (val2<val3)
		{
			menor = val2;
			mayor = val3;
		}
		else if (val2>val3)
		{
			menor = val3;
			mayor = val2;
		}
		else if (val2 == val3)
		{
			menor = val3;
			mayor = val2;
		}
	}
	else if (val2 == val3)
	{
		medio = val2;
		if (val1<val3)
		{
			menor = val1;
			mayor = val3;
		}
		else if (val1>val3)
		{
			menor = val3;
			mayor = val1;
		}
		else if (val1 == val3)
		{
			menor = val3;
			mayor = val1;
		}
	}
	else if (val1 > val2)
	{
		if (val1 > val3)
		{
			mayor = val1;
			if (val2 > val3)
			{
				medio = val2;
				menor = val3;
			}
			else
			{
				medio = val3;
				menor = val2;
			}

		}
		else
		{
			mayor = val3;
			medio = val1;
			menor = val2;
		}
	}
	else if (val1 < val2)
	{
		if (val2> val3)
		{
			mayor = val2;
			if (val1 >val3)
			{
				medio = val1;
				menor = val3;
			}
			else
			{
				medio = val3;
				menor = val1;
			}
		}
		else
		{
			mayor = val3;
			medio = val2;
			menor = val1;
		}
	}


	cout << "El orden de menor a mayor es: " << menor << ", " << medio << ", " << mayor << "\n";

	cin.ignore();
	cin.get();
	return 0;
}