#include <iostream>
#include <string>
using namespace std;

int palindromo(const string& s, int ini, int fim) {
	if (ini >= fim) return 1;
	if (s[ini] != s[fim]) return 0;
	return palindromo(s, ini + 1, fim - 1);
}

int main() {
	string palavra;
	cout << "Digite uma palavra: ";
	cin >> palavra;
	if (palindromo(palavra, 0, palavra.size() - 1))
		cout << "É palíndromo!" << endl;
	else
		cout << "Não é palíndromo." << endl;
	return 0;
}
