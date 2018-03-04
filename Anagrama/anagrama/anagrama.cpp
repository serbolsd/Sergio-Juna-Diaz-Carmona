#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <fstream>
//#include "d:\facilities.h"
using namespace std;

void crear_archivo(string n)
{
	ofstream archivo_n;
	archivo_n.open(n.c_str(), ios::out);
}

void escribir_en_nuevo(string n,vector <string> v)
{
	ofstream archivo_n(n.c_str());
	for (int i = 0; i < v.size(); i++)
	{
		archivo_n << v[i] << endl;
	}
}

void leer(vector <string> &v, string n)
{
	ifstream ist(n.c_str());
	char m[256];
	string linea;
	while (true)
	{
		ist.getline(m, 265, '\n');
		linea = m;
		if (linea == "")
		{
			break;
		}
		v.push_back(linea);
	}
	cout << "Las palabras registradas son:" << endl;
	cout << "\n";
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
}

bool verificar(vector <string> v, int i, int j)
{
	string sig_pal = v[j], pal = v[i], letra, letra2;
	if (sig_pal.size() != pal.size())
	{
		return false;
	}
	else
	{
		for (int a = 0; a < sig_pal.size(); a++)
		{
			letra = sig_pal[a];
			for (int d = 0; d < pal.size(); d++)
			{
				letra2 = pal[d];
				if (letra == letra2)
				{
					pal[d] = NULL;
					break;
				}
			}
		}
	}
	if (pal[0]=='\0')
	{
		return true;
	}
	else
	{
		return false;
	}

}

void ordenar(vector <string> &v)
{
	string corrector;
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i+1; i < v.size(); j++)
		{
		
			if (j+1 > v.size())
				break;
			else
			{
				if (verificar(v, i, j))
				{
					corrector = v[j];
					v[j] = v[i + 1];
					v[i + 1] = corrector;
					i++;
				}
			}
			
		}
	}
}



int main()
{
	string nombre,nombre_acomo="anagrama.txt";
	char opcion;
	cout << "si desea ingresar el nombre del archivo ingrese 1\nSi desea usar el predeterminado ingrese cualquier otra cosa" << endl;
	cin >> opcion;
	if (opcion==1)
	{
	cout << "Escribe el nombre del archivo: ";
	getline(cin, nombre);	
	}
	else
	{
	nombre = "prueba.txt";
	}
	vector <string> linea;
	crear_archivo(nombre_acomo);
	leer(linea, nombre);
	ordenar(linea);
	cout << "\n";
	cout << "Las palabras en orden son:" << endl;
	cout << "\n";
	for (int i = 0; i < linea.size(); i++)
	{
		cout << linea[i] << endl;
	}
	cout << "\n";
	escribir_en_nuevo(nombre_acomo, linea);
	cout << "Presione ENTER para salir"<<endl;
	cin.ignore();
	cin.get();

	return 0;
}