#include <iostream>
#include "util.h"

void menu(){
    std::cout << "======================MENU=============================" << std::endl;
    std::cout << "1 - Cadastrar astronauta" << std::endl;
    std::cout << "2 - Cadastrar voo" << std::endl;
    std::cout << "3 - Adicionar astronauta em voo" << std::endl;
    std::cout << "4 - Remover astronauta de um voo" << std::endl;
    std::cout << "5 - Lançar um voo" << std::endl;
    std::cout << "6 - Explodir voo" << std::endl;
    std::cout << "7 - Finalizar um voo" << std::endl;
    std::cout << "8 - Listar todos os voos" << std::endl;
    std::cout << "9 - Listar todos os astronautas mortos" << std::endl;
    std::cout << "0 - Sair" << std::endl;
    std::cout << "Digite a opção desejada: ";
}