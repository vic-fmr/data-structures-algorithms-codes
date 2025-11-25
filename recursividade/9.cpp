#include <iostream>
using namespace std;

int soma_digitos_iterativo(int n) {
	n = abs(n);
	int soma = 0;
	while (n > 0) {
		soma += n % 10;
		n /= 10;
	}
	return soma;
}

int main() {
	int num;
	cout << "Digite um número inteiro: ";
	cin >> num;
	cout << "Soma dos dígitos: " << soma_digitos_iterativo(num) << endl;
	return 0;
}
