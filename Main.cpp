#include <iostream>
#include "dominio/Gerenciador.h"

using namespace std;

void menu();
#define INFORME_CPF std::cout << "Informe o CPF do astronauta: ";
#define INFORME_NOME std::cout << "Informe o nome do astronauta: ";
#define INFORME_IDADE std::cout << "Informe a idade do astronauta: ";
#define INFORME_CODIGO std::cout << "Informe o código do voo: ";

int main() {
    Gerenciador gerenciador;

    int opcao;

    std::string cpf;
    std::string nome;
    int idade;
    
    int codigo;

    do {
        menu();
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                INFORME_CPF;
                std::cin >> cpf;
                INFORME_NOME;
                std::cin >> nome;
                INFORME_IDADE;
                std::cin >> idade;

                gerenciador.cadastrarAstronauta(cpf, nome, idade);

                break;
            case 2:
                INFORME_CODIGO;
                std::cin >> codigo;

                gerenciador.cadastrarVoo(codigo);

                break;
            case 3:
                INFORME_CPF;
                std::cin >> cpf;
                INFORME_CODIGO;
                std::cin >> codigo;

                gerenciador.adicionarAstronautaEmVoo(cpf, codigo);

                break;
            case 4:
                INFORME_CPF;
                std::cin >> cpf;
                INFORME_CODIGO;
                std::cin >> codigo;

                gerenciador.removerAstronautaDeVoo(cpf, codigo);

                break;
            case 5:
                INFORME_CODIGO;
                std::cin >> codigo;

                gerenciador.lancarVoo(codigo);

                break;
            case 6:
                INFORME_CODIGO;
                std::cin >> codigo;

                gerenciador.explodirVoo(codigo);

                break;
            case 7:
                INFORME_CODIGO;
                std::cin >> codigo;

                gerenciador.finalizarVoo(codigo);

                break;
            case 8:
                gerenciador.listarTodosVoos();

                break;
            case 9:
                gerenciador.listarAstronautasMortos();

                break;
            case 0:
            std::cout << "Obrigado por utilizar nosso sistema de gerenciamento de voos." << std::endl;                break;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
        }
    } while (opcao != 0);

    return 0;
}

void menu(){
    std::cout << "======================MENU==========================" << std::endl;
    std::cout << "1 - Cadastrar Astronauta" << std::endl;
    std::cout << "2 - Cadastrar Voo" << std::endl;
    std::cout << "3 - Adicionar Astronauta em Voo" << std::endl;
    std::cout << "4 - Remover Astronauta de um Voo" << std::endl;
    std::cout << "5 - Lançar um voo" << std::endl;
    std::cout << "6 - Explodir Voo" << std::endl;
    std::cout << "7 - Finalizar um voo" << std::endl;
    std::cout << "8 - Listar todos os voos" << std::endl;
    std::cout << "9 - Listar todos os astronautas mortos" << std::endl;
    std::cout << "0 - Sair" << std::endl;
    std::cout << "Digite a opção desejada" << std::endl;
}