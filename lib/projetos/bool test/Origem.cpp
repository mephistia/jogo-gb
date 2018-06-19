#include <iostream>
#include <string>

using namespace std;

int main() {

	int a, b, c, d;
	cout << endl << "Digite 1 ou 0" << endl;
	cin >> a;

	cout << endl << "Digite 1 ou 0" << endl;
	cin >> b;

	cout << endl << "Digite 1 ou 0" << endl;
	cin >> c;

	cout << endl << "Digite 1 ou 0" << endl;
	cin >> d;


	if (a || b|| c || d) {
		cout << endl << "Existe algum 1" << endl;
	}
	else
		cout << endl << "Não existe algum 1" << endl;

	system("pause");
	return 0;

	

}