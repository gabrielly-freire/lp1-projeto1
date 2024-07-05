#ifndef GERENCIADOR_H
#define GERENCIADOR_H

#include <iostream>
#include <vector>
#include "Astronauta.h"
#include "Voo.h"

class Gerenciador {
private:
    std::vector<Astronauta*> astronautas;
    std::vector<Voo*> voos;
    // metodos auxiliares
    Astronauta* encontrarAstronauta(std::string cpf);
    Voo* encontrarVoo(int codigo);
    bool podeLancarVoo(int codigo);
    bool checarCpf(std::string cpf);
    bool checarCodigo(int codigo);
    bool podeAdicionarAstronauta(std::string cpf, int codigo);
    bool podeRemoverAstronauta(std::string cpf, int codigo);
    void removerAstronauta(std::string cpf, int codigo);
public:
    // metodos principais
    void cadastrarAstronauta(std::string cpf, std::string nome, int idade);
    void cadastrarVoo(int codigo);
    void adicionarAstronautaEmVoo(std::string cpf, int codigo);
    void removerAstronautaDeVoo(std::string cpf, int codigo);
    void lancarVoo(int codigo);
    void explodirVoo(int codigo);
    void finalizarVoo(int codigo);
    void listarTodosVoos();
    void listarAstronautasMortos();
    
};

#endif
