#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib> 

using namespace std;

struct Cliente {
    int id;
    string nome;
    Cliente* prox;
    Cliente(int i, const string& n) : id(i), nome(n), prox(nullptr) {}
};

class FilaBanco {
private:
    Cliente* frente; 
    Cliente* tras;   
    int proximo_id;

public:
    FilaBanco() : frente(nullptr), tras(nullptr), proximo_id(1) {}

    ~FilaBanco() {
        while (!isEmpty()) {
            dequeue(); 
        }
    }

    bool isEmpty() const {
        return frente == nullptr;
    }

    void enqueue(const string& nome) {
        Cliente* novoCliente = new Cliente(proximo_id++, nome);
        
        cout << "[CHEGADA] Cliente ID " << novoCliente->id << " (" << nome << ") entrou na fila." << endl;

        if (isEmpty()) {
            frente = novoCliente;
            tras = novoCliente;
        } else {
            tras->prox = novoCliente;
            tras = novoCliente;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "[ATENDIMENTO] Fila vazia. Nenhum cliente para atender." << endl;
            return;
        }
        
        Cliente* clienteAtendido = frente;
        
        cout << "[ATENDIDO] Cliente ID " << clienteAtendido->id << " (" << clienteAtendido->nome << ") saiu da fila e foi atendido." << endl;

        frente = frente->prox;

        if (frente == nullptr) {
            tras = nullptr;
        }
        
        delete clienteAtendido;
    }

    void status() const {
        if (isEmpty()) {
            cout << "\n[STATUS] A fila esta vazia. Nao ha clientes esperando." << endl;
            return;
        }

        cout << "\n[STATUS] Clientes na fila:" << endl;
        Cliente* atual = frente;
        int posicao = 1;
        while (atual != nullptr) {
            cout << "  " << posicao << ". ID " << atual->id << " (" << atual->nome << ")";
            if (posicao == 1) {
                cout << " <- PROXIMO A SER ATENDIDO";
            }
            cout << endl;
            atual = atual->prox;
            posicao++;
        }
    }
};

int main() {
    FilaBanco fila;

    cout << "--- Simulacao de Atendimento Bancario ---" << endl;

    // 1. Chegada de clientes
    fila.enqueue("Ana");
    fila.enqueue("Bruno");
    fila.enqueue("Carlos");
    
    fila.status();

    // 2. Atendimento de dois clientes
    cout << "\n--- Iniciando Atendimentos ---" << endl;
    fila.dequeue();
    fila.dequeue();

    fila.status();

    // 3. Chegada de novo cliente enquanto ha atendimento
    cout << "\n--- Nova Chegada ---" << endl;
    fila.enqueue("Daniela");
    
    fila.status();

    // 4. Atendimento final
    cout << "\n--- Finalizando Atendimentos ---" << endl;
    fila.dequeue();
    fila.dequeue();
    
    fila.status();
    
    // 5. Tentativa de atender fila vazia
    fila.dequeue();

    return 0;
}