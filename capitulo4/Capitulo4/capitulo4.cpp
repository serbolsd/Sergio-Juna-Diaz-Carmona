#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <string> nombres;
vector <int> puntuajes;
string noname = "No name";
int puntuaje0 = 0;


int registrar()
{


	int a, b;
	string primero, segundo, buscador;
	bool esta1 = false, esta2 = false;
	cout << "Escribas dos nonbre y su puntuajes al lado de ellos\n";
	cout << "Ejemplo: joe 17 barbara 22\n";
	cin >> primero >> a >> segundo >> b;

	for (int i = 0; i < nombres.size(); ++i)
	{
		buscador = nombres[i];
		if (buscador == primero)
		{
			esta1 = true;
		}
	}
	if (esta1)
	{
		cout << "\n";
		cout << "El nombre: '" << primero << "' ya esta registrado\nNo se puede ingresas 2 veces el mismo nombre\n";
		cout << "\n";
	}
	else
	{
		nombres.push_back(primero);
		puntuajes.push_back(a);
	}

	for (int i = 0; i < nombres.size(); ++i)
	{
		buscador = nombres[i];
		if (buscador == segundo)
		{
			esta2 = true;
		}
	}
	if (esta2)
	{
		cout << "\n";
		cout << "El nombre: '" << segundo << "' ya esta registrado\nNo se puede ingresas 2 veces el mismo nombre\n";
		cout << "\n";
	}
	else
	{
		nombres.push_back(segundo);
		puntuajes.push_back(b);
	}
	cout << "\n";
	cout << "El registro hasta ahora es:\n";
	cout << "\n";
	nombres.push_back("No name");
	puntuajes.push_back(0);
	for (int i = 0; i < nombres.size(); i++)
	{
		cout << nombres[i] << " " << puntuajes[i] << "\n";
	}

	cout << "\n";
	cout << "Presione Enter para continuar\n";
	cout << "\n";
	cin.ignore();
	return 0;
}
int buscarnombres()
{
	string buscador, nombre;
	bool esta = true;
	cout << "Ingrese el nombre de la persona de la cual desea saber el puntuaje\n";
	cin >> buscador;
	cout << "\n";
	for (int i = 0; i < nombres.size(); i++)
	{
		nombre = nombres[i];
		if (nombre == buscador)
		{
			cout << "El puntuaje de '" << buscador << "' es de: " << puntuajes[i] << "\n";
			esta = false;
		}

	}

	if (esta)
	{
		cout << "El nombre que busca no se encutra\n";
	}

	cout << "\n";
	cout << "Presione Enter para continuar\n";
	cout << "\n";
	cin.ignore();
	return 0;
}
int buscarpuntuajes()
{
	int buscador, puntos;
	bool esta = true;
	cout << "Ingrese el puntuaje que desea revisar\n";
	cin >> buscador;
	cout << "\n";
	cout << "El puntuaje corresponde a:\n";
	cout << "\n";
	for (int i = 0; i < puntuajes.size(); i++)
	{
		puntos = puntuajes[i];
		if (puntos == buscador)
		{
			cout << nombres[i] << "\n";
			esta = false;
		}

	}

	if (esta)
	{
		cout << "No existe nadie con ese puntuaje\n";
	}

	cout << "\n";
	cout << "Presione Enter para continuar\n";
	cout << "\n";
	cin.ignore();
	return 0;
}
int ejercicio192021()
{
	bool primeravuelta = true;
	int elegir;
	do
	{

		cout << "Elija la opcion que desee\n";
		cout << "1- Registrar\n";
		cout << "2- Buscar puntuacion\n";
		cout << "3- Buscar persona de puntuaje\n";
		cout << "0- salir\n";
		cin >> elegir;
		cout << "\n";
		switch (elegir)
		{
		case 1:
			if (primeravuelta)
			{
				primeravuelta = false;
			}
			else
			{
				nombres.pop_back();
				puntuajes.pop_back();
			}
			registrar();
			break;
		case 2:
			buscarnombres();
			break;
		case 3:
			buscarpuntuajes();
			break;
		case 0:
			break;
		default:
			cout << "Hijoles, eso no es valido\n\n";
			break;
		}
		cout << "\n";
		cin.ignore();
	} while (elegir != 0);

	cout << "Presione ENTER para continuar";
	cin.get();
	return 0;
}

int ejercicio3() 
{
	vector <double> distancias;
	double distancia1, distancia2, menos, mayor, suma, media;
	cout << "ingrese las dostancias separadas con espacio\n";
	cin >> distancia1>> distancia2;
	cout << "\n";
	if (distancia1 < distancia2)
	{
		menos = distancia1;
		mayor = distancia2;
	}
	else
	{
		menos = distancia2;
		mayor = distancia1;
	}
	suma = distancia1 + distancia2;
	media = suma / 2;
	cout << "La distancia mas larga es: " << mayor << "\n";
	cout << "La distancia mas corta es: " << menos << "\n";
	cout << "La suma de las distancias es: " << suma << "\n";
	cout << "La media de las distancias es: " << media << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "Presione ENTER para continuar\n";

	cin.ignore();
	cin.get();
	return 0;
}

