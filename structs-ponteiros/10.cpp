#include <iostream>
#include <string>
using namespace std;

struct ContaBancaria {
	string nome;
	int numero;
	float saldo;
};

void depositar(ContaBancaria &conta, float valor) {
	if (valor > 0) {
		conta.saldo += valor;
		cout << "Depósito realizado com sucesso!" << endl;
	} else {
		cout << "Valor inválido para depósito." << endl;
	}
}

void sacar(ContaBancaria &conta, float valor) {
	if (valor > 0 && conta.saldo >= valor) {
		conta.saldo -= valor;
		cout << "Saque realizado com sucesso!" << endl;
	} else {
		cout << "Saldo insuficiente ou valor inválido." << endl;
	}
}

void exibirSaldo(const ContaBancaria &conta) {
	cout << "Saldo atual: R$ " << conta.saldo << endl;
}

int main() {
	ContaBancaria conta;
	cout << "Digite o nome do titular: ";
	cin >> conta.nome;
	cout << "Digite o número da conta: ";
	cin >> conta.numero;
	conta.saldo = 0.0f;

	int opcao;
	float valor;
	do {
		cout << "\n1 - Depositar\n2 - Sacar\n3 - Exibir saldo\n0 - Sair\nEscolha: ";
		cin >> opcao;
		switch(opcao) {
			case 1:
				cout << "Valor para depositar: ";
				cin >> valor;
				depositar(conta, valor);
				break;
			case 2:
				cout << "Valor para sacar: ";
				cin >> valor;
				sacar(conta, valor);
				break;
			case 3:
				exibirSaldo(conta);
				break;
			case 0:
				cout << "Encerrando..." << endl;
				break;
			default:
				cout << "Opção inválida!" << endl;
		}
	} while(opcao != 0);

	return 0;
}
