#include <iostream>
using namespace std;

void contagem_regressiva_iterativa(int n) {
	for (int i = n; i >= 0; i--) {
		cout << i;
		if (i > 0) cout << ", ";
	}
	cout << endl;
}

int main() {
	int n;
	cout << "Digite um número para a contagem regressiva: ";
	cin >> n;
	contagem_regressiva_iterativa(n);
	return 0;
}
