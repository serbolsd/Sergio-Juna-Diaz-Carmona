#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;

void leer_archivo(string nombre,string& cosa)
{
	//char *lector = new char[1000];
	char lector[1000];
	string nom =nombre;
	char simbolo = '¹';
	ifstream *archivo = new ifstream (nom.c_str());
	archivo->getline(lector, 1000, '\0');
	cosa = lector;
	//delete (nom);
	delete (archivo);
	//delete []lector;
}

void operaciones(string contenido)
{
	vector <char> operaciones;
	vector <int> numero;
	char numeros[10];
	for (int a = 0; a < 9; a++)
	{
		numeros[a] = '\0';
	}
	string operacion;
	char registro = 'A';
	int num1, num2, result;

	int i = 0;
	
	while (registro != '\0')
	{
		int j = 0;
		registro = 'A';
		while (registro != '\n')
		{
			if(i<contenido.size()+1)
				registro = contenido[i];
			else
			{
				break;
			}
			if (registro == ' ')
			{

			}
			else if (registro == '\n' || registro == '\0')
			{
				num1 = atoi(numeros);
				numero.push_back(num1);
			}
			else if (registro == '+')
			{
				operaciones.push_back(registro);
				operacion = "suma";
				num1 = atoi(numeros);
				numero.push_back(num1);
				for (int a = 0; a < 9; a++)
				{
					numeros[a] = '\0';
				}
				j = 0;
			}
			else if (registro == '*')
			{
				operaciones.push_back(registro);
				operacion = "suma";
				num1 = atoi(numeros);
				numero.push_back(num1);
				for (int a = 0; a < 9; a++)
				{
					numeros[a] = '\0';
				}
				j = 0;
			}
			else if (registro == '-')
			{
				operaciones.push_back(registro);
				operacion = "suma";
				num1 = atoi(numeros);
				numero.push_back(num1);
				for (int a = 0; a < 9; a++)
				{
					numeros[a] = '\0';
				}
				j = 0;
			}
			else if (registro < 65)
			{
				numeros[j] = registro;
				j++;
			}
			i++;
		}
		for (int i = 0; i < operaciones.size(); i++)
		{
			if (operaciones[i] == '+')
			{
				num1 = numero[i];
				num2 = numero[i + 1];
				result = num1 + num2;
			}
			else if (operaciones[i] == '-')
			{
				num1 = numero[i];
				num2 = numero[i + 1];
				result = num1 - num2;
			}
			else if (operaciones[i] == '*')
			{
				num1 = numero[i];
				num2 = numero[i + 1];
				result = num1 * num2;
			}
		}
		/*
		if (operacion == "suma")
			result = num1 + num2;*/
		cout << result << endl;
		while (operaciones.size()>0)
		{
			operaciones.pop_back();
		}
		while (numero.size() > 0)
		{
			numero.pop_back();
		}
		for (int a = 0; a < 9; a++)
		{
			numeros[a] = '\0';
		}

	}
}

int main()
{
	string contenidoarchivo;
	string nombre = "prueba.txt";
	leer_archivo(nombre, contenidoarchivo);
	cout << contenidoarchivo << endl;
	operaciones(contenidoarchivo);
	//cin.ignore();
	cin.get();
	//delete (contenidoarchivo);
	//delete[] numeros;
	return 0;
}