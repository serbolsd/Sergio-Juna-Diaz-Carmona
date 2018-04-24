#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include<sstream>

using namespace std;

void agregar_nuevo(string n, string *total, int nt)
{
	ofstream *archivo_n=new ofstream(n.c_str(), ios::app);
	for (int i = 0; i < nt; i++)
	{
		if (nt == 1)
		{
			*archivo_n << "Resultado= ";
		}
		*archivo_n << total[i];
	}
	*archivo_n << "\n";
	if (nt == 1)
	{
		*archivo_n << "\n";
	}
	delete (archivo_n);
}

void agregar_nuevo(vector<string> total, string n)
{
	ofstream *archivo_n = new ofstream(n.c_str(), ios::app);
	for (int i = 0; i < total.size(); i++)
	{
		if (total.size() == 1)
		{
			*archivo_n << "Resultado= ";
		}
		*archivo_n << total[i];
	}
	*archivo_n << "\n";
	if (total.size() == 1)
	{
		*archivo_n << "\n";
	}
	delete (archivo_n);
}

void gerarquia_parentesis(vector <string> &total,string n,int nt=-1)
{
	while (nt != 1)
	{
		nt = total.size();
		int i = 0;
		int nt = (total.size());
		int par1 = 0, par2, pare = par1;
		par2 = (total.size());
		string contenido;
		while (i < nt)
		{
			if (total[i] == "(")
			{
				par1 = i;
			}
			if (total[i] == ")")
			{
				par2 = i;
				pare = par1 + 1;
			}
			i++;
		}
		i = pare;
		while (i < par2)
		{
			if (total[i] == "p" || total[i] == "P")
			{
				double nume, nume2, pot, resultado;
				int p = 1;
				const char *m = (total[i - 1]).c_str();
				nume = atof(m);
				m = (total[i + 1]).c_str();
				pot = atof(m);
				nume2 = nume;
				while (p<pot)
				{
					nume = nume * nume2;
					p++;
				}
				resultado = nume;
				//acomodar(i, ope, num, resultado);
				char num[50];
				snprintf(num, 50, "%f", resultado);
				nt = total.size() - 1;
				total[i - 1] = num;
				for (int j = i; j < nt; j++)
				{
					if ((j + 1)<total.size())
					{
						total[j] = total[j + 1];
					}
				}
				for (int j = i; j < nt; j++)
				{
					if ((j + 1)<total.size())
					{
						total[j] = total[j + 1];
					}
				}
				total.pop_back();
				total.pop_back();
				agregar_nuevo(total, n);
				for (int im = 0; im < total.size(); im++)
				{
					cout << total[im];
				}
				cout << "\n";
				par2 -= 2;

			}
			i++;
		}
		i = pare;
		while (i < par2)
		{
			if (total[i] == "r" || total[i] == "R")
			{
				double nume, ra, resultado;
				const char *m = (total[i - 1]).c_str();
				nume = atof(m);
				m = (total[i + 1]).c_str();
				ra = atof(m);
				resultado = pow(nume, (1 / ra));
				char num[50];
				snprintf(num, 50, "%f", resultado);
				nt = total.size() - 1;
				total[i - 1] = num;
				for (int j = i; j < nt; j++)
				{
					if ((j + 1)<total.size())
					{
						total[j] = total[j + 1];
					}
				}
				for (int j = i; j < nt; j++)
				{
					if ((j + 1)<total.size())
					{
						total[j] = total[j + 1];
					}
				}
				total.pop_back();
				total.pop_back();
				
				agregar_nuevo(total, n);
				for (int im = 0; im < total.size(); im++)
				{
					cout << total[im];
				}
				cout << "\n";
				par2 -= 2;
				
			}
			i++;
		}
		i = pare;
		while (i < par2)
		{
			if (total[i] == "l" || total[i] == "L")
			{
				double nume, nume2, resultado;
				//num.size()>1 &&
				if (total[i-1]=="+"|| total[i - 1] == "-" || total[i - 1] == "/" || total[i - 1] == "*" || total[i - 1] == "P" || total[i - 1] == "p" || total[i - 1] == "S" || total[i - 1] == "s" || total[i - 1] == "R" || total[i - 1] == "r" || total[i - 1] == "L" || total[i - 1] == "l" || total[i - 1] == "t" || total[i - 1] == "T" || total[i - 1] == "C" || total[i - 1] == "c")
				{
					const char *m ;
					m = (total[i + 1]).c_str();
					nume = atof(m);
					resultado = log(nume) / log(2.718281828);
					char num[50];
					snprintf(num, 50, "%f", resultado);
					nt = total.size() - 1;
					total[i - 1] = num;
					for (int j = i; j < nt; j++)
					{
						if ((j + 1)<total.size())
						{
							total[j] = total[j + 1];
						}
					}
					total.pop_back();
					
					agregar_nuevo(total, n);
					for (int im = 0; im < total.size(); im++)
					{
						cout << total[im];
					}
					cout << "\n";
					par2 -= 2;
				}
				else
				{
					const char *m = (total[i - 1]).c_str();
					nume = atof(m);
					m = (total[i + 1]).c_str();
					nume2 = atof(m);
					nume2 = log(nume2) / log(2.718281828);
					resultado = nume * nume2;
					char num[50];
					snprintf(num, 50, "%f", resultado);
					nt = total.size() - 1;
					total[i - 1] = num;
					for (int j = i; j < nt; j++)
					{
						if ((j + 1)<total.size())
						{
							total[j] = total[j + 1];
						}
					}
					for (int j = i; j < nt; j++)
					{
						if ((j + 1)<total.size())
						{
							total[j] = total[j + 1];
						}
					}
					total.pop_back();
					total.pop_back();
					
					agregar_nuevo(total, n);
					for (int im = 0; im < total.size(); im++)
					{
						cout << total[im];
					}
					cout << "\n";
					par2 -= 2;
				}
			}
			i++;
		}
		i = pare;
		while (i < par2)
		{
			if (total[i] == "S" || total[i] == "s")
			{
				double nume, nume2, resultado;
				const char *m = (total[i - 1]).c_str();
				nume = atof(m);
				m = (total[i + 1]).c_str();
				nume2 = atof(m);
				resultado = nume * (tan(nume2*3.14159 / 180));
				char num[50];
				snprintf(num, 50, "%f", resultado);
				string to = m;
				nt = total.size() - 1;
				total[i - 1] = num;
				for (int j = i; j < nt; j++)
				{
					if ((j + 1)<total.size())
					{
						total[j] = total[j + 1];
					}
				}
				for (int j = i; j < nt; j++)
				{
					if ((j + 1)<total.size())
					{
						total[j] = total[j + 1];
					}
				}
				total.pop_back();
				total.pop_back();
				
				agregar_nuevo(total, n);
				for (int im = 0; im < total.size(); im++)
				{
					cout << total[im];
				}
				cout << "\n";
				par2 -= 2;
			}
			i++;
		}
		i = pare;
		while (i < par2)
		{
			if (total[i] == "C" || total[i] == "c")
			{
				double nume, nume2, resultado;
				const char *m = (total[i - 1]).c_str();
				nume = atof(m);
				m = (total[i + 1]).c_str();
				nume2 = atof(m);
				resultado = nume * (tan(nume2*3.14159 / 180));
				char num[50];
				snprintf(num, 50, "%f", resultado);
				string to = m;
				nt = total.size() - 1;
				total[i - 1] = num;
				for (int j = i; j < nt; j++)
				{
					if ((j + 1)<total.size())
					{
						total[j] = total[j + 1];
					}
				}
				for (int j = i; j < nt; j++)
				{
					if ((j + 1)<total.size())
					{
						total[j] = total[j + 1];
					}
				}
				total.pop_back();
				total.pop_back();
				
				agregar_nuevo(total, n);
				for (int im = 0; im < total.size(); im++)
				{
					cout << total[im];
				}
				cout << "\n";
				par2 -= 2;
			}
			i++;
		}
		i = pare;
		while (i < par2)
		{
			if (total[i] == "T" || total[i] == "t")
			{
				double nume, nume2, resultado;
				const char *m = (total[i - 1]).c_str();
				nume = atof(m);
				m = (total[i + 1]).c_str();
				nume2 = atof(m);
				resultado = nume * (tan(nume2*3.14159 / 180));
				char num[50];
				snprintf(num, 50, "%f", resultado);
				string to = m;
				nt = total.size() - 1;
				total[i - 1] = num;
				for (int j = i; j < nt; j++)
				{
					if ((j + 1)<total.size())
					{
						total[j] = total[j + 1];
					}
				}
				for (int j = i; j < nt; j++)
				{
					if ((j + 1)<total.size())
					{
						total[j] = total[j + 1];
					}
				}
				total.pop_back();
				total.pop_back();
				
				agregar_nuevo(total, n);
				for (int im = 0; im < total.size(); im++)
				{
					cout << total[im];
				}
				cout << "\n";
				par2 -= 2;

			}
			i++;
		}
		i = pare;
		while (i < par2)
		{
			if (total[i] == "*")
			{
				double nume, nume2, resultado;
				const char *m = (total[i - 1]).c_str();
				nume = atof(m);
				m = (total[i + 1]).c_str();
				nume2 = atof(m);
				resultado = nume * nume2;
				char num[50];
				snprintf(num, 50, "%f", resultado);
				string to = m;
				nt = total.size() - 1;
				total[i - 1] = num;
				for (int j = i; j < nt; j++)
				{
					if ((j + 1)<total.size())
					{
						total[j] = total[j + 1];
					}
				}
				for (int j = i; j < nt; j++)
				{
					if ((j + 1)<total.size())
					{
						total[j] = total[j + 1];
					}
				}
				total.pop_back();
				total.pop_back();
				agregar_nuevo(total, n);
				for (int im = 0; im < total.size(); im++)
				{
					cout << total[im];
				}
				cout << "\n";
				par2 -= 2;
			}
			i++;
		}
		i = pare;
		while (i < par2)
		{
			if (total[i] == "/")
			{
				double nume, nume2, resultado;
				const char *m = (total[i - 1]).c_str();
				nume = atof(m);
				m = (total[i + 1]).c_str();
				nume2 = atof(m);
				resultado = nume / nume2;
				char num[50];
				snprintf(num, 50, "%f", resultado);
				string to = m;
				nt = total.size() - 1;
				total[i - 1] = num;
				for (int j = i; j < nt; j++)
				{
					if ((j + 1)<total.size())
					{
						total[j] = total[j + 1];
					}
				}
				for (int j = i; j < nt; j++)
				{
					if ((j + 1)<total.size())
					{
						total[j] = total[j + 1];
					}
				}
				total.pop_back();
				total.pop_back();
				agregar_nuevo(total, n);
				for (int im = 0; im < total.size(); im++)
				{
					cout << total[im];
				}
				cout << "\n";
				par2 -= 2;
			}
			i++;
		}
		i = pare;
		while (i < par2)
		{
			if (total[i] == "+")
			{
				double nume, nume2, resultado;
				const char *m = (total[i - 1]).c_str();
				nume = atof(m);
				m = (total[i + 1]).c_str();
				nume2 = atof(m);
				resultado = nume + nume2;
				char num[50];
				snprintf(num, 50, "%f", resultado);
				string to = m;
				nt = total.size() - 1;
				total[i - 1] = num;
				for (int j = i; j < nt; j++)
				{
					if ((j+1)<total.size())
					{
					total[j] = total[j + 1];
					}
				}
				for (int j = i; j < nt; j++)
				{
					if ((j + 1)<total.size())
					{
						total[j] = total[j + 1];
					}
				}
				total.pop_back();
				total.pop_back();
				agregar_nuevo(total, n);
				for (int im = 0; im < total.size(); im++)
				{
					cout << total[im];
				}
				cout << "\n";
				par2 -= 2;
			}
			i++;
		}
		i = pare;
		while (i < par2)
		{
			if (total[i] == "-")
			{
				double nume, nume2, resultado;
				const char *m = (total[i - 1]).c_str();
				nume = atof(m);
				m = (total[i + 1]).c_str();
				nume2 = atof(m);
				resultado = nume - nume2;
				char num[50];
				snprintf(num, 50, "%f", resultado);
				string to = m;
				nt = total.size() - 1;
				total[i - 1] = num;
				for (int j = i; j < nt; j++)
				{
					if ((j + 1)<total.size())
					{
						total[j] = total[j + 1];
					}
				}
				for (int j = i; j < nt; j++)
				{
					if ((j + 1)<total.size())
					{
						total[j] = total[j + 1];
					}
				}
				total.pop_back();
				total.pop_back();

				agregar_nuevo(total, n);
				for (int im = 0; im < total.size(); im++)
				{
					cout << total[im];
				}
				cout << "\n";
				par2 -= 2;
			}
			i++;
		}
		i = par1;
		if ((i+2)==par2)
		{
			for (int j = i; j < total.size(); j++)
			{
				if ((j + 1)<total.size())
				{
					total[j] = total[j + 1];
				}
			}
			for (int j = i+1; j < total.size(); j++)
			{
				if ((j + 1)<total.size())
				{
					total[j] = total[j + 1];
				}
			}
			total.pop_back();
			total.pop_back();
			if (total[i - 1] == "+" || total[i - 1] == "-" || total[i - 1] == "/" || total[i - 1] == "*" || total[i - 1] == "P" || total[i - 1] == "p" || total[i - 1] == "S" || total[i - 1] == "s" || total[i - 1] == "R" || total[i - 1] == "r" || total[i - 1] == "L" || total[i - 1] == "l" || total[i - 1] == "t" || total[i - 1] == "T" || total[i - 1] == "C" || total[i - 1] == "c")
			{

			}
			else
			{
				double nume, nume2, resultado;
				const char *m = (total[i - 1]).c_str();
				nume = atof(m);
				m = (total[i]).c_str();
				nume2 = atof(m);
				resultado = nume * nume2;
				char num[50];
				snprintf(num, 50, "%f", resultado);
				string to = m;
				total[i - 1] = num;
				for (int j = i; j < (total.size() - 1); j++)
				{
					total[j] = total[j + 1];
				}
				total.pop_back();

				agregar_nuevo(total, n);
				for (int im = 0; im < total.size(); im++)
				{
					cout << total[im];
				}
				cout << "\n";
				par2 -= 2;
			}
		}
			if (nt==1)
			{
				for (int im = 0; im < total.size(); im++)
				{
					cout <<"Resultado="<< total[im];
				}
				cout << "\n";
				agregar_nuevo(total, n);
			}
			
	}
	
}

