#include <iostream>

using namespace std;

int buscaSequencial(int vetor[], int tamanho, int valor) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == valor)
        return i; // retorna índice se encontrado
    }
    return -1; // não encontrado
}
int buscaSequencialContador(int vetor[], int tamanho, int valor) {
    int contador = 0;
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == valor) {
            cout << "Valor: " << valor << " encontrado na posicao: " << i << ".\n";
            contador++;
        }
    }
    
    if(contador == 0) {
        return -1; // Valor não encontrado
    } else {
        return contador; // Retorna o número de ocorrências encontradas
    }
}

int main() {
    // Questão 1:
    cout << "Questão 1: \n";
    int vetor[] = {15, 8, 25, 7, 12, 18, 5, 9, 30, 3};
    int valor = 25;
    int pos = buscaSequencial(vetor, 10, valor);

    if (pos != -1)
    cout <<"Valor: " << valor << " encontrado na posicao: " << pos << ".\n";
    else
    cout << " Valor nao encontrado.\n";

    // Questão 2:
    cout << "\nQuestão 2: \n";
    int vetor2[] = {7, 3, 5, 7, 9, 2, 7, 1, 4, 6};
    int valor2 = 7;
    int quant = buscaSequencialContador(vetor2, 10, valor2);

    if(quant == -1) {
        cout << "Valor nao encontrado.\n";
    } else {
        cout << "Total de ocorrencias do valor " << valor2 << ": " << quant << ".\n";
    }

    // Questão 3
    cout << "\nQuestão 3: \n";
    int vetor3[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int valor3 = 55;
    int pos3 = buscaSequencial(vetor3, 10, valor3);

    if(pos3 == -1){
        cout << "Valor: " << valor3 << " não encontrado.";
    } else {
        cout << "Valor: " << valor3 << " encotrado na posição: " << pos3 << endl;
    }
}