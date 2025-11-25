#include <iostream>
#include <string>

using namespace std;

struct No {
    char caractere;
    No* prox;
};

struct Pilha {
    No* topo;
    Pilha() : topo(nullptr) {}
};

void push(Pilha &p, char c) {
    No* novoNo = new No;
    novoNo->caractere = c;
    novoNo->prox = p.topo;
    p.topo = novoNo;
}

char pop(Pilha &p) {
    if (p.topo == nullptr) {
        return '\0'; 
    }
    No* temp = p.topo;
    char c = temp->caractere;
    p.topo = temp->prox;
    delete temp;
    return c;
}

bool isEmpty(Pilha &p){
    return p.topo == nullptr;
}

string inverterString(const string& str) {
    Pilha p;
    string invertida = "";

    for (char c : str) {
        push(p, c);
    }

    while (!isEmpty(p)) {
        invertida += pop(p);
    }

    return invertida;
}

int main() {
    string original = "LIFO";
    string invertida = inverterString(original);
    
    cout << "String Original: " << original << endl;
    cout << "String Invertida: " << invertida << endl;

    original = "Estrutura de Dados";
    invertida = inverterString(original);
    
    cout << "\nString Original: " << original << endl;
    cout << "String Invertida: " << invertida << endl;
    
    return 0;
}