void leer_chido(vector <char>& ope, vector <double>& num,string *&total)
{
	int nt = ope.size() + num.size();
	for (int i = 0; i < nt; i++)
	{
		total[i] = '\0';
	}
	int ver = 0;
	int i = 0;
	int j = i;
	int n = i;
	while (i < nt - 1)
	{
		while (ver < ope.size())
		{
			if (ope[j] == '(')
			{
				total[i] = ope[j];
				j++;
				i++;
			}
			ver++;
		}
		ver = 0;
		char m[50];
		snprintf(m, 50, "%f", num[n]);
		string to = m;
		total[i] = to;
		n++;
		i++;
		while (ver < ope.size())
		{
			if (i >= nt)
			{
				break;
			}
			if (ope[j] == ')')
			{

				total[i] = ope[j];
				j++;
				i++;
			}
			ver++;
		}
		ver = 0;
		if (i < nt - 1)
		{
			total[i] = ope[j];
			j++;
			i++;
		}

	}
}

void acomodar_parentesis(vector <char>& ope, vector <double>& num)
{
	string nuevoar = "respuestas.txt";
	int nt = ope.size() + num.size();
	string *totala = new string[nt];
	leer_chido(ope, num, totala);
	vector <string> total;
	/*for (int i = 0; i < nt; i++)
	{
		total[i] = '\0';
	}*/
	int ver = 0;
	int i = 0;
	int j = i;
	int n = i;
	bool oper = false;
	while (i < nt - 1)
	{
		if ((totala[i - 1] == "+" || totala[i - 1] == "-" || totala[i - 1] == "/" || totala[i - 1] == "*" || totala[i - 1] == "P" || totala[i - 1] == "p" || totala[i - 1] == "S" || totala[i - 1] == "s" || totala[i - 1] == "R" || totala[i - 1] == "r" || totala[i - 1] == "L" || totala[i - 1] == "l" || totala[i - 1] == "t" || totala[i - 1] == "T" || totala[i - 1] == "C" || totala[i - 1] == "c"))
		{

		}
		else if (ope[j] == '(')
		{

			ver = 0;
			char m[50];
			snprintf(m, 50, "%f", num[n]);
			string to = m;
			total.push_back(to);
			n++;
			i++;
		}
		oper = false;
		if (ope[j] == '(')
		{
			stringstream aa;
			char a=(ope[j]);
			string m;
			aa << a;
			aa >> m;
			total.push_back(m);
			j++;
			i++;
		}
		char m[50];
		snprintf(m, 50, "%f", num[n]);
		string to = m;
		total.push_back(to);
		n++;
		i++;
		if (i >= nt)
		{
			break;
		}
		if (j<ope.size())
		{

			if (ope[j] == ')')
			{

				stringstream aa;
				char a = (ope[j]);
				string m;
				aa << a;
				aa >> m;
				total.push_back(m);
				j++;
				i++;
			}
		}
		
		if (i < nt - 1)
		{
			if (ope[j]!='('|| ope[j] != ')')
			{

				stringstream aa;
				char a = (ope[j]);
				string m;
				aa << a;
				aa >> m;
				total.push_back(m);
				j++;
				i++;
				oper = true;
			}
		}

	}
	/*while (t<nt)
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
		}
	}
	int t2 = 1;
	int o = 0;
	while (t2<nt)
	{
		char m[50];
		snprintf(m,50, "%0", ope[o]);
		string to = m;
		total[t2] = ope[o];
		t2 += 2;
		o += 1;
	}*/
	//total.pop_back();
	for (size_t a = 0; a < nt; a++)
	{
		if (nt == 1)
		{
			cout << "Resultado= ";
		}
		cout << total[a] << " ";
	}
	agregar_nuevo(total, nuevoar);
	cout << "\n";
	gerarquia_parentesis(total, nuevoar);
	//operaciones_perentesis(total, nt);
	delete[]totala;
}


