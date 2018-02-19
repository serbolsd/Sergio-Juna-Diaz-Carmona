#include "d:\facilities.h"



int drill()
{
	int birth_year = 1999;

	cout << dec << "El año en decimal es: " << birth_year << endl;
	cout << hex << "El año en hexadecimal es: " << birth_year << endl;
	cout << oct << "El año en octales es: " << birth_year << endl;
	cout << dec;

	int edad = 18;

	cout << dec << "La edad en decimal es: " << edad << endl;
	cout << hex << "La edad en hexadecimal es: " << edad << endl;
	cout << oct << "La edad en octales es: " << edad << endl;
	cout << dec;
	int a, b, c, d;
	cout << "\n";
	cin >> a >> oct >> b >> hex >> c >> d;
	cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';
	cout << "\n";
	float numero = 1234567.89;
	cout << defaultfloat << numero << endl;
	cout << fixed << numero << endl;
	cout << scientific << numero << endl;
	cout << "\n";
	cout << setw(10) << "Diaz Sergio, 3118477673, sergio_jdc@hotmail.com" << endl;
	cout << setw(20) << "Guitierrez Alexix, 3118476512, brianguti@hotmail.com" << endl;
	cout << setw(10) << "Romero Aldo, 3118484236, ytaldolito96@hotmail.com" << endl;
	cout << setw(10) << "Aguilar Gabriel, 3318545673, ehirixhd@hotmail.com" << endl;
	cout << setw(10) << "Viorato Daniel, 31156123232, daniela@hotmail.com" << endl;
	cout << setw(10) << "Marquez Claudio, 3179874621, lecaludio@hotmail.com" << endl;


	return 0;
}
//ejericio 1
void crear_archivo(string nombrearchivo)//Creo el archivo tipo txt utilisando nombrearchivo
{
	ofstream txt;
	string nuevo_archivo;
	nuevo_archivo = nombrearchivo + " copia";
	getline(cin, nuevo_archivo);
	txt.open(nuevo_archivo.c_str(), ios::out);

}
void agregar_nums(vector<char>& vec, string archivo)// Lee los numeros separados por un espacio
{
	ifstream ist(archivo.c_str());
	if (!ist) error("Hijoles, no se puede abrir este archivo\n", archivo);//si no se encuentra el archivo
	char n;
	while (ist >> n)
		vec.push_back(n);//agrega los numeros al vector
}
void editar_copia(string nombrearchivo, vector<char> v)
{
	try {
		string nuevo_archivo;
		nuevo_archivo = nombrearchivo + " copia";
		ofstream ost(nuevo_archivo.c_str());
		string minuscula;
		int minus;
		if (!ost) error("Hijoles, no se puede abrir este archivo", nuevo_archivo);

		for (int i = 0; i < v.size(); ++i)//ingreso los datos hora y temperatura al archivo
		{

			minus = (v[i]);
			if (minus<97)
			{
				minus += 32;
			}
			minuscula = (char)minus;
			ost << minuscula;
		}
	}
	catch (exception& e) {
		cerr << e.what() << endl;
	}
}
void la_magia()
{
	try
	{
		string nuevo_archivo;
		vector<char> nums;
		string nombre_archivo;
		int sum = 0;

		cout << "Ingresa el nombre del archivo:\n";
		cin >> nombre_archivo;
		crear_archivo(nombre_archivo);
		agregar_nums(nums, nombre_archivo);


		for (int i = 0; i < nums.size(); ++i)
			cout << nums[i];
		cout << "\n";
		cout << "\n";
		for (int i = 0; i < nums.size(); i++)
			cout << nums[i];
		editar_copia(nombre_archivo, nums);

	}
	catch (exception& e) {
		cerr << e.what() << endl;//para dar el mensaje de erro
	}
}
int ejercico1()
{
	la_magia();

	return 0;
}
//acaba ejercicio 1

int main()
{

	int elegir;
	do
	{
		cout << "Elija el ejercicio del capitulo 4 que quiere ver\n";
		cout << "1- Drill\n";
		cout << "2- Ejercicio 1\n";
		//cout << "3- Ejercicio 2\n";
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
			drill();
			break;
		case 2:
			ejercico1();
			break;
		case 3:
			
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