int ejercicio5()
{
	{
		double num1, num2, resultado;
		string simbolo;
		cout << "Ingrese dos numeros y el signo de la operacion separados por espacios\n Ejemplo: 12 4 +\n";
		cin >> num1 >> num2 >> simbolo;
		if (simbolo == "+")
		{
			resultado = num1 + num2;
		}
		else if (simbolo == "-")
		{
			resultado = num1 - num2;
		}
		else if (simbolo == "/")
		{
			resultado = num1 / num2;
		}
		else if (simbolo == "*" || simbolo == "x" || simbolo == "X")
		{
			resultado = num1 * num2;
		}

		cout << "\n \nEl resultado de la operacion es: " << resultado;
		cout << "\n\n\n Presione Enter para continuar";

		cin.ignore();
		cin.get();
		return 0;
	}
}

int ejercicio8y9()
{
	int arroz = 1, arrozactual = 0, cuadrados = 1;
	while (arrozactual < 1000)
	{
		arrozactual += arroz;
		cuadrados += 1;
		arroz = arroz * 2;
	}
	cout << "Para 1000 granos";
	cout << "para un total de: " << arrozactual << " de granos de arroz, se necesitan: " << cuadrados << "cuadrados.";
	cout << "\n";
	int arroz2 = 1, arrozactual2 = 0, cuadrados2 = 1;
	while (arrozactual2 < 1000000)
	{
		arrozactual2 += arroz2;
		cuadrados2 += 1;
		arroz2 = arroz2 * 2;
	}
	cout << "Para 1000000 granos";
	cout << "para un total de: " << arrozactual2 << " de granos de arroz, se necesitan: " << cuadrados2 << " cuadrados.";
	cout << "\n";
	int arroz3 = 1, arrozactual3 = 0, cuadrados3 = 1;
	while (arrozactual3 < 1000000000)
	{
		arrozactual3 += arroz3;
		cuadrados3 += 1;
		arroz3 = arroz3 * 2;
	}
	cout << "Para 1000000000 granos";
	cout << "para un total de: " << arrozactual3 << " de granos de arroz, se necesitan: " << cuadrados3 << " cuadrados.";
	cout << "\n";
	int arroz4 = 1, arrozactual4 = 0, cuadrados4 = 1;
	while (cuadrados4 < 64)
	{
		arrozactual4 += arroz4;
		cuadrados4 += 1;
		arroz4 = arroz4 * 2;
		//Para revisar hasta que numero se llena un int y cuantos cuadros se necesitan
		cout << "para un total de: " << arrozactual4 << " de granos de arroz, se necesitan: " << cuadrados4 << " cuadrados\n.";
		//Para un total de 2147483647 de granos de arroz, se necesitan: 32 cuadrados
	}
	cout << "\n";
	cin.ignore();
	cin.get();
	return 0;
}

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

int ejercicio18()
{
	int a, b, c;
	double operacion, resultado1, resultado2, cuadrado, raiz;
	cout << "Ingrese los tres numeros de su funcion cuadratica\n";
	cin >> a >> b >> c;
	cuadrado = pow(b, 2);
	raiz = cuadrado - (4 * a*c);
	raiz = sqrt(raiz);
	operacion = -b;
	resultado1 = (operacion + raiz) / (2 * a);
	resultado2 = (operacion - raiz) / (2 * a);
	cout << "\n";
	cout << "El resultado es:\n";
	cout << "X1 = " << resultado1 << "\n";
	cout << "X2 = " << resultado2 << "\n";
	cin.ignore();
	cin.get();
	return 0;
}

int main()
{
	
	int elegir;
	do
	{
		cout << "Elija el ejercicio del capitulo 4 que quiere ver\n";
		cout << "1- Drill\n";
		cout << "2- Ejercicio 3\n";
		cout << "3- Ejercicio 5\n";
		cout << "4- Ejercicios 8 y 9\n";
		cout << "5- Ejercicios 18\n";
		cout << "6- Ejercicios 19, 20 y 21\n";
		cin >> elegir;
		switch (elegir)
		{
		case 0:
			break;
		case 1:
			drill4();
			break;
		case 2:
			ejercicio3();
			break;
		case 3:
			ejercicio5();
			break;
		case 4:
			ejercicio8y9();
			break;
		case 5:
			ejercicio18();
			break;
		case 6:
			ejercicio192021();
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