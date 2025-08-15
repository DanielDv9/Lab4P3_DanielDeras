#include <iostream>
using namespace std;
#include <cstring>
#include <cstdlib>
#include <ctime>   
void imprimir_mensaje(char* mensaje) {
	for (int i = 0; i < strlen(mensaje); i++) {
		cout << mensaje[i];
	}
}
void liberar_memoria(char* mensaje) {
	for (int i = 0; i < strlen(mensaje); i++) {
		delete[] mensaje;
	}
}
void combinacion_casas(int* arreglo, int& tamano_casa) {
	int* arreglo_ganancia = new int[tamano_casa];
	int posicion = 0;
	int acum = 0;
	for (int i = 0; i < tamano_casa; i++) {
		for (int j = 0; j < tamano_casa; j++) {
			if ((j + 2) > tamano_casa) {

			} else {
				acum += arreglo[j + 2];
			}
		}
		arreglo_ganancia[i] = acum;
		acum = 0;
	}
	cout << endl;
	for (int i = 0; i < tamano_casa; i++) {
		cout << " [" << arreglo_ganancia[i] << "] ";
	}
}
int main() {
	srand(time(0));
	int resp;
	char* mensaje = new char[51];
	char* mensaje_anterior = new char[51];
	bool validar = false;
	int tamano_casa;
	int* arreglo = NULL;
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
			liberar_memoria(mensaje);
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
			arreglo = new int[tamano_casa];
			for (int i = 0; i < tamano_casa; i++) {
				int numero_random = 500 + rand() % (10000 - 500 + 1);
				arreglo[i] = numero_random;
				cout << "Casa " << i << ": $" << arreglo[i] << endl;
			}
			combinacion_casas(arreglo, tamano_casa);
			break;
		default:
			break;
		}
	} while (resp);
}
