#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Paciente{
    string nome;
    int idade;
    string diagnostico;
};

vector<Paciente> pacientes = {
    {"João Silva", 45, "Hipertensão"},
    {"Maria Oliveira", 62, "Diabetes"},
    {"Carlos Souza", 70, "Artrite"},
    {"Ana Lima", 29, "Gripe"},
    {"Pedro Santos", 80, "Alzheimer"},
    {"Beatriz Costa", 55, "Asma"},
    {"Luiz Pereira", 67, "Cardiopatia"},
    {"Fernanda Alves", 34, "Sinusite"},
    {"Rafael Mendes", 73, "Parkinson"},
    {"Sofia Martins", 22, "Alergia"}
};

void filtrarPacientes(vector<Paciente>& pacientes){
    for(const auto& p : pacientes){
        if(p.idade > 60){
            cout << "Nome: " << p.nome << "| Idade: " << p.idade << "| Diagnóstico: " << p.diagnostico << endl;
        }
    }
}

int main() {
    filtrarPacientes(pacientes);
    return 0;
}
