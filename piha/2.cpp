#include <iostream>
#include <string>

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
        return -1; 
    }
    No* temp = p.topo;
    int valor = temp->valor;
    p.topo = temp->prox;
    delete temp;
    return valor;
}

int top(Pilha &p){
    if (p.topo == nullptr) {
        return -1;
    }
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

bool verificarParenteses(const string& expressao) {
    Pilha p; 
    
    for (char caractere : expressao) {
        if (caractere == '(') {
            push(p, 1); 
        } else if (caractere == ')') {
            if (isEmpty(p)) {
                return false;
            }
            pop(p);
        }
    }

    return isEmpty(p);
}

int main() {
    Pilha p;
    push(p, 10);
    push(p, 20);
    push(p, 30);
    exibir(p);
    cout << "Pop: " << pop(p) << endl;
    exibir(p);

    cout << "\n--- Teste de Balanceamento de Parenteses ---" << endl;
    
    string teste1 = "(())()";
    cout << "Expressao: \"" << teste1 << "\", Resultado: " 
         << (verificarParenteses(teste1) ? "Valido" : "Invalido") << endl;

    string teste2 = "(()";
    cout << "Expressao: \"" << teste2 << "\", Resultado: " 
         << (verificarParenteses(teste2) ? "Valido" : "Invalido") << endl;

    string teste3 = ")(()";
    cout << "Expressao: \"" << teste3 << "\", Resultado: " 
         << (verificarParenteses(teste3) ? "Valido" : "Invalido") << endl;

    string teste4 = "()(())";
    cout << "Expressao: \"" << teste4 << "\", Resultado: " 
         << (verificarParenteses(teste4) ? "Valido" : "Invalido") << endl;

    string teste5 = "";
    cout << "Expressao: \"" << teste5 << "\", Resultado: " 
         << (verificarParenteses(teste5) ? "Valido" : "Invalido") << endl;

    return 0;
}