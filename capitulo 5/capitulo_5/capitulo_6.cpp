#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

//Estas dos son para producir numeros aleatorios, para el ejercicio 12
#include <stdlib.h>
#include <time.h>

using namespace std;
//Esto es parte del ejercicio 2
double ctok(double c)    // converts Celsius to Kelvin 
{
	//6. Se le esta dando un valor entero a algo que tiene decimales
	double k = c + 273.15;
	//7. no se retonrna a ninugno numero. 8. tampoco tiene punto y coma
	return k;
}
int ejercicio2()
{
	double c = 0;           // declare input variable          
	//1. no se ha declarado d
	double d;
	cin >> d;                   // retrieve temperature to input variable  
	//2. c esta entre comillas. 3.ademas de que se pide que se ingrese d
	c = d;
	double k = ctok(c);     // convert temperature 
	//4. La c de cout esta en mayuscula
	cout << k << '/n';         // print out temperature

	cin.ignore();
	cin.get();
	//5. Falta un return
	return 0;
}

int ejercicio3()
{
	double c = 0;           // declare input variable          
							//1. no se ha declarado d
	double d;
	cin >> d;                   // retrieve temperature to input variable  
								//2. c esta entre comillas. 3.ademas de que se pide que se ingrese d
	if (d>-273.15)
	{
		c = d;
		double k = ctok(c);     // convert temperature 
								//4. La c de cout esta en mayuscula
		cout << k << '/n';         // print out temperature
	}
	else
	{
		cout << "No se puede calcular una temperatura menor al zero absoluto\n";
	}


	cin.ignore();
	cin.get();
	//5. Falta un return
	return 0;
}

//Esto es paerte del ejercicio 4
double ctok2(double c)    // converts Celsius to Kelvin 
{

	if (c>-273.15)
	{
		//6. Se le esta dando un valor entero a algo que tiene decimales
		double k = c + 273.15;
		//7. no se retonrna a ninugno numero. 8. tampoco tiene punto y coma
		cout << k << '/n';         // print out temperature
		return 0;
	}
	else
	{
		cout << "No se puede calcular una temperatura menor al zero absoluto\n";
		return 0;
	}

}
int ejercicio4()
{
	double c = 0;           // declare input variable          
							//1. no se ha declarado d
	double d;
	cin >> d;                   // retrieve temperature to input variable  
								//2. c esta entre comillas. 3.ademas de que se pide que se ingrese d
	c = d;
	double k = ctok2(c);     // convert temperature 
							 //4. La c de cout esta en mayuscula



	cin.ignore();
	cin.get();
	//5. Falta un return
	return 0;
}

int ejercicio7()
{
	int a, b, c;
	double operacion, resultado1, resultado2, cuadrado, raiz;
	cout << "Ingrese los tres numeros de su funcion cuadratica\n";
	cin >> a >> b >> c;
	cuadrado = pow(b, 2);
	raiz = cuadrado - (4 * a*c);
	if (raiz >= 0)
	{
		raiz = sqrt(raiz);
		operacion = -b;
		resultado1 = (operacion + raiz) / (2 * a);
		resultado2 = (operacion - raiz) / (2 * a);
		cout << "\n";
		cout << "El resultado es:\n";
		cout << "X1 = " << resultado1 << "\n";
		cout << "X2 = " << resultado2 << "\n";
	}
	else
	{
		cout << "Hijoles chavo, eso no se puede, no es una raiz real\n";
	}

	cin.ignore();
	cin.get();
	return 0;
}

