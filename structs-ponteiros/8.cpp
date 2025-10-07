#include <iostream>

using namespace std;

struct Retangulo{
    int base;
    int altura;

    Retangulo(int b, int a){
        base = b;
        altura = a;
    }
};

int area(Retangulo r){
    return r.altura * r.base;
}

int perimetro(Retangulo r){
    return (2 * r.altura) + (2 * r.base);
}

int main(){
    int base;
    int altura;

    cout << "Insira a base: ";
    cin >> base;
    cout << "Insira a altura: ";
    cin >> altura;

    Retangulo r(base, altura);
    cout << "Área: "<< area(r) << " | Perimetro: " << perimetro(r) << endl;

}