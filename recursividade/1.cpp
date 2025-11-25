#include <iostream>
using namespace std;

int contar_digitos(int n) {
	if (n < 10 && n > -10) 
		return 1;
	else
		return 1 + contar_digitos(n / 10);
}

int main() {
	int num;
	cout << "Digite um número inteiro: ";
	cin >> num;
	cout << "Quantidade de dígitos: " << contar_digitos(num) << endl;
	return 0;
}
