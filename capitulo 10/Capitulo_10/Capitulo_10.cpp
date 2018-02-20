#include "librerias.h"
//Drill
struct point
{
	double x;
	double y;
	point(double xx = 0, double yy = 0) :x(xx), y(yy) { }

};
void crear_archivo(string archivo)//Creo el archivo tipo txt utilisando nombrearchivo
{
	ofstream txt;
	getline(cin, archivo);
	txt.open(archivo.c_str(), ios::out);

}
istream& operator>>(istream& ist, point& p)
{
	ist >> p.x >> p.y;
	return ist;
}
ostream& operator<<(ostream& ost, const point& p)
{
	ost << "(" << p.x << "," << p.y << ")" << endl;
	return ost;
}
int drill()
{
	string archivo = "mydata.txt";
	crear_archivo(archivo);
	vector <point> original_points;
	point puntos;
	cout << "Introdusca 7 cordenadas (x y)" << endl;
	for (int i = 0; i < 7; i++)
	{
		cin >> puntos;
		original_points.push_back(puntos);
	}
	for (int i = 0; i < original_points.size(); i++)
	{
		cout << original_points[i];
	}
	ofstream documento;
	documento.open(archivo.c_str);
	for (int i = 0; i < original_points.size(); i++)
	{
		documento << original_points[i];
	}
	documento.close();
	ifstream procesodoc;
	procesodoc.open(archivo);
	char n;
	vector <char> processed_points;
	while (procesodoc >> n)
	{
		processed_points.push_back(n);
	}
	for (int i = 0; i < original_points.size(); i++)
	{
		cout << original_points[i];
	}
	cout << "\n";
	for (int i = 0; i < processed_points.size(); i++)
	{
		cout << processed_points[i];
	}

	return 0;
}
//Acaba Drill

//parte del ejercicio 1
void agregar_nums(vector<int>& vec, string archivo)// Lee los numeros separados por un espacio
{
	ifstream ist(archivo.c_str());
	if (!ist) error("Hijoles, no se puede abrir este archivo\n", archivo);//si no se encuentra el archivo
	int n;
	while (ist >> n) 
		vec.push_back(n);//agrega los numeros al vector
}

int ejercicio1()
{
	try
	{
		vector<int> nums;
		string nombre_archivo;
		int sum = 0;

		cout << "Ingresa el nombre del archivo:\n";
		cin >> nombre_archivo;

		agregar_nums(nums, nombre_archivo);

		
		for (int i = 0; i<nums.size(); ++i)
			sum += nums[i];

		cout << "La suma de los numeros en el archivo: " << nombre_archivo << " es de " << sum << ".\n";
		cout << "\nLa cual se produjo de los numeros\n";
		for (int i = 0; i < nums.size(); i++)
			cout << nums[i] << " ";
		cout << "\nLos cuales son los numeros en el archivo";
	}
	catch (exception& e) {
		cerr << e.what() << endl;//para dar el mensaje de erro
	}
	return 0;
}
//acaba el ejercicio 1

//ejerccio 2
string nombrearchivo = "raw_temps.txt";
void crear_archivo()//Creo el archivo tipo txt utilisando nombrearchivo
{
	ofstream txt;
	getline(cin, nombrearchivo);
	txt.open(nombrearchivo.c_str(), ios::out);

}
struct Reading {
	int hora;
	double temperatura;
	Reading(int h, double t) :hora(h), temperatura(t) { }
};
Reading agregar(int& h)// Para crear de manera aleatoria la temperatura
{
	double t = randint(44.6, 107.6);
	return Reading(h++, t);
}
int ejercicio2()
{
	try {
		vector<Reading> readings;
		ofstream ost(nombrearchivo.c_str());
		if (!ost) error("Hijoles, no se puede abrir este archivo", nombrearchivo);
		int h = 0;
		for (int i = 0; i < 50; ++i)
		{
			if (h>24)//para la hora
				h = 0;
			readings.push_back(agregar(h));
		}
		for (int i = 0; i<readings.size(); ++i)//ingreso los datos hora y temperatura al archivo
			ost << readings[i].hora << " " << readings[i].temperatura << endl;
	}
	catch (exception& e) {
		cerr << e.what() << endl;
	}
	
	return 0;
}
//acaba el ejercicio 2

//Ejercicio 3 (utiliza funciones del ejercicio 2)
int ejercicio3()
{
	try {
		vector<Reading> readings;
		ofstream ost(nombrearchivo.c_str());
		if (!ost) error("Hijoles, no se puede abrir este archivo", nombrearchivo);
		int h = 0;
		for (int i = 0; i < 50; ++i)
		{
			if (h > 24)//para la hora
				h = 0;
			readings.push_back(agregar(h));
		}
		for (int i = 0; i < readings.size(); ++i)//ingreso los datos hora y temperatura al archivo
			ost << readings[i].hora << " " << readings[i].temperatura << endl;

		vector<int> temp;
		vector<int> solotemp;
		ifstream documento;
		documento.open(nombrearchivo);
		int n;
		while (documento >> n)
		{
			temp.push_back(n);
		}
		for (int i = 1; i < temp.size(); i += 2)
		{
			int n = temp[i];
			solotemp.push_back(n);
		}
		cout << "Las temperaturas registradas son:\n";
		for (int i = 0; i < solotemp.size(); i++)
		{
			cout << solotemp[i] << ",";
		}
		double media = 0;
		double mediana;
		int arc;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (solotemp[i] > solotemp[j])
				{
					arc = solotemp[i];
					solotemp[i] = solotemp[j];
					solotemp[j] = arc;
				}
			}
		}
		cout << "\n";
		cout << "\n";
		mediana = (solotemp[25] + solotemp[26]) / 2;
		cout << "La mediana de las temperaturas es: " << mediana << endl;
		for (int i = 0; i < solotemp.size(); i++)
		{
			media += solotemp[i];
		}
		media = (media / solotemp.size());
		cout << "La media de las temperaturas es: " << media << endl;
	}
	catch (exception& e) {
		cerr << e.what() << endl;
	}

	return 0;
}
//acaba ejercicio 3

