#include <iostream>
using namespace std;
int main()
{
	int pen = 1, ppen, nic = 5, pnic, dim = 10, pdim, qua = 25, pqua, md = 50, pmd, cents;
	double dollars;
	cout << "¿Cuantos Pennies tiene?\n";
	cin >> ppen;
	cout << "¿Cuantos nickels tiene?\n";
	cin >> pnic;
	cout << "¿Cuantos dimes tiene?\n";
	cin >> pdim;
	cout << "¿Cuantos quarters tiene?\n";
	cin >> pqua;
	cout << "¿Cuantos half dollars tiene?\n";
	cin >> pmd;
	cents = ((ppen*pen) + (pnic*nic) + (pdim*dim) + (pqua*qua) + (pmd*md));
	dollars = cents * .01;
	cout << "Tienes " << ppen << " pennis\n";
	cout << "Tienes " << pnic << " nickels\n";
	cout << "Tienes " << pdim << " dimes\n";
	cout << "Tienes " << pqua << " quarters\n";
	cout << "Tienes " << pmd << " half dollar\n";
	cout << "La evalucion de todas las monedas indica que tienes " << cents << " cents\n";
	cout << "Lo que equivale a " << dollars << " dollars\n";
	cin.ignore();
	cin.get();
	return 0;
}