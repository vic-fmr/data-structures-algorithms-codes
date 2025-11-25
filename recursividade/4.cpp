#include <iostream>
using namespace std;

int produto(int a, int b) {
	if (b == 0)
		return 0;
	else if (b > 0)
		return a + produto(a, b - 1);
	else 
		return -produto(a, -b);
}

int main() {
	int a, b;
	cout << "Digite dois inteiros: ";
	cin >> a >> b;
	cout << "Produto: " << produto(a, b) << endl;
	return 0;
}
