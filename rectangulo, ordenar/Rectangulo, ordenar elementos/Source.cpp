#include <iostream>
#include <string>
using namespace std;
int rectan(int& a, int&b, int *peri, int *are);
int main()
{
	int elegir,arc;
	const int n = 5;
	do
	{
		cout << "Elija el numero de lo que quiere hacer" << endl;
		cout << "1- Calcular perimetro y area de un rectangulo\n";
		cout << "2- ordenar numeros de menor a mayor\n";
		cout << "0- Salir\n";
		cin >> elegir;

		switch (elegir)
		{
		case 1:
			int a, b, peri, are;
			cout << "Ingrese la longitud de su rectangulo\n";
			cin >> a;
			cout << "Ingrese la altura de su rectangulo\n";
			cin >> b;
			rectan(a, b, &peri, &are);
			cout << "El perimetro de su rectangulo es: " << peri << " y el area es  " << are;
			printf("\n Presione ENTER para continuar");
			break;
		case 2:

			
			cout << "Por defecto la cantidad de numeros sera 5\n";				
			int v[n];
			cout << "INGRESE NUMEROS: " << endl;
			for (int i = 0; i < n; i = i + 1)
			{
				cin >> v[i];
				cout << " " << endl;
			}
			for (int i = 0; i < n; i++)
			for (int j = i + 1; j<n; j++)
			
			if (v[i] > v[j])
				{
					arc = v[i];
					v[i] = v[j];
					v[j] = arc;
				}
			cout << " " << endl;
			cout << "LISTA ORDENADA DE LOS ELEMENTOS" << endl;
			for (int i = 0; i<n; i++) 
			{
				cout << v[i] << endl;
			}
			printf("\n Presione ENTER para continuar");



			break;
		case 0:
			break;
		default:
			if (elegir != 0 || elegir != 1 || elegir != 2)
			{
				elegir = -1;
			}
			cout << "No existe esa opcion\n";
			printf("\n Presione ENTER para continuar");
			break;


		}
		cin.ignore();
		cin.get();
		
	} while (elegir != 0);

}
int rectan(int& a, int&b,int *peri, int *are)
{
	*peri = (2 * (a)) + (2 * (b));
	*are = a * b;
	return 0;
}