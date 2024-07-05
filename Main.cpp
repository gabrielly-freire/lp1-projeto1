#include <iostream>
#include "dominio/Gerenciador.h"
#include "util/util.h"

using namespace std;

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
        std::cin.ignore();

        switch (opcao) {
            case 1:
                std::cout << "=================CADASTRAR ASTRONAUTA=================" << std::endl;    
                INFORME_CPF;
                std::getline(std::cin, cpf);
                INFORME_NOME;
                std::getline(std::cin, nome);
                INFORME_IDADE;
                std::cin >> idade;
                std::cin.ignore();

                gerenciador.cadastrarAstronauta(cpf, nome, idade);

                break;
            case 2:
                std::cout << "====================CADASTRAR VOO=====================" << std::endl;
                INFORME_CODIGO;
                std::cin >> codigo;
                std::cin.ignore();

                gerenciador.cadastrarVoo(codigo);

                break;
            case 3:
                std::cout << "==============ADICIONAR ASTRONAUTA A VOO===============" << std::endl;
                INFORME_CPF;
                std::getline(std::cin, cpf);
                INFORME_CODIGO;
                std::cin >> codigo;
                std::cin.ignore();

                gerenciador.adicionarAstronautaEmVoo(cpf, codigo);

                break;
            case 4:
                std::cout << "=================REMOVER ASTRONAUTA DE VOO================" << std::endl;
                INFORME_CPF;
                std::getline(std::cin, cpf);
                INFORME_CODIGO;
                std::cin >> codigo;
                std::cin.ignore();

                gerenciador.removerAstronautaDeVoo(cpf, codigo);

                break;
            case 5:
                std::cout << "====================LANÇAMENTO DE VOO===================" << std::endl;
                INFORME_CODIGO;
                std::cin >> codigo;
                std::cin.ignore();

                gerenciador.lancarVoo(codigo);

                break;
            case 6:
                std::cout << "======================EXPLODIR VOO=====================" << std::endl;
                INFORME_CODIGO;
                std::cin >> codigo;
                std::cin.ignore();

                gerenciador.explodirVoo(codigo);

                break;
            case 7:
                std::cout << "======================FINALIZAR VOO=====================" << std::endl;
                INFORME_CODIGO;
                std::cin >> codigo;
                std::cin.ignore();

                gerenciador.finalizarVoo(codigo);

                break;
            case 8:
                std::cout << "=================LISTAR VOOS=====================" << std::endl;
                gerenciador.listarTodosVoos();

                break;
            case 9:
                std::cout << "=================ASTRONAUTAS MORTOS===================" << std::endl;
                gerenciador.listarAstronautasMortos();

                break;
            case 0:
                std::cout << "Obrigado por utilizar nosso sistema de gerenciamento de voos." << std::endl;
                break;
            default:
                std::cout << "Opção inválida. Tente novamente." << std::endl;
        }
    } while (opcao != 0);

    return 0;
}
