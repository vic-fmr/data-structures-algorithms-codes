#include <iostream>
using namespace std;

struct No {
	int valor;
	No* prox;
};

struct Fila {
	No* inicio;
	No* fim;
	Fila() : inicio(nullptr), fim(nullptr) {}
};

void enqueue(Fila &f, int valor) {

    //Criação padrão de um novo nó
	No* novoNo = new No;
	novoNo->valor = valor;
	novoNo->prox = nullptr;

    //Inserção no final da fila
	if (f.fim == nullptr) {
        //Fila vazia
		f.inicio = f.fim = novoNo;
	} else {
        //Fila não vazia
		f.fim->prox = novoNo; // Aponta o próximo do fim atual para o novo nó
		f.fim = novoNo; // Atualiza o fim da fila para o novo nó
	}
}

int dequeue(Fila &f) {
    //Verifica se a fila está vazia
	if (f.inicio == nullptr) {
		cout << "Fila vazia!" << endl;
		return -1;
	}

    //Temp para pegar o valor do início
	No* temp = f.inicio;
	int valor = temp->valor;// Guarda o valor a ser retornado
	f.inicio = temp->prox;// Atualiza o início da fila

    // Se a fila ficar vazia após o dequeue
	if (f.inicio == nullptr) {
		f.fim = nullptr;
	}
	delete temp;
	return valor;
}

void exibir(Fila &f) {
	No* temp = f.inicio;
	cout << "Fila: ";
	while (temp != nullptr) {
		cout << temp->valor << " ";
		temp = temp->prox;
	}
	cout << endl;
}

int main() {
	Fila f;
	enqueue(f, 10);
	enqueue(f, 20);
	enqueue(f, 30);
	exibir(f);
	cout << "Dequeue: " << dequeue(f) << endl;
	exibir(f);
	return 0;
}
