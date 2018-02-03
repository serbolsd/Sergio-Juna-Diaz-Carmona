#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
//drill
int drill4()
{
	double n = 2, agregar = 0, suma = 0, a, b, mayor, menor, mayorhas, menorhasta, numingrsados, metro = 100, cen = .01, pie = (12 * 0.0254), pulga = 0.0254, valorcompara1, valorcompara2;
	string salir, medida1, medida2, medidmayor, medidamenor, mediameyorhasta, medidamenorhasta;
	bool vuelta = false;
	vector<double> numeros;

	do//Para comnzar el ciclo
	{
		cout << "Ingrese un numeros y su unidad de medida(m,cm,ft,in\n";
		cin >> a >> medida1;
		//por si se ingresa un valor que no es valido
		if (medida1 == "cm")
		{
			valorcompara1 = (a * cen);
		}
		else if (medida1 == "ft")
		{
			valorcompara1 = a * pie;
		}
		else if (medida1 == "in")
		{
			valorcompara1 = a * pulga;
		}
		else if (medida1 != "m")
		{
			do
			{
				cout << "medida invalida";
				cin >> medida1;
			} while (medida1 != "m" || medida1 != "cm" || medida1 != "ft" || medida1 != "in");
			if (medida1 == "cm")
			{
				valorcompara1 = (a * cen);
			}
			else if (medida1 == "ft")
			{
				valorcompara1 = a * pie;
			}
			else if (medida1 == "in")
			{
				valorcompara1 = a * pulga;
			}
			else
			{
				valorcompara1 = a;
			}
		}
		else
		{
			valorcompara1 = a;
		}
		//para tranformar en metros
		//para agregar al vector
		numeros.push_back(valorcompara1);

		cout << "ingrese otro numero\n";
		cin >> b >> medida2;

		//por si se ingresa un valor que no es valido
		if (medida2 == "cm")
		{
			valorcompara2 = (b * cen);
		}
		else if (medida2 == "ft")
		{
			valorcompara2 = b * pie;
		}
		else if (medida2 == "in")
		{
			valorcompara2 = b * pulga;
		}
		else if (medida2 != "m")
		{
			do
			{
				cout << "medida invalida";
				cin >> medida2;
			} while (medida2 != "m" || medida2 != "cm" || medida2 != "ft" || medida2 != "in");
			if (medida2 == "cm")
			{
				valorcompara2 = (b * cen);
			}
			else if (medida2 == "ft")
			{
				valorcompara2 = b * pie;
			}
			else if (medida2 == "in")
			{
				valorcompara2 = b * pulga;
			}
			else
			{
				valorcompara2 = b;
			}
		}
		else
		{
			valorcompara2 = b;
		}
		//para tranformar en metros
		//para agregar al vector
		numeros.push_back(valorcompara2);
		cout << "\n";
		cout << a << medida1 << " " << b << medida2 << "\n";
		//compara para saber si los numero son cercanos
		if ((valorcompara1 - valorcompara2) < .01 && (valorcompara1 - valorcompara2)>-.01)
		{
			cout << "Los numeros " << a << " y " << b << " son casi iguales\n";
			cout << "\n";
		}
		if (valorcompara1 < valorcompara2)// Aquie reviso cual es el mayor
		{
			menor = a;
			medidamenor = medida1;
			mayor = b;
			medidmayor = medida2;
			cout << "El numero mayor es: " << mayor << medidmayor << ", y el numero menor es: " << menor << medidamenor << "\n";
			cout << "\n";
		}
		else if (valorcompara1 == valorcompara2)// para ver si son iguales
		{
			cout << "Ambos numeros son iguales: " << a << "\n";
			cout << "\n";
		}

		else
		{
			menor = b;
			medidamenor = medida2;
			mayor = a;
			medidmayor = medida1;
			cout << "El numero mayor es: " << mayor << medidmayor << ", y el numero menor es: " << menor << medidamenor << "\n";
			cout << "\n";
		}
		if (vuelta == false)
		{
			vuelta = true;
			menorhasta = menor;
			medidamenorhasta = medidamenor;
			mayorhas = mayor;
			mediameyorhasta = medidmayor;
		}
		else
		{
			if (menor < menorhasta)
			{
				menorhasta = menor;
				medidamenorhasta = medidamenor;

			}
			if (mayor > mayorhas)
			{
				mayorhas = mayor;
				mediameyorhasta = medidmayor;
			}
		}
		suma += (valorcompara1 + valorcompara2);
		cout << "El mayor numero hasta ahora es: " << mayorhas << mediameyorhasta << "\n";
		cout << "El menor numero hasta ahora es:" << menorhasta << medidamenorhasta << "\n";
		cout << "\n";
		cout << "Infrese '|' si desea salir, de lo contrario ingrese c\n";// para saber si desea salir o no 
		cin >> salir;
		cout << "\n";
	} while (salir != "|");
	cout << "los numeros registrados convertidos en metros(ordenados de forma creciente) son\n";
	//para ordenar los numeros de menor a mayor

	sort(numeros.begin(), numeros.end());

	//para imrpimir el vector
	for (int i = 0; i<numeros.size(); i++)
	{
		cout << numeros[i] << endl;
	}
	cout << "\n";
	cout << "La suma de todos estos numeros da un total de:";
	cout << suma << "m\n";
	cout << "Preione enter para terminar";
	cin.ignore();
	cin.get();
	return 0;
}
int drill5() {
	try {
		cout << "succes" << endl;
		//keep_window_open();
		return 0;
	}
	catch (exception& e) {
		cerr << "error: " << e.what() << '\n';
		//keep_window_open();
		return 1;
	}
	catch (...) {
		cerr << "Oops: unknown exception!\n";
		//keep_window_open();
		return 2;

	}
	/*	cout<< "Success!\n"; 
	cout << "Success!\n";
	cout << "Success" << "\n";
	cout << "success" << '\n'; 
	string res = "7"; vector<string> v(10); v[5] = res; cout << "Success!\n"; 
	vector<int> v2(10); v2[5] = 7; if (v2[5] == 7) cout << "Success!\n"; 
	if (true) cout << "Success!\n"; else cout << "Fail!\n"; 
	bool c = true; if (c) cout << "Success!\n"; else cout << "Fail!\n";  
	string s = "ape"; bool c = "fool" < s; if (c) cout << "Success!\n";  
	string s = "ape"; if (s == "ape") cout << "Success!\n";  
	string s = "fool"; if (s == "fool") cout << "Success!\n";  
	string s = "ape"; if (s == "ape") cout << "Success!\n"; 
	vector<char> v(5); for (int i = 0; i < v.size(); ++i); cout << "Success!\n";  
	vector<char> v(5); for (int i = 0; i <= v.size(); ++i); cout << "Success!\n";  
	string s = "Success!\n"; for (int i = 0; i < 6; ++i) cout << s[i]; 
	if (true)  cout << "Success!\n"; else cout << "Fail!\n"; 
	int x = 2000; int c = x; if (c == 2000) cout << "Success!\n";  
	string s = "Success!\n"; for (int i = 0; i < 10; ++i) cout << s;  
	vector<int> v(5); for (int i = 0; i <= v.size(); ++i); cout << "Success!\n";  
	int i = 0; int j = 9; while (i < 10) ++j; if (j < i) cout << "Success!\n";  
	int x = 2; double d = 5 / (x-0.8888888889); if (d == (2 * x + 0.5)) cout << "Success!\n"; 
	string s = "Success!\n"; for (int i = 0; i <= 10; ++i) cout << s;  
	int i = 0; int j=9; while (i < 10) ++i; if (j < i) cout << "Success!\n";
	int x = 2; double d = 5 / (x-0.888888889); if (d = 2 * x + 0.5) cout << "Success!\n"; 
	cout << "Success!\n";*/
	cin.ignore();
	cin.get();
	cout << "\n";
	return 0;
}
int main()
{
		int elegir;
		const int n = 5;
		do
		{
			cout << "Elija el numero de lo que quiere hacer" << endl;
			cout << "1- Drill\n";
			cout << "2- drill 5";
			cout << "0- Salir\n";
			cin >> elegir;
			switch (elegir)
			{
			case 1:
				drill4();
				break;
			case 2:
				drill5();
				break;
			default:
				break;
			}
		} while (elegir != 0);
}