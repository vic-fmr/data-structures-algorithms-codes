#include <iostream>
#include <stdexcept>

using namespace std;

#define MAX_SIZE 5

class FilaCircular {
private:
    int dados[MAX_SIZE];
    int frente; 
    int tras;   

public:
    FilaCircular() : frente(0), tras(0) {}

    bool isEmpty() const {
        return frente == tras;
    }

    bool isFull() const {
        return (tras + 1) % MAX_SIZE == frente;
    }

    void enqueue(int valor) {
        if (isFull()) {
            throw runtime_error("Erro: A fila circular esta cheia. Nao e possivel inserir.");
        }
        
        cout << "Enqueue: " << valor << endl;
        dados[tras] = valor;
        tras = (tras + 1) % MAX_SIZE;
    }

    int dequeue() {
        if (isEmpty()) {
            throw runtime_error("Erro: A fila circular esta vazia. Nao e possivel remover.");
        }
        
        int valor = dados[frente];
        frente = (frente + 1) % MAX_SIZE;
        
        return valor;
    }

    int front() const {
        if (isEmpty()) {
            throw runtime_error("Erro: A fila circular esta vazia. Nao ha elemento na frente.");
        }
        return dados[frente];
    }
    
    void exibir() const {
        if (isEmpty()) {
            cout << "Fila: Vazia" << endl;
            return;
        }

        cout << "Fila: ";
        int i = frente;
        
        while (i != tras) {
            cout << dados[i] << " ";
            i = (i + 1) % MAX_SIZE;
        }
        cout << "(f=" << frente << ", t=" << tras << ")" << endl;
    }
};

int main() {
    FilaCircular fila;

    try {
        cout << "--- Inserindo Elementos ---" << endl;
        fila.enqueue(10); 
        fila.enqueue(20); 
        fila.enqueue(30); 
        fila.enqueue(40); 
        
        fila.exibir();
        cout << "Primeiro elemento (Front): " << fila.front() << endl; 
        cout << "A fila esta cheia? " << (fila.isFull() ? "Sim" : "Nao") << endl;

        cout << "\n--- Removendo Elementos ---" << endl;
        cout << "Dequeue: " << fila.dequeue() << endl; 
        cout << "Dequeue: " << fila.dequeue() << endl; 

        fila.exibir();
        cout << "A fila esta cheia? " << (fila.isFull() ? "Sim" : "Nao") << endl;

        cout << "\n--- Reutilizando Espaco ---" << endl;
        fila.enqueue(50); 
        fila.enqueue(60); 

        fila.exibir();
        cout << "A fila esta cheia? " << (fila.isFull() ? "Sim" : "Nao") << endl; 
        
        cout << "\nDequeue ate esvaziar..." << endl;
        cout << "Dequeue: " << fila.dequeue() << endl; 
        cout << "Dequeue: " << fila.dequeue() << endl; 
        cout << "Dequeue: " << fila.dequeue() << endl; 
        cout << "Dequeue: " << fila.dequeue() << endl; 
        
        cout << "\nA fila esta vazia? " << (fila.isEmpty() ? "Sim" : "Nao") << endl;

    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
    }

    return 0;
}