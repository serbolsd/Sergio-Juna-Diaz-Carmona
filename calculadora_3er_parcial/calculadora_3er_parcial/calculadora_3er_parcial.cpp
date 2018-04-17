#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

using namespace std;

void crear_archivo(string archi)
{
	ofstream archivo_n(archi.c_str());
	archivo_n.open(archi.c_str(), ios::out);
}

void agregar_nuevo(string n, string *total, int nt)
{
	ofstream archivo_n(n.c_str(), ios::app);
	for (int i = 0; i < nt; i++)
	{
		if (nt == 1)
		{
			archivo_n << "Resultado= ";
		}
		archivo_n << total[i];
	}
	archivo_n << "\n";
}

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
void imprimir(vector <char>& ope, vector <double>& num)
{
	string nuevoar = "respuestas.txt";
	int nt = ope.size() + num.size();
	string *total = new string[nt];
	int t = 0;
	int l = 0;
	while (t<nt)
	{
		char m[50];
		snprintf(m, 50, "%f", num[l]);
		string to = m;
		total[t] = to;
		t += 2;
		l += 1;
		/*for (int i = 0; i < 50; i++)
		{
		m[i] = '/0';
		}*/
	}
	int t2 = 1;
	int o = 0;
	while (t2<nt)
	{
		/*char m[50];
		snprintf(m,50, "%0", ope[o]);
		string to = m;*/
		total[t2] = ope[o];
		t2 += 2;
		o += 1;
	}
	for (size_t a = 0; a < nt; a++)
	{
		if (nt== 1)
		{
			cout << "Resultado= ";
		}
		cout << total[a] << " ";
	}
	agregar_nuevo(nuevoar, total, nt);
	cout << "\n";
	delete[]total;
}

