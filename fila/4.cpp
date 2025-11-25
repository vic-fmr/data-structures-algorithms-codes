#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;


struct No {
    int valor;
    No* prox;
    No(int v) : valor(v), prox(nullptr) {}
};


class Pilha {
private:
    No* topo;
public:
    Pilha() : topo(nullptr) {}
    ~Pilha() { while (topo) pop(); }

    void push(int valor) {
        No* novoNo = new No(valor);
        novoNo->prox = topo;
        topo = novoNo;
    }

    int pop() {
        if (!topo) throw runtime_error("Pilha vazia!");
        No* temp = topo;
        int valor = temp->valor;
        topo = topo->prox;
        delete temp;
        return valor;
    }

    bool isEmpty() const {
        return topo == nullptr;
    }
};


class Fila {
private:
    No* frente; 
    No* tras;   
public:
    Fila() : frente(nullptr), tras(nullptr) {}
    ~Fila() { while (frente) dequeue(); }
    
    void enqueue(int valor) {
        No* novoNo = new No(valor);
        if (isEmpty()) {
            frente = novoNo;
            tras = novoNo;
        } else {
            tras->prox = novoNo;
            tras = novoNo;
        }
    }

    int dequeue() {
        if (isEmpty()) throw runtime_error("Fila vazia!");
        No* temp = frente;
        int valor = temp->valor;
        frente = frente->prox;
        if (frente == nullptr) tras = nullptr;
        delete temp;
        return valor;
    }

    bool isEmpty() const {
        return frente == nullptr;
    }
    
    void exibir() const {
        No* atual = frente;
        cout << "Fila: ";
        while (atual != nullptr) {
            cout << atual->valor << " ";
            atual = atual->prox;
        }
        cout << endl;
    }
};

void inverterFila(Fila& fila) {
    Pilha p;

    // 1. Transferência Fila -> Pilha
    while (!fila.isEmpty()) {
        p.push(fila.dequeue());
    }

    // 2. Transferência Pilha -> Fila
    while (!p.isEmpty()) {
        fila.enqueue(p.pop());
    }
}

// --- Função Principal ---

int main() {
    Fila minhaFila;

    // Preenche a fila original: 1 -> 2 -> 3 -> 4
    minhaFila.enqueue(1);
    minhaFila.enqueue(2);
    minhaFila.enqueue(3);
    minhaFila.enqueue(4);

    cout << "Ordem original: ";
    minhaFila.exibir();

    inverterFila(minhaFila);

    cout << "Ordem invertida: ";
    minhaFila.exibir(); // Deve exibir: 4 3 2 1 

    // Teste com outra fila
    Fila testeFila;
    testeFila.enqueue(10);
    testeFila.enqueue(20);

    cout << "\nOrdem original (Teste): ";
    testeFila.exibir();

    inverterFila(testeFila);

    cout << "Ordem invertida (Teste): ";
    testeFila.exibir(); // Deve exibir: 20 10 

    return 0;
}