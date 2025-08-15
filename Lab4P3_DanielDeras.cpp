#include <iostream>
using namespace std;
#include <cstring>
int main() {
	int resp;
	char* mensaje = new char[51];
	bool validar = false;
	do {
		cout << "--Bienvenido--\n";
		cout << "1) ejercicio 1\n";
		cout << "2) ejercicio 2\n";
		cout << "0) Salir\n";
		cin >> resp;
		switch (resp) {
		case 1:
			do
			{
				cout << "Ingrese el mensaje a encriptar(En mayusculas): \n";
				cin.getline(mensaje, 51);
				for (int i = 0; i < strlen(mensaje); i++) {
					if ((int)mensaje[i] < 65 || (int)mensaje[i] > 90) {
						validar = true;
					}
				}
			} while (validar);
			break;
		default:
			break;
		}
	} while (resp);
}