int ejercicio12()
{
	vector <int> numeros;
	bool incompleto = true;
	int a, ain, b, bin, c, cinp, d, din, y = 10, revisar;
	cout << "Espere un momento\n";
	while (numeros.size() < 4)
	{
		//como el random es del 1 al 10, esto evita que aparesca el 10, asi solo llega al 9
		while (y == 10)
		{
			//Para que no sea la misma serie de numeros siempre
			srand(time(NULL));
			//Para producier un numero aleatorio del 0 al 10
			y = rand() % 11;
			for (int i = 0; i < numeros.size(); i++)
			{
				revisar = numeros[i];
				if (revisar == y)
				{
					y = 10;
				}
			}
		}

		numeros.push_back(y);
		y = 10;
	}
	a = numeros[0];
	b = numeros[1];
	c = numeros[2];
	d = numeros[3];
	cout << "Los numeros tiene que estar en la posicion correcar\n";
	cout << "Si un numero, esta en la posicion correcta se le acisara con 'toro'\n";
	cout << "Si el numero esta en dentro de los que se quiere adivinar per no en la posicion correcta, se le avisara con 'vaca'\n";

	while (incompleto)
	{
		int toro = 0, vaca = 0;
		cout << "Ingrese cuatro numeros separados con espacio para intentar adivinar\n";
		cin >> ain >> bin >> cinp >> din;
		//revisar el primer numero
		if (ain == a)
		{
			toro += 1;
		}
		else
		{
			for (int i = 0; i < numeros.size(); i++)
			{
				revisar = numeros[i];
				if (ain == revisar)
				{
					vaca += 1;
				}
			}
		}
		//revisar el segundo numero
		if (bin == b)
		{
			toro += 1;
		}
		else
		{
			for (int i = 0; i < numeros.size(); i++)
			{
				revisar = numeros[i];
				if (bin == revisar)
				{
					vaca += 1;
				}
			}
		}
		//revisar el tercer numero
		if (cinp == c)
		{
			toro += 1;
		}
		else
		{
			for (int i = 0; i < numeros.size(); i++)
			{
				revisar = numeros[i];
				if (cinp == revisar)
				{
					vaca += 1;
				}
			}
		}
		//revisar el cuarto numero
		if (din == d)
		{
			toro += 1;
		}
		else
		{
			for (int i = 0; i < numeros.size(); i++)
			{
				revisar = numeros[i];
				if (din == revisar)
				{
					vaca += 1;
				}
			}
		}

		if (toro == 4)
		{
			incompleto = false;
		}
		else
		{
			cout << "Hay " << toro << " toro/s y " << vaca << " vaca/s\n";
		}
		cout << "\n";
	}

	for (int i = 0; i < numeros.size(); i++)
	{
		cout << numeros[i];
	}
	cout << " LO HAS CONSEGUIDO!!\n";
	cin.ignore();
	cin.get();
	return 0;
}

int drill()
{
	try {
		cout << "succes" << endl;
		//keep_window_open();
		cout << "Success!\n";
		cout << "Success!\n";
		cout << "Success" << "\n";
		cout << "success" << '\n';
		string res = "7"; vector<string> v(10); v[5] = res; cout << "Success!\n";
		vector<int> v2(10); v2[5] = 7; if (v2[5] == 7) cout << "Success!\n";
		if (true) cout << "Success!\n"; else cout << "Fail!\n";
		bool c = true; if (c) cout << "Success!\n"; else cout << "Fail!\n";
		string s = "ape"; bool c2 = true; if (c) cout << "Success!\n";
		string s2 = "ape"; if (s2 == "ape") cout << "Success!\n";
		string s3 = "fool"; if (s3 == "fool") cout << "Success!\n";
		string s4 = "ape"; if (s4 == "ape") cout << "Success!\n";
		vector<int> v3(5); for (int i = 0; i < v3.size(); ++i) cout << "Success!\n";
		vector<char> v4(5); for (int i = 0; i <= v4.size(); ++i); cout << "Success!\n";
		string s5 = "Success!\n"; for (int i = 0; i < 6; ++i) cout << s5;
		if (true)  cout << "Success!\n";else cout << "Fail!\n";
		int x = 2000; int c3 = x; if (c3 == 2000) cout << "Success!\n";
		string s6 = "Success!\n"; for (int i = 0; i < 10; ++i) cout << s6;
		vector<int> v5(5); for (int i = 0; i <= v5.size(); ++i); cout << "Success!\n";
		int i = 0; int j = 9; while (i < 10) ++j; if (j < i) cout << "Success!\n";
		int x2 = 2; double d = 5 / (x2 - 0.8888888889); if (d == (2 * x + 0.5)) cout << "Success!\n";
		string s7 = "Success!\n"; for (int i = 0; i <= 10; ++i) cout << s7;
		int i2 = 0; int j2 = 9; while (i2 < 10) ++i2; if (j2< i2) cout << "Success!\n";
		int x3 = 2; double d2 = 5 / (x - 0.888888889); if (d2 = 2 * x3 + 0.5) cout << "Success!\n";
		cout << "Success!\n";
		cin.ignore();
		cin.get();
		cout << "\n";
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

	return 0;
}

int main()
{

	int elegir;
	do
	{
		cout << "Elija el ejercicio del capitulo 5 que quiere ver\n";
		cout << "1- Drill\n";
		cout << "2- Ejercicio 2\n";
		cout << "3- Ejercicio 3\n";
		cout << "4- Ejercicio 4\n";
		cout << "5- Ejercicio 7\n";
		cout << "6- Ejercicio 12\n";
		cin >> elegir;
		switch (elegir)
		{
		case 0:
			break;
		case 1:
			drill();
			break;
		case 2:
			ejercicio2();
			break;
		case 3:
			ejercicio3();
			break;
		case 4:
			ejercicio4();
			break;
		case 5:
			ejercicio7();
			break;
		case 6:
			ejercicio12();
			break;
		default:
			break;
		}
		cout << "\n";
		cout << "Presione Enter para continuar\n\n";

	} while (elegir != 0);


	cin.get();
	return 0;
}