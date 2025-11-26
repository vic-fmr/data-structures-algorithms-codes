#include <iostream>
using namespace std;

// ------------------------------
// Aluno: Victor Ferreira Marques
// ------------------------------

int buscaSequencial(int vetor[], int tamanho, int valor) {
    int esq, dir, comp;

    for (int i = 0; i < tamanho; i++) {
        comp++;
        esq = i;
        dir = (tamanho - 1) - i;


        if (vetor[esq] == valor || vetor[dir] == valor) {

            vetor[esq] == valor 
            ? cout << "\nValor encontrado na posição: " << esq << " (pela esquerda)"
            : cout << "\nValor encontrado na posição: " << dir << " (pela direita)";

            cout << "\nTotal de comparações: " << comp * 2 << endl;
            return i; 
        }   
        
        if(esq == dir) {
            cout << "Colisão entre esquerda e direita, encerrando...\n";
            return -1;
        }
  }
    return -1;
}

int main(){
    int vetor[] = {1, 3, 5, 7, 9, 13, 15, 17, 19};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int valor;

    cout << "Digite um valor para buscar: ";
    cin >> valor;

    int resultado = buscaSequencial(vetor, tamanho, valor);

    if(resultado == -1) cout << "Valor: " << valor << " nao encontrado." << endl;
}