#include <iostream>
#include <vector>
using namespace std;

int maior_elemento_iterativo(const vector<int>& v) {
	if (v.empty()) return 0; // ou lançar exceção
	int maior = v[0];
	for (size_t i = 1; i < v.size(); i++) {
		if (v[i] > maior)
			maior = v[i];
	}
	return maior;
}

int main() {
	int n, x;
	vector<int> v;
	cout << "Quantos elementos? ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Digite o elemento " << i+1 << ": ";
		cin >> x;
		v.push_back(x);
	}
	cout << "Maior elemento: " << maior_elemento_iterativo(v) << endl;
	return 0;
}
