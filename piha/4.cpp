#include <iostream>
#include <string>
#include <algorithm> // Não usaremos, mas seria necessário se não usássemos a pilha.

using namespace std;

struct No {
    int valor; // Armazena o resto (0 ou 1)
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
        return -1; 
    }
    No* temp = p.topo;
    int valor = temp->valor;
    p.topo = temp->prox;
    delete temp;
    return valor;
}

bool isEmpty(Pilha &p){
    return p.topo == nullptr;
}


string decimalParaBinario(int decimal) {
    if (decimal == 0) {
        return "0";
    }

    Pilha p;
    string binario = "";
    int quociente = decimal;

    while (quociente > 0) {
        int resto = quociente % 2;
        push(p, resto);
        quociente = quociente / 2;
    }

    while (!isEmpty(p)) {
        binario += to_string(pop(p));
    }

    return binario;
}

int main() {
    int n1 = 10;
    cout << "Decimal: " << n1 << " -> Binario: " << decimalParaBinario(n1) << endl;

    int n2 = 25;
    cout << "Decimal: " << n2 << " -> Binario: " << decimalParaBinario(n2) << endl;
    
    int n3 = 13; // 1101
    cout << "Decimal: " << n3 << " -> Binario: " << decimalParaBinario(n3) << endl;

    int n4 = 0;
    cout << "Decimal: " << n4 << " -> Binario: " << decimalParaBinario(n4) << endl;

    int n5 = 32; // 100000
    cout << "Decimal: " << n5 << " -> Binario: " << decimalParaBinario(n5) << endl;
    
    return 0;
}