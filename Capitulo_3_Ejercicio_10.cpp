#include <iostream>
#include <string>
using namespace std;
int main()
{
	string operador,operacion;
	int a, b, resultado;
	cout << "Escribe la operacion que quieras hacer, y despues dos numeros, todo separado por espacios\n";
	cout << "Ejemplo: + 100 15 \nlas operaciones disponibles son '-' '+' '*' '/'\n ";
	cin >> operador >> a >> b;
	if (operador=="+")
	{
		resultado = a + b;
		operacion = "suma";
	}
	else if (operador=="-")
	{
		resultado = a - b;
		operacion = "resta";
	}
	else if(operador=="*")
	{
		resultado = a * b;
		operacion = "multiplicacion";
	}
	else if (operador == "/")
	{
		resultado = a / b;
		operacion = "division";
	}
	cout << "\n";
	cout << "El resulatdo de la " << operacion << " es " << resultado;

	cin.ignore();
    cin.get();
	return 0;
}