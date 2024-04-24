#include "Voo.h"

// Construtor 
Voo::Voo(int codigo) {
    this->codigo = codigo;
    this->status = 1; 
}

// Getters
int Voo::getCodigo() {
    return codigo;
}

int Voo::getStatus() {
    return status;
}

std::vector<Astronauta*> Voo::getPassageiros() {
    return passageiros;
}

// Set
void Voo::setStatus(int status) {
    this->status = status;
}

void Voo::adicionarPassageiro(Astronauta* astronauta) {
    passageiros.push_back(astronauta); 
}

void Voo::removerPassageiro(Astronauta* astronauta) {
    for(int i = 0; i < passageiros.size(); i++){
        Astronauta *a = passageiros[i];
        if (a == astronauta){
            passageiros.erase(passageiros.begin() + i); // recebe o endereco
        }   
    }
}

std::string Voo::toString() {
    std::string nomeStatus;
    switch (status) {
        case 1:
            nomeStatus = "planejado";
            break;
        case 2:
            nomeStatus = "em curso";
            break;
        case 3:
            nomeStatus = "finalizado (com sucesso)";
            break;
        case 4:
            nomeStatus = "finalizado (sem sucesso)";
            break;
    }
    
    std::string textoPassageiros;

    for (int i = 0; i < passageiros.size(); i++) {
        Astronauta* astronauta = passageiros[i];
        textoPassageiros += std::to_string(i+1) + " " + astronauta->toString() + ", ";
    }

    if (!textoPassageiros.empty()) {
        textoPassageiros = textoPassageiros.substr(0, textoPassageiros.size() - 2); 
    }
    
    return "Código: " + std::to_string(codigo) + ", Status: " + nomeStatus + ", Passageiros: [" + textoPassageiros + "]\n";
}

std::string Voo::toStringVoo() {
    std::string nomeStatus;
    switch (status) {
        case 1:
            nomeStatus = "planejado";
            break;
        case 2:
            nomeStatus = "em curso";
            break;
        case 3:
            nomeStatus = "finalizado (com sucesso)";
            break;
        case 4:
            nomeStatus = "finalizado (sem sucesso)";
            break;
    }
    
    return "Código: " + std::to_string(codigo) + ", Status: " + nomeStatus + "\n";
}