void acomodar(int& i, vector <char>& ope, vector <double>& num, double resultado)
{
	string nuevoar = "respuestas.txt";
	//crear_archivo(nuevoar);
	int n = num.size();
	int n2 = ope.size();
	int j = i;
	if (ope.size()>0)
	{
		num[i] = resultado;
		if (num.size()>ope.size())
		{
			i += 1;
			while (i<n - 1)
			{
				num[i] = num[i + 1];
				i++;
			}
			num.pop_back();
		}
		else if (ope[i] == 'l' || ope[i] == 'L')
		{

		}
		else
		{
			i+=1;
			while (i<n-1)
			{
				num[i] = num[i + 1];
				i++;
			}
			num.pop_back();
		}
		while (j<n2-1)
		{
			ope[j] = ope[j + 1];
			j++;
		}
		ope.pop_back();
		/*int nt = ope.size()+num.size();
		string *total= new string[nt];
		int t = 0;
		int l = 0;
		while (t<nt)
		{
			char m[50];
			snprintf(m, 50, "%f", num[l]);
			string to = m;
			total[t]=to;
			t+=2;
			l+=1;
			/*for (int i = 0; i < 50; i++)
			{
				m[i] = '/0';
			}*/
		/*}
		int t2 = 1;
		int o = 0;
		while (t2<nt)
		{
			/*char m[50];
			snprintf(m,50, "%0", ope[o]);
			string to = m;*/
			/*total[t2] = ope[o];
			t2 += 2;
			o+=1;
		}
		for (size_t a = 0; a < nt; a++)
		{
			cout << total[a]<<" ";
		}
		agregar_nuevo(nuevoar, *total, nt);
		cout << "\n";
		delete[]total;*/
		imprimir(ope, num);
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

	while (ope.size()>0)
	{
		int i = 0;
		while (i < ope.size())
		{
			if (ope[i] == 'p'|| ope[i] == 'P')
			{
				double nume, nume2, pot,resultado;
				int p = 1;
				nume = num[i];
				pot = num[i + 1];
				nume2 = nume;
				while (p<pot)
				{
					nume = nume * nume2;
					p++;
				}
				resultado = nume;
				acomodar(i, ope, num, resultado);
			}
			i++;
		}
		i = 0;
		while (i < ope.size())
		{
			if (ope[i] == 'r' || ope[i] == 'R')
			{
				double nume, ra, resultado;
				nume = num[i];
				ra = num[i + 1];
				resultado = pow(nume,(1/ra));
				acomodar(i, ope, num, resultado);
			}
			i++;
		}
		i = 0;
		while (i < ope.size())
		{
			if (ope[i] == 'l' || ope[i] == 'L')
			{
				double nume, nume2,resultado;
				//num.size()>1 && 
				if (ope.size()==(num.size()))
				{
					nume = num[i];
					resultado = log(nume) / log(2.718281828);
				}
				else 
				{
					nume = num[i];
					nume2 = num[i + 1];
					nume2=log(nume2) / log(2.718281828);
					resultado = nume * nume2;
				}
				acomodar(i, ope, num, resultado);
			}
			i++;
		}
		i = 0;
		while (i < ope.size())
		{
			if (ope[i] == 's' || ope[i] == 'S')
			{
				double nume, nume2,resultado;
				nume = num[i];
				nume2 = num[i+1];
				nume2= nume2*3.14159 / 180;
				resultado = nume*(sin(nume2));
				acomodar(i, ope, num, resultado);
			}
			i++;
		}
		i = 0;
		while (i < ope.size())
		{
			if (ope[i] == 'C' || ope[i] == 'c')
			{
				double nume, nume2, resultado;
				nume = num[i];
				nume2 = num[i + 1];
				resultado = nume * (cos(nume2*3.14159 / 180));
				acomodar(i, ope, num, resultado);
			}
			i++;
		}
		i = 0;
		while (i < ope.size())
		{
			if (ope[i] == 'T' || ope[i] == 't')
			{
				double nume, nume2, resultado;
				nume = num[i];
				nume2 = num[i + 1];
				resultado = nume * (tan(nume2*3.14159 / 180));
				acomodar(i, ope, num, resultado);
			}
			i++;
		}
		i = 0;
		while (i < ope.size())
		{
			if (ope[i] == '*')
			{
				double resultado = num[i] * num[i + 1];
				acomodar(i, ope, num, resultado);
			}
			i++;
		}
		i = 0;
		while (i < ope.size())
		{
			if (ope[i] == '/')
			{
				double resultado = num[i] / num[i + 1];
				acomodar(i, ope, num, resultado);
			}
			i++;
		}
		i = 0;
		while (i < ope.size())
		{
			if (ope[i] == '+')
			{
				double resultado = num[i] + num[i + 1];
				acomodar(i, ope, num, resultado);
			}
			i++;
		}
		i = 0;
		while (i < ope.size())
		{
			if (ope[i] == '-')
			{
				double resultado = num[i] - num[i + 1];
				acomodar(i, ope, num, resultado);
			}
			i++;
		}
		i = 0;
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
		bool se_puede = true;
		int j = 0;
		registro = 'A';
		while (registro != '\n')
		{
			/*if (contenido.size()==1)
			{
				registro = contenido[0];
				//num1 = atoi(numeros);
				//numero.push_back(num1);
			}*/
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
				if (operaciones.size() == numero.size())
				{
					numeros[j] = registro;
					j++;
				}
				else
				{
					num1 = atoi(numeros);
					numero.push_back(num1);
					for (int a = 0; a < 9; a++)
					{
						numeros[a] = '\0';
					}
					j = 0;
				}
			}
			else if (registro == '/')
			{
				operaciones.push_back(registro);
				operacion = "divi";
				num1 = atoi(numeros);
				numero.push_back(num1);
				for (int a = 0; a < 9; a++)
				{
					numeros[a] = '\0';
				}
				j = 0;
			}
			else if (registro == 'P' || registro=='p')
			{
				operaciones.push_back(registro);
				num1 = atoi(numeros);
				numero.push_back(num1);
				for (int a = 0; a < 9; a++)
				{
					numeros[a] = '\0';
				}
				j = 0;
			}
			else if (registro == 'S' || registro == 's')
			{
				operaciones.push_back(registro);
				num1 = atoi(numeros);
				numero.push_back(num1);
				for (int a = 0; a < 9; a++)
				{
					numeros[a] = '\0';
				}
				j = 0;
			}
			else if (registro == 'C' || registro == 'c')
			{
				operaciones.push_back(registro);
				num1 = atoi(numeros);
				numero.push_back(num1);
				for (int a = 0; a < 9; a++)
				{
					numeros[a] = '\0';
				}
				j = 0;
			}
			else if (registro == 'T' || registro == 't')
			{
				operaciones.push_back(registro);
				num1 = atoi(numeros);
				numero.push_back(num1);
				for (int a = 0; a < 9; a++)
				{
					numeros[a] = '\0';
				}
				j = 0;
			}
			else if (registro == 'L' || registro == 'l')
			{
				operaciones.push_back(registro);
				num1 = atoi(numeros);
				if (num1>0)
				{
				numero.push_back(num1);
				}
				for (int a = 0; a < 9; a++)
				{
					numeros[a] = '\0';
				}
				j = 0;
			}
			else if (registro == 'R' || registro == 'r')
			{
				operaciones.push_back(registro);
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
				if (numeros[j]== 0 && operacion=="divi")
				{
					se_puede = false;
				}
				else
				{
					operacion = "nada";
				}
				j++;
			}
			i++;
		}
		if (numero.size() == 1)
		{
			cout << numero[0] << "\n";
		}
		else if (se_puede)
		{
			imprimir(operaciones, numero);
			gerarquia_oper(operaciones, numero);
		}
		else
		{
			cout << "No se puede hacer esta operacion\n";
		}
		/*
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
		
		if (operacion == "suma")
			result = num1 + num2;
		cout << result << endl;*/
		cout << "\n";
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
	string nuevoar = "respuestas.txt";
	crear_archivo(nuevoar);
	string mensaje = ("Esta calculadora funciona con los siguientes parametros:\n\
	1)La 'P' o 'p' es para sacar la potencia del numero de la izquierda\n\
	2)La 'R' o 'r' es para sacar la raiz del numero de la izquierda\n\
	3)La 'S' o 's' es para calcular el seno\n\
	4)La 'C' o 'c' es para calcular el coseno\n\
	5)La 'T' o 't' es para calcular la tangente\n\
	6)La 'L' o 'l' es para calcular el logaritmo natural");
	cout << mensaje<<"\n Presione CUALQUIER TECLA para continuar\n";
	ofstream archivo_n(nuevoar.c_str(),ios::app);
	archivo_n << mensaje<<"\n\n\n";
	archivo_n.close();
	cin.get();
	system("cls");
	leer_archivo(nombre, contenidoarchivo);
	cout << contenidoarchivo << endl;
	cout << "\n";
	operaciones(contenidoarchivo);
	cout << "La operaciones y los resultados de han guardado en un archivo .txt llamado '" << nuevoar << "'" << endl;
	cout << "Presione cualquier tecla para terminar"<<endl;
	cin.ignore();
	//delete (contenidoarchivo);
	//delete[] numeros;
	return 0;
}