//Ejercicio 4 (utiliza funciones del ejercicio 2 y 3)
int ejercicio4()
{
	try {
		char tipo = 'a';

		cout << "Introdusca 'c' para celcius o 'f' para fahrenheit" << endl;
		cin >> tipo;

		vector<Reading> readings;
		ofstream ost(nombrearchivo.c_str());
		if (!ost) error("Hijoles, no se puede abrir este archivo", nombrearchivo);
		int h = 0;
		for (int i = 0; i < 50; ++i)
		{
			if (h > 24)//para la hora
				h = 0;
			readings.push_back(agregar(h, tipo));
		}
		for (int i = 0; i < readings.size(); ++i)//ingreso los datos hora y temperatura al archivo
			ost << readings[i].hora << " " << readings[i].temperatura << endl;

		vector<int> temp;
		vector<int> solotemp;
		ifstream documento;
		documento.open(nombrearchivo);
		int n;
		while (documento >> n)
		{
			temp.push_back(n);
		}
		for (int i = 1; i < temp.size(); i += 3)
		{
			int n = temp[i];
			solotemp.push_back(n);
		}
		if (tipo == 'c')
		{
			cout << "Las temperaturas registradas en celcius son:\n";
		}
		else
		{
			cout << "Las temperaturas registradas en fahrenheit son:\n";
		}
		for (int i = 0; i < solotemp.size(); i++)
		{
			cout << solotemp[i] << ",";
		}
		double media = 0;
		double mediana;
		int arc;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (solotemp[i] > solotemp[j])
				{
					arc = solotemp[i];
					solotemp[i] = solotemp[j];
					solotemp[j] = arc;
				}
			}
		}
		cout << "\n";
		cout << "\n";
		if (tipo == 'c')
		{
			mediana = (solotemp[25] + solotemp[26]) / 2;
			cout << "La mediana de las temperaturas en celcius es: " << mediana << endl;
			for (int i = 0; i < solotemp.size(); i++)
			{
				media += solotemp[i];
			}
			media = (media / solotemp.size());
			cout << "La media de las temperaturas en celcius es: " << media << endl;
			vector<int>a_faren;
			for (int i = 0; i < solotemp.size(); i++)
			{
				a_faren.push_back(solotemp[i] + 32);
			}
			double medianaf, mediaf;
			medianaf = (a_faren[25] + a_faren[26]) / 2;
			cout << "La mediana de las temperaturas en fahrenheit es: " << medianaf << endl;
			for (int i = 0; i < solotemp.size(); i++)
			{
				mediaf += solotemp[i];
			}
			mediaf = (mediaf / solotemp.size());
			cout << "La media de las temperaturas en fahrenheit es: " << mediaf << endl;
		}
		else
		{
			mediana = (solotemp[25] + solotemp[26]) / 2;
			cout << "La mediana de las temperaturas en fahrenheit es: " << mediana << endl;
			for (int i = 0; i < solotemp.size(); i++)
			{
				media += solotemp[i];
			}
			media = (media / solotemp.size());
			cout << "La media de las temperaturas en fahrenheit es: " << media << endl;
			vector<int>a_cel;
			for (int i = 0; i < solotemp.size(); i++)
			{
				a_cel.push_back(solotemp[i] + 32);
			}
			double medianac, mediac;
			medianac = (a_cel[25] + a_cel[26]) / 2;
			cout << "La mediana de las temperaturas en celcius es: " << medianac << endl;
			for (int i = 0; i < solotemp.size(); i++)
			{
				mediac += solotemp[i];
			}
			mediac = (mediac / solotemp.size());
			cout << "La media de las temperaturas en celcius es: " << mediac << endl;
		}

	}
	catch (exception& e) {
		cerr << e.what() << endl;
	}

	return 0;
}
//acaba ejercicio 4

int main()
{

	int elegir;
	do
	{
		cout << "Elija el ejercicio del capitulo 4 que quiere ver\n";
		cout << "1- Drill\n";
		cout << "2- Ejercicio 1\n";
		cout << "3- Ejercicio 2\n";
		cout << "4- Ejercicio 3\n";
		cout << "5- Ejercicio 4\n";
		cout << "0- Salir\n";
		cin >> elegir;
		switch (elegir)
		{
		case 0:
			break;
		case 1:
			drill();
			break;
		case 2:
			ejercicio1();
			break;
		case 3:
			ejercicio2();
			break;
		case 4:
			ejercicio3();
			break;
		case 5:
			ejercicio4();
			break;
		default:
			break;
		}
		cout << "\n";
		cout << "Presione Enter para continuar\n\n";
		cin.ignore();
		cin.get();
	} while (elegir != 0);


	cin.get();
	return 0;
}