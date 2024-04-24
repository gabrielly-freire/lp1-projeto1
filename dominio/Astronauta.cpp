#include "Astronauta.h"

// Construtor
Astronauta::Astronauta(std::string cpf, std::string nome, int idade) {
    this->cpf = cpf;
    this->nome = nome;
    this->idade = idade;
    this->vivo = true; 
    this->disponivel = true; 
}

// Getters
std::string Astronauta::getCpf() {
    return cpf;
}

std::string Astronauta::getNome() {
    return nome;
}

int Astronauta::getIdade() {
    return idade;
}

bool Astronauta::isVivo() {
    return vivo;
}


bool Astronauta::isDisponivel() {
    return disponivel;
}

void Astronauta::tornarDisponivel() {
    disponivel = true;
}

void Astronauta::tornarIndisponivel() {
    disponivel = false;
}

void Astronauta::morrer() {
    vivo = false;
}

std::string Astronauta::toString() {
    std::string isVivo = vivo ? "sim" : "não"; 
    std::string isDisponivel = disponivel ? "sim" : "não";

    return "Nome: " + nome + ", CPF: " + cpf + ", Idade: " + std::to_string(idade) + ", Vivo: " + isVivo + ", Disponível: " + isDisponivel + " ";
}

// std::string Astronauta::toString() {
//     std::string isVivo = vivo ? "sim" : "não"; 
//     std::string isDisponivel = disponivel ? "sim" : "não";

//     return "Nome: " + nome + ", CPF: " + cpf + " ";
// }
