#include <iostream>
#include <vector>

using namespace std;

struct No{
    int valor;
    No* prox;
};

No* inserirNoInicio(No* raiz, int valor){
    cout << "Inserindo no inicio: " << valor << endl;
    No* novoNo = new No;

    novoNo->valor = valor;
    novoNo->prox = raiz;

    return novoNo;
}

void inserirNoFinal(No* &raiz, int valor){
    cout << "Inserindo no final: " << valor << endl;
    No* temp = raiz;

    if(temp == nullptr){
        raiz = new No;
        raiz->valor = valor;
        raiz->prox = nullptr;
        return;
    }

    while (temp->prox != nullptr)
    {
        temp = temp->prox;
    }

    No* novoNo = new No;
    novoNo->valor = valor;
    novoNo->prox = nullptr;
    
    temp->prox = novoNo;
    
}

No* deletarNo(No* raiz, int valor){
    cout << "Deletando: " << valor << endl;

    if(raiz == nullptr)
        return nullptr;

    if(raiz->valor == valor){
        No* novaRaiz = raiz->prox;
        delete raiz;
        raiz = novaRaiz;
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

int main(){
    No* raiz = nullptr;

    inserirNoFinal(raiz, 12);
    inserirNoFinal(raiz, 11);
    inserirNoFinal(raiz, 1100);

    raiz = inserirNoInicio(raiz, 10);
    raiz = inserirNoInicio(raiz, 20);
    raiz = inserirNoInicio(raiz, 50);


    exibirLista(raiz);

    raiz = deletarNo(raiz, 1100);

    exibirLista(raiz);

}