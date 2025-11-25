#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class Fila {
private:
    vector<int> dados;

public:
    void enqueue(int valor) {
        dados.push_back(valor);
    }

    int dequeue() {
        if (isEmpty()) {
            throw runtime_error("Erro: A fila esta vazia. Nao e possivel remover.");
        }
        
        int elemento = dados.front(); 
        
        dados.erase(dados.begin());
        
        return elemento;
    }

    int front() const {
        if (isEmpty()) {
            throw runtime_error("Erro: A fila esta vazia. Nao ha elemento na frente.");
        }
        return dados.front();
    }

    bool isEmpty() const {
        return dados.empty();
    }
};

int main() {
    Fila fila;

    cout << "A fila esta vazia? " << (fila.isEmpty() ? "Sim" : "Nao") << endl;

    cout << "--- Enqueue (Inserindo) ---" << endl;
    fila.enqueue(10);
    cout << "Inserido: 10" << endl;
    fila.enqueue(20);
    cout << "Inserido: 20" << endl;
    fila.enqueue(30);
    cout << "Inserido: 30" << endl;
    
    cout << "Primeiro elemento (Front): " << fila.front() << endl;
    
    cout << "\n--- Dequeue (Removendo) ---" << endl;
    try {
        cout << "Removido: " << fila.dequeue() << endl;
        cout << "Removido: " << fila.dequeue() << endl;
        
        cout << "Primeiro elemento (Front) apos remocao: " << fila.front() << endl;
        
        cout << "A fila esta vazia? " << (fila.isEmpty() ? "Sim" : "Nao") << endl;
        
        cout << "Removido: " << fila.dequeue() << endl;
        
        cout << "A fila esta vazia? " << (fila.isEmpty() ? "Sim" : "Nao") << endl;

        cout << "Tentando remover de uma fila vazia..." << endl;
        fila.dequeue(); 

    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
    }

    return 0;
}