#include <iostream>

using namespace std;

int buscaBinaria(int vetor[], int tamanho, int valor){
    int inicio = 0; 
    int fim = tamanho - 1;
    int meio = 0;

    while (inicio <= fim) {
        int meio = (inicio + fim)/2;

        if(vetor[meio] == valor){
            return meio;
        } else if (vetor[meio] < valor){
            inicio = meio + 1;
        } else{
            fim = meio - 1;
        }
    }
    
    return -1;
}

int main() {
    int vetor[] = {3, 6, 9, 12, 15, 18, 21};
    int valor = 15;
    int pos = buscaBinaria(vetor, 7, valor);

    if (pos != -1)
        cout << "Valor: " << valor << " encontrado na posicao: " << pos << ".\n";
    else
        cout << "Valor nao encontrado.\n";
    return 0;
}