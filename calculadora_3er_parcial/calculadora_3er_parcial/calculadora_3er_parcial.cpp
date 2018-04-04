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

void acomodar(int i, vector <char>& ope, vector <double>& num, int resultado)
{

	int n = num.size();
	int n2 = ope.size();
	int j = i;
	if (ope.size()>0)
	{
		num[i] = resultado;
		i+=1;
		while (i<n-1)
		{
			num[i] = num[i + 1];
			i++;
		}
		num.pop_back();
		while (j<n2-1)
		{
			ope[j] = ope[j + 1];
			j++;
		}
		ope.pop_back();
		int nt = ope.size()+num.size();
		string *total= new string[nt];
		int t = 0;
		while (t<nt)
		{
			int i = 0;
			char m[50];
			snprintf(m, 50, "%f", num[i]);
			string to = m;
			total[t]=to;
			t+=2;
			i++;
			/*for (int i = 0; i < 50; i++)
			{
				m[i] = '/0';
			}*/
		}
		int t2 = 1;
		while (t2<nt)
		{
			int i = 0;
			char m[50];
			snprintf(m,50, "%f", ope[i]);
			string to = m;
			total[t2] = to;
			t2 += 2;
			i++;
		}
		for (size_t a = 0; a < nt; a++)
		{
			cout << total[a];
		}
	}
}

void gerarquia_oper(vector <char> operaciones, vector <double> numero)
{
	vector <char> ope;
	vector <double> num;
	for (int i = 0; i < operaciones.size(); i++)
	{
		ope.push_back(operaciones[i]);
	}
	for (int i = 0; i < numero.size(); i++)
	{
		num.push_back(numero[i]);
	}

	for (int i = 0; i < ope.size(); i++)
	{
		if (ope[i]=='*')
		{
			int resultado = num[i] * num[i + 1];
			acomodar(i, ope, num, resultado);
		}

	}

}

void operaciones(string contenido)
{
	vector <char> operaciones;
	vector <double> numero;
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
		
		gerarquia_oper(operaciones,numero);

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