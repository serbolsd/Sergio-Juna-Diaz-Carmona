#include "librerias.h"

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

int main()
{

	int elegir;
	do
	{
		cout << "Elija el ejercicio del capitulo 4 que quiere ver\n";
		//cout << "1- Drill\n";
		cout << "2- Ejercicio 1\n";
		cout << "3- Ejercicio 2\n";
		/*cout << "4- Ejercicios 8 y 9\n";
		cout << "5- Ejercicios 18\n";
		cout << "6- Ejercicios 19, 20 y 21\n";*/
		cout << "0- Salir\n";
		cin >> elegir;
		switch (elegir)
		{
		case 0:
			break;
		case 1:
			
			break;
		case 2:
			ejercicio1();
			break;
		case 3:
			ejercicio2();
			break;
		case 4:
			
			break;
		case 5:
			
			break;
		case 6:
			
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