#include <iostream>
using namespace std;

// Equipe Master Plus Ultra Top
// Integrantes:
// Ana Sofia da Silva
// Camila Maria Teixeira
// Lucas Rodrigues
// Victor Ferreira
// René Lucena

int buscaBinaria(int vetor[], int tamanho, int valor) {
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        if (vetor[meio] == valor){
            return meio;
    } else if (vetor[meio] < valor) {
        inicio = meio + 1;
    } else {
        fim = meio - 1;
    }
  }

    return -1;
}

void acharRedondezas(int vetor[], int tamanho, int valor){

    int anterior, proximo;

    for(int i = 0; i < tamanho; i++){

        if(vetor[i] < valor && vetor[i+1] > valor){
            anterior = vetor[i];
            proximo = vetor[i+1];

            cout << "Valor: "<< valor << " nao encontrado." << endl;
            cout << "Anterior: " << anterior << endl;
            cout << "Proximo: " << proximo << endl;
    } else if (vetor[0] > valor){
        proximo = vetor[0];

        cout << "Valor: "<< valor << " nao encontrado." << endl;
        cout << "Anterior: não existe anterior" << endl;
        cout << "Proximo: " << proximo << endl;
        break;
    } else if (vetor[tamanho-1] < valor){
        anterior = vetor[tamanho-1];

        cout << "Valor: "<< valor << " nao encontrado." << endl;
        cout << "Anterior: " << anterior << endl;
        cout << "Proximo: não existe posterior" << endl;
        break;
    }

  }
  
}

int main() {
    int vetor[] = {4,5,6,8,9,10};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int valor;

    cout << "Digite um valor para buscar: ";
    cin >> valor;

    int resultado = buscaBinaria(vetor, tamanho, valor);

    if (resultado != -1) {
        cout << "Valor " << valor << " encontrado no indice " << resultado << "." << endl;
  } else {
    acharRedondezas(vetor, tamanho, valor);
  }

    return 0;
}