void crear_archivo(string archi)
{
	ofstream archivo_n(archi.c_str());
	archivo_n.open(archi.c_str(), ios::out);
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

void gerarquia_paren(vector <char> operaciones, vector <double> numero)
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
			if (ope[i] == 'p' || ope[i] == 'P')
			{
				double nume, nume2, pot, resultado;
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
				resultado = pow(nume, (1 / ra));
				acomodar(i, ope, num, resultado);
			}
			i++;
		}
		i = 0;
		while (i < ope.size())
		{
			if (ope[i] == 'l' || ope[i] == 'L')
			{
				double nume, nume2, resultado;
				//num.size()>1 && 
				if (ope.size() == (num.size()))
				{
					nume = num[i];
					resultado = log(nume) / log(2.718281828);
				}
				else
				{
					nume = num[i];
					nume2 = num[i + 1];
					nume2 = log(nume2) / log(2.718281828);
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
				double nume, nume2, resultado;
				nume = num[i];
				nume2 = num[i + 1];
				nume2 = nume2 * 3.14159 / 180;
				resultado = nume * (sin(nume2));
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
			if (ope[i] == '-')
			{
				double resultado = num[i] - num[i + 1];
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
		bool parentesis = false;
		bool anteregistro = false;
		int j = 0;
		registro = 'A';
		int pa = -10;
		while (pa!=0)
		{
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
				else if (registro == '(')
				{
					if (pa==-10)
					{
						pa = 0;
					}
					parentesis = true;
					if (pa ==0 && numeros=='\0')
					{
						operaciones.push_back(registro);
						
					}
					else
					{
						operaciones.push_back(registro);
						
						if (anteregistro)
						{

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
						pa += 1;
				}
				else if (registro == ')')
				{
					pa -= 1;
					operaciones.push_back(registro);
					
					num1 = atoi(numeros);
					numero.push_back(num1);
					
					if (pa==0)
					{
						i++;
						registro = contenido[i];
					}
				}
				else if (registro == '\n' || registro == '\0')
				{
					num1 = atoi(numeros);
					numero.push_back(num1);
				}
				else if (registro == '+')
				{
					operaciones.push_back(registro);
					num1 = atoi(numeros);
					numero.push_back(num1);
					
					for (int a = 0; a < 9; a++)
					{
						numeros[a] = '\0';
					}
					j = 0;
					anteregistro = true;
				}
				else if (registro == '*')
				{
					operaciones.push_back(registro);
					num1 = atoi(numeros);
					numero.push_back(num1);
					
					for (int a = 0; a < 9; a++)
					{
						numeros[a] = '\0';
					}
					j = 0;
					anteregistro = true;
				}
				else if (registro == '-')
				{
					if (numero.size()>0)
					{
						if (operaciones.size() == numero.size())
						{
							numeros[j] = registro;
							j++;
						}
						else if (operaciones[(operaciones.size() - 1)] == '(' || operaciones[(operaciones.size() - 1)] == ')')
						{
							numeros[j] = registro;
							j++;
						}
					}
					else if(operaciones.size() == numero.size())
					{
						operaciones.push_back(registro);
						num1 = atoi(numeros);
						numero.push_back(num1);


						for (int a = 0; a < 9; a++)
						{
							numeros[a] = '\0';
						}
						j = 0;
						anteregistro = true;
					}
					else if (operaciones[(operaciones.size()-1)]=='(' || operaciones[(operaciones.size() - 1)] == ')')
					{
						numeros[j] = registro;
						j++;
					}
					else
					{
						operaciones.push_back(registro);
						num1 = atoi(numeros);
						numero.push_back(num1);
						
						
						for (int a = 0; a < 9; a++)
						{
							numeros[a] = '\0';
						}
						j = 0;
						anteregistro = true;
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
					anteregistro = true;
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
					anteregistro = true;
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
					anteregistro = true;
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
					anteregistro = true;
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
					anteregistro = true;
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
					anteregistro = true;
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
					anteregistro = true;
				}
				else if (registro < 65)
				{
					numeros[j] = registro;
					if (numeros[j]== '0' && operacion=="divi")
					{
						se_puede = false;
						operacion = "nada";
					}
					else
					{
						operacion = "nada";
					}
					j++;
					anteregistro = false;
				}
				i++;
			}
			pa = 0;
		}
		
		if (numero.size() == 1)
		{
			cout << numero[0] << "\n";
		}
		else if (parentesis)
		{
			for (int i = 0; i < operaciones.size(); i++)
			{
				cout << operaciones[i];
			}
			for (int i = 0; i < numero.size(); i++)
			{
				cout << numero[i];
			}
			cout << "\n";
			acomodar_parentesis(operaciones, numero);
		}
		else if (se_puede)
		{
			imprimir(operaciones, numero);
			gerarquia_oper(operaciones, numero);
		}
		else
		{
			imprimir(operaciones, numero);
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

