#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include<stdlib.h>
#include <time.h>
//#include "oraciones.h"
using namespace std;


struct oracion
{
	string sujeto;
	string adjetivo;
	string verbo;
	string advervio;
	string preposicion;
	string sustantivo;
	oracion(string su = "", string adj = "", string ver = "", string adv = "", string  pre = "", string sus = "") : sujeto(su), adjetivo(adj), verbo(ver), advervio(adv), preposicion(pre), sustantivo(sus) {}

};
ostream& operator<<(ostream& ost, oracion& ora)
{
	ost << ora.sujeto << " " << ora.adjetivo << " " << ora.verbo << " " << ora.advervio << " " << ora.preposicion << " " << ora.sustantivo << endl;
	return ost;
}

/*
enum tipo
{
sujeto=0,
adjetivo,
verbo,
advervio,
preposicion,
sustantivo,
};*/


void crear_nuevo(string n)
{
	ofstream archivo_n(n.c_str());
	archivo_n.open(n.c_str(), ios::out);
}
void agregar_nuevo(string n, vector <oracion> v)
{
	ofstream archivo_n(n.c_str());
	for (int i = 0; i < v.size(); i++)
	{
		archivo_n << v[i];
	}
}

void leer_archivo(string n, vector <string>&s, vector <string>&ad, vector <string>&ver, vector <string>&adver, vector <string>&pre, vector <string>&sus);

void hacer_oracion(vector <oracion> &v, vector <string>&s, vector <string>&ad, vector <string>&ver, vector <string>&adver, vector <string>&pre, vector <string>&sus)
{
	srand(time(NULL));
	oracion ora;
	int a, b, c, d, e, f, numa, numb, numc, numd, nume, numf;
	numa = -12 + s.size();
	numb = -12 + ad.size();
	numc = -12 + ver.size();
	numd = -12 + adver.size();
	nume = -12 + pre.size();
	numf = -12 + sus.size();
	while (v.size()<8)
	{
		a = 1 + rand() % (11 + numa);
		b = 1 + rand() % (11 + numb);
		c = 1 + rand() % (11 + numc);
		d = 1 + rand() % (11 + numd);
		e = 1 + rand() % (11 + nume);
		f = 1 + rand() % (11 + numf);
		ora.sujeto = s[a];
		ora.adjetivo = ad[b];
		ora.verbo = ver[c];
		ora.advervio = ad[d];
		ora.preposicion = pre[e];
		ora.sustantivo = sus[f];
		v.push_back(ora);
	}

}

int main()
{
	vector <string> sujetos, adjetivos, verbos, advervios, preposiciones, sustantivos;
	vector<oracion> oracion;
	string archivo = "oraciones.txt", archivo_n = "oraciones_ran.txt";
	crear_nuevo(archivo_n);
	leer_archivo(archivo, sujetos, adjetivos, verbos, advervios, preposiciones, sustantivos);
	hacer_oracion(oracion, sujetos, adjetivos, verbos, advervios, preposiciones, sustantivos);
	for (int i = 0; i < oracion.size(); i++)
	{
		//cout << oracion[i].sujeto << " " << oracion[i].adjetivo << " " << oracion[i].verbo << " " << oracion[i].advervio << " " << ooracion[i].preposicion << " " << oracion[i].sustantivo << endl;
		cout << oracion[i];
	}
	agregar_nuevo(archivo_n, oracion);
	cin.get();
	return 0;
}



void leer_archivo(string n, vector <string>&s, vector <string>&ad, vector <string>&ver, vector <string>&adver, vector <string>&pre, vector <string>&sus)
{
	string *tipo = new string(), *palabra = new string("nada");
	char registro[256];
	ifstream archivo(n.c_str());
	while (*palabra != "")
	{
		archivo.getline(registro, 256, '\n');
		*palabra = registro;
		if (*palabra == "Sujeto")
		{
			*tipo = "Sujeto";
		}
		else if (*palabra == "Adjetivo")
		{
			*tipo = "Adjetivo";
		}
		else if (*palabra == "Verbo")
		{
			*tipo = "Verbos";
		}
		else if (*palabra == "Advervio")
		{
			*tipo = "Advervio";
		}
		else if (*palabra == "Preposicion")
		{
			*tipo = "Preposicion";
		}
		else if (*palabra == "Sustantivo")
		{
			*tipo = "Sustantivo";
		}

		if (*tipo == "Sujeto")
		{
			s.push_back(*palabra);
		}
		else if (*tipo == "Adjetivo")
		{
			ad.push_back(*palabra);
		}
		else if (*tipo == "Verbos")
		{
			ver.push_back(*palabra);
		}
		else if (*tipo == "Advervio")
		{
			adver.push_back(*palabra);
		}
		else if (*tipo == "Preposicion")
		{
			pre.push_back(*palabra);
		}
		else if (*tipo == "Sustantivo")
		{
			sus.push_back(*palabra);
		}
	}

	delete tipo, palabra, registro;

}
