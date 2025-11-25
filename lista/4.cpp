#include <iostream>
#include <vector>

using namespace std;

struct No{
    int valor;
    No* prox;
};

void inserirOrdenado(No* &raiz, int valor) {
    cout << "Inserindo ordenadamente: " << valor << endl;

    No* novoNo = new No;
    novoNo->valor = valor;
    novoNo->prox = nullptr;

    if (raiz == nullptr || valor < raiz->valor) {
        novoNo->prox = raiz;
        raiz = novoNo;
        return;
    }

    No* atual = raiz;
    
    while (atual->prox != nullptr && atual->prox->valor < valor) {
        atual = atual->prox;
    }

    novoNo->prox = atual->prox;
    atual->prox = novoNo;
}

No* deletarNo(No* raiz, int valor){
    cout << "Deletando: " << valor << endl;

    if(raiz == nullptr)
        return nullptr;

    if(raiz->valor == valor){
        No* novaRaiz = raiz->prox;
        delete raiz;
        return novaRaiz;
    }

    No* temp = raiz;

    while (temp->prox != nullptr && temp->prox->valor != valor)
    {
        temp = temp->prox;
    }

    if(temp->prox == nullptr)
        return raiz;
    
    No* noParaDeletar = temp->prox;
    temp->prox = noParaDeletar->prox;
    delete noParaDeletar;

    return raiz;
}

void exibirLista(No* raiz){

    No* temp = raiz;

    cout << "Exibindo Lista: ";

    while (temp != nullptr)
    {
        cout << temp->valor;

        if(temp->prox != nullptr){
            cout << " -> ";
        } else{
            cout << endl;
        }

        temp = temp->prox;
    }
}

int contarElementos(No* raiz){
    int contador = 0;
    No* atual = raiz;

    while (atual != nullptr)
    {
        contador++;
        atual = atual->prox;
    }
    
    return contador;
}

void reverterLista(No* &raiz) {
    cout << "\nRevertendo a lista..." << endl;
    No* anterior = nullptr;
    No* atual = raiz;
    No* proximo = nullptr;

    while (atual != nullptr) {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }

    raiz = anterior;
}

int main(){
    No* raiz = nullptr;

    inserirOrdenado(raiz, 10);
    inserirOrdenado(raiz, 50);
    inserirOrdenado(raiz, 5);
    inserirOrdenado(raiz, 20);
    inserirOrdenado(raiz, 1100);
    inserirOrdenado(raiz, 1);

    cout << "\n--- Lista Original ---" << endl;
    exibirLista(raiz);

    reverterLista(raiz);

    cout << "--- Lista Revertida ---" << endl;
    exibirLista(raiz);

    reverterLista(raiz);
    cout << "--- Lista Revertida Novamente ---" << endl;
    exibirLista(raiz);
    
    return 0;
}