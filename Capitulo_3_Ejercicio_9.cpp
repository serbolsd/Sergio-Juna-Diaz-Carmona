#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int main()
{
	string val,cero = "cero", uno = "uno", dos = "dos", tres = "tres", cuatro = "cuatro";
	int valor;
	cout << "Escribe con letrasminusculas el numero (solo un numero del 0 al 4)\n";
	string numero;
	cin >> numero;
	cout << "\n";
	if (numero == cero)
	{
		valor = 0;
	}
	else if (numero == uno)
	{
		valor = 1;
	}
	else if (numero == dos)
	{
		valor = 2;
	}
	else if (numero == tres)
	{
		valor = 3;
	}
	else if (numero == cuatro)
	{
		valor = 4;
	}
	else
	{
		
		val = "si";
	}
	if (val =="si")
	{
		cout << "Estupida computadora";
	}
	else
	{
		cout << valor;
	}
	

	
	cin.ignore();
	cin.get();
	return 0;
}