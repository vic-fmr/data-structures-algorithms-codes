#include <iostream>

using namespace std;

int buscaBinaria(int vetor[], int tamanho, int valor) {
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (vetor[meio] == valor) {
            return meio; // Retorna a posicao do valor encontrado
        } else if (vetor[meio] < valor) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return -1; // Retorna -1 se o valor nao for encontrado
}

int buscaBinariaComp(int vetor[], int tamanho, int valor) {
    int inicio = 0;
    int fim = tamanho - 1;
    int count = 0;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        count++;

        if (vetor[meio] == valor) {
            return count; 
        } else if (vetor[meio] < valor) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return -1; // Retorna -1 se o valor nao for encontrado
}

int main(){
    cout << "Questão 1: \n";
    int vetor[] = {2, 4, 6, 8, 10, 12, 13, 14, 16, 18};
    int valor = 13;
    int pos = buscaBinaria(vetor, 10, valor);

    if(pos != -1){
        cout << "Valor: " << valor << " encontrado na posição: " << pos << endl;
    } else {
        cout << "Valor não encontrado.";
    }

    cout << "Questão 2: \n";
    int vetor2[] = {10, 20,30 ,40 ,50 ,60 ,70, 80, 90, 100};
    int valor2 = 100;
    int comp = buscaBinariaComp(vetor, 10, valor);

    if(comp != -1){
        cout << "Valor: " << valor2 << " encontrado com " << comp << " comparações." << endl;
    } else {
        cout << "Valor não encontrado.";
    }
}