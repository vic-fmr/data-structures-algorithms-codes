#include <iostream>

using namespace std;

int produto_iterativo(int a, int b) {
    int resultado = 0;
    
    if (a == 0 || b == 0) {
        return 0;
    }

    bool resultado_negativo = (a < 0) ^ (b < 0);

    int multiplicando = a;
    int contador = b;

    if (a < 0) {
        multiplicando = -a;
    }
    if (b < 0) {
        contador = -b;
    }

    for (int i = 0; i < contador; ++i) {
        resultado += multiplicando;
    }

    if (resultado_negativo) {
        resultado = -resultado;
    }

    return resultado;
}

int main() {
    int a, b;
    cout << "Digite dois inteiros: ";
    cin >> a >> b;
    cout << "Produto Iterativo: " << produto_iterativo(a, b) << endl;
    return 0;
}