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

        switch (opcao) {
            case 1:
                std::cout << "=================CADASTRAR ASTRONAUTA=================" << std::endl;    
                INFORME_CPF;
                std::cin >> cpf;
                INFORME_NOME;
                std::cin >> nome;
                INFORME_IDADE;
                std::cin >> idade;

                gerenciador.cadastrarAstronauta(cpf, nome, idade);

                break;
            case 2:
                std::cout << "====================CADASTRAR VOO=====================" << std::endl;
                INFORME_CODIGO;
                std::cin >> codigo;

                gerenciador.cadastrarVoo(codigo);

                break;
            case 3:
                std::cout << "==============ADICIONAR ASTRONAUTA A VOO===============" << std::endl;
                INFORME_CPF;
                std::cin >> cpf;
                INFORME_CODIGO;
                std::cin >> codigo;

                gerenciador.adicionarAstronautaEmVoo(cpf, codigo);

                break;
            case 4:
                std::cout << "=================REMOVER ASTRONAUTA DE VOO================" << std::endl;
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
                std::cout << "=================LISTAR VOOS=====================" << std::endl;
                gerenciador.listarTodosVoos();

                break;
            case 9:
                std::cout << "=================ASTRONAUTAS MORTOS===================" << std::endl;
                gerenciador.listarAstronautasMortos();

                break;
            case 0:
                std::cout << "Obrigado por utilizar nosso sistema de gerenciamento de voos." << std::endl;                break;
            default:
                std::cout << "Opção inválida. Tente novamente." << endl;
        }
    } while (opcao != 0);

    return 0;
}