#include <iostream>
using namespace std;
#include <cstring>
void imprimir_mensaje(char* mensaje) {
	for (int i = 0; i < strlen(mensaje); i++) {
		cout << mensaje[i];
	}
}
int main() {
	int resp;
	char* mensaje = new char[51];
	char* mensaje_anterior = new char[51];
	bool validar = false;
	int tamano_casa;
	do {
		cout << "--Bienvenido--\n";
		cout << "1) ejercicio 1\n";
		cout << "2) ejercicio 2\n";
		cout << "0) Salir\n";
		cin >> resp;
		cin.ignore();
		switch (resp) {
		case 1:
			do
			{
				validar = false;
				cout << "Ingrese el mensaje a encriptar(En mayusculas): \n";
				cin.getline(mensaje, 51);
				for (int i = 0; i < strlen(mensaje); i++) {
					if ((int)mensaje[i] < 65 || (int)mensaje[i] > 90) {
						validar = true;
					}
				}
			} while (validar);
			strcpy_s(mensaje_anterior, strlen(mensaje) + 1, mensaje);
			for (int i = 0; i < strlen(mensaje); i++) {
				if ((int)mensaje[i] == 65) {
					mensaje[i] = mensaje[i] + 2;

				}else if ((int)mensaje[i] == 90) {
					mensaje[i] = mensaje[i] - 2;

				}
				else if ((int)mensaje[i]%2 == 0) {
					mensaje[i] = mensaje[i] + 2;
				}
				else {
					mensaje[i] = (int)mensaje[i] - 2;
				}
			}
			cout << "La desencriptacion de ";
			imprimir_mensaje(mensaje_anterior);
			cout << " es: ";
			imprimir_mensaje(mensaje);
			cout << endl;
			break;
		case 2:
			do
			{
				cout << "Ingrese el numero de casas que hay en la residencial (entre 5 y 15): ";
				cin >> tamano_casa;
				if (tamano_casa < 5 || tamano_casa > 15) {
					cout << "NUMERO INVALIDO\n";
				}
			} while (tamano_casa < 5 || tamano_casa > 15);
			break;
		default:
			break;
		}
	} while (resp);
}
