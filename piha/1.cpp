#include <iostream>
using namespace std;

struct No {
	int valor;
	No* prox;
};

struct Pilha {
	No* topo;
	Pilha() : topo(nullptr) {}
};

void push(Pilha &p, int valor) {
	No* novoNo = new No;
	novoNo->valor = valor;
	novoNo->prox = p.topo;
	p.topo = novoNo;
}

int pop(Pilha &p) {
	if (p.topo == nullptr) {
		cout << "Pilha vazia!" << endl;
		return -1;
	}
	No* temp = p.topo;
	int valor = temp->valor;
	p.topo = temp->prox;
	delete temp;
	return valor;
}

int top(Pilha &p){
    return p.topo->valor;
}

bool isEmpty(Pilha &p){
    return p.topo == nullptr;
}

void exibir(Pilha &p) {
	No* temp = p.topo;
	cout << "Pilha: ";
	while (temp != nullptr) {
		cout << temp->valor << " ";
		temp = temp->prox;
	}
	cout << endl;
}

int main() {
	Pilha p;
	push(p, 10);
	push(p, 20);
	push(p, 30);
	exibir(p);
	cout << "Pop: " << pop(p) << endl;
	exibir(p);
	return 0;
}
