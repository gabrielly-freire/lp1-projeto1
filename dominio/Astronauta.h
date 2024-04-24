#ifndef ASTRONAUTA_H
#define ASTRONAUTA_H
#include <iostream>
#include <vector>

class Astronauta{
private:
    std::string cpf;
    std::string nome;
    int idade;
    bool vivo;
    bool disponivel;
    // std::vector<Voo*> voosParticipados;
public:
    // construtor
    Astronauta(std::string cpf, std::string nome, int idade);
 
    // getters
    std::string getCpf();
    std::string getNome();
    int getIdade();
    bool isVivo();
    bool isDisponivel();

    // metodos
    void tornarDisponivel();
    void tornarIndisponivel();
    void morrer();

    //toString
    std::string toString();
};


#endif