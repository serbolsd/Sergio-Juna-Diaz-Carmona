#include <iostream>
#include <string>
using namespace std;
int main()
{
	int edad;
	string mio, nom1, nomb2,sexo,pronombre;
	cout << "Ingresa tu nombre:\n";
	cin >> mio;
	cout << "Ingrese el nombre de a quien quiere escribirle:\n";
	cin >> nom1;
	cout << "Ingrese el nombre de un amigo:\n";
	cin >> nom1;
	cout<<"Ingres H, si su amigo es hombre o m si su amigo es mujer\n";
	cin >> sexo;
	cout << "Ingrese la edad del remitente\n";
	cin >> edad;
	cout << "------------------------------------------------------------------------------------------------------" <<"\n";
	cout << "\n";
	cout << "\n";
	cout << "------------------------------------------------------------------------------------------------------" << "\n";
	cout << "Querid@: " << nom1 <<".";
	cout << "Como va todo en la vida? La mia sigue igual, siempre aburrida.\n";
	if (sexo=="h")
	{
		cout << "Por cierto, si has visto al " << nomb2 << " por favor dile que me llame... él me debe dinero.\n";
	}
	else
	{
		cout << "Por cierto, si has visto a la " << nomb2 << " por favor dile que me llame... la extraño.\n";
	}
	cout << "Tambien escuche que ya tienes " << edad << " años,";
	if (edad<12)
	{
		cout << "El proximo año ya tendras " << edad + 1 << ".\n";
	}
	else if (edad==17)
	{
		cout << "el proximo año ya podras votar\n";
	}
	else if(edad>70)
	{
		cout << "espero que este disfrutando el retiro\n";
	}
	else
	{
		cout << "que rapido pasa el tiempo.\n";
	}
	cout << "Espero vernos pronto.\nTu gran amigo " << mio <<".";
	cin.ignore();
	cin.get();
	return 0;
}