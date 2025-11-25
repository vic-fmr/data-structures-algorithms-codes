#include <iostream>
using namespace std;

void contagem_regressiva(int n) {
	if (n < 0) return;
	cout << n;
	if (n > 0) cout << ", ";
	contagem_regressiva(n - 1);
}

int main() {
	int n;
	cout << "Digite um número para a contagem regressiva: ";
	cin >> n;
	contagem_regressiva(n);
	cout << endl;
	return 0;
}
