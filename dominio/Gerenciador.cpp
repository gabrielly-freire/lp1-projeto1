#include "Gerenciador.h"
// 1 - planejado; 2 - em curso; 3 - finalizado; 4 - explodiu;

void Gerenciador::cadastrarAstronauta(std::string cpf, std::string nome, int idade){
    if(checarCpf(cpf)){
        Astronauta *astronauta = new Astronauta(cpf, nome, idade);
        astronautas.push_back(astronauta);
    }else{
        std::cout << "Astronauta já cadastrado em nossa base de dados." << std::endl;
    }
}

void Gerenciador::cadastrarVoo(int codigo){
    if(checarCodigo(codigo)){
        Voo *voo = new Voo(codigo);
        voos.push_back(voo);
    }else{
        std::cout << "Voo já cadastrado em nossa base de dados." << std::endl;
    }
}

void Gerenciador::adicionarAstronautaEmVoo(std::string cpf, int codigoVoo){
    Voo *voo = encontrarVoo(codigoVoo);
    Astronauta *astronauta = encontrarAstronauta(cpf);

    if(!astronauta){
        std::cout << "Astronauta não encontrado em nossa base de dados." << std::endl;
        return;
    } else if(!voo){
        std::cout << "Voo não encontrado em nossa base de dados." << std::endl;
        return;
    } else if(!astronauta->isVivo()){
        std::cout << "Este astronauta não pode entrar no voo." << std::endl;
        return;
    } else if(voo->getStatus() != 1){
        std::cout << "Esta operação só pode ser realizada durante a fase de planejamento." << std::endl;
        return;
    } else if(!podeAdicionarAstronauta(cpf, codigoVoo)){
        std::cout << "Este astronauta já está no voo." << std::endl;
        return;
    } else {
        voo->adicionarPassageiro(astronauta);
        std::cout << "Astronauta adicionado com sucesso ao voo." << std::endl;
    }
}

void Gerenciador::removerAstronautaDeVoo(std::string cpf, int codigoVoo){
    Voo *voo = encontrarVoo(codigoVoo);
    Astronauta *astronauta = encontrarAstronauta(cpf);

    if(!astronauta){
        std::cout << "Astronauta não encontrado em nossa base de dados." << std::endl;
        return;
    } else if(!voo){
        std::cout << "Voo não encontrado em nossa base de dados." << std::endl;
        return;
    }else if(voo->getStatus() != 1){
        std::cout << "Esta operação só pode ser realizada durante a fase de planejamento." << std::endl;
        return;
    }else if(!podeRemoverAstronauta(cpf, codigoVoo)){
        std::cout << "Astronauta não está no voo." << std::endl;
        return;
    } else {
        voo->removerPassageiro(astronauta);
        std::cout << "Astronauta removido do voo com sucesso." << std::endl;
    }
}

void Gerenciador::lancarVoo(int codigoVoo){
    Voo *voo = encontrarVoo(codigoVoo);

    if(!voo){
        std::cout << "Voo não encontrado em nossa base de dados." << std::endl;
        return;
    } else if(voo->getPassageiros().empty()){
        std::cout << "Impossível lançar o voo sem ao menos um astronauta. Por favor, adicione pelo menos um astronauta." << std::endl;
        return;
    } else if(!podeLancarVoo(codigoVoo)){
        std::cout << "Não é possível lançar o voo, pois há tripulantes em outro voo no momento." << std::endl;
        return;
    } else if(voo->getStatus() != 1){
        std::cout << "Não é possível lançar o voo, pois ele não está em planejamento" << std::endl;
        return;
    } else {
        voo->setStatus(2);
        for (Astronauta *astronauta : voo->getPassageiros()){
            astronauta->tornarIndisponivel();
        }
        std::cout << "Voo lançado com sucesso!" << std::endl;
    }
}

void Gerenciador::explodirVoo(int codigoVoo){
    Voo *voo = encontrarVoo(codigoVoo);

    if(!voo){
        std::cout << "Voo não encontrado em nossa base de dados." << std::endl;
        return;
    } else if(voo->getStatus() != 2){
        std::cout << "Esta operação só pode ser realizada quando o voo estiver em curso." << std::endl;
        return;
    } else {
        voo->setStatus(4);
        for (Astronauta *astronauta : voo->getPassageiros()){
            astronauta->tornarIndisponivel();
            astronauta->morrer();
        }   

        for(Voo *voo : voos){
            for (Astronauta *astronauta : voo->getPassageiros()){
                if(!astronauta->isVivo()){
                    removerAstronautaDeVoo(astronauta->getCpf(), voo->getCodigo());
                }
            }  
        }
        
        std::cout << "Voo explodiu" << std::endl;
    }
}

void Gerenciador::finalizarVoo(int codigoVoo){
    Voo *voo = encontrarVoo(codigoVoo);

    if(!voo){
        std::cout << "Voo não encontrado em nossa base de dados." << std::endl;
        return;
    } else if(voo->getStatus() != 2){
        std::cout << "Esta operação só pode ser realizada quando o voo estiver em curso." << std::endl;
        return;
    } else {
        voo->setStatus(3);
        for (Astronauta *astronauta : voo->getPassageiros()){
            astronauta->tornarDisponivel();
        }   
        std::cout << "Voo finalizado com sucesso!" << std::endl;
    }
}

void Gerenciador::listarTodosVoos(){
    if(voos.empty()){
        std::cout << "Nãp temos registro de voos na nossa base de dados.." << std::endl;
    } else {
        for(Voo *voo : voos){
            std::cout << voo->toString();
        }
    }
}

void Gerenciador::listarAstronautasMortos(){
    bool naoTemMortos = true;
    for (Astronauta *astronauta : astronautas){
        if(!astronauta->isVivo()){
            std::cout << astronauta->toString() + ", Voos participados: ";
            for (Voo *voo : voos){
                for (Astronauta *a: voo->getPassageiros()){
                    if(astronauta->getCpf() == a->getCpf()){
                        std::cout << voo->toStringVoo();
                        naoTemMortos = false;
                    }
                }
            }
        }
    }
    if(naoTemMortos){
        std::cout << "Não temos registros de astronautas mortos nossa base de dados." << std::endl;
    }
}

// metodos auxiliares
Astronauta* Gerenciador::encontrarAstronauta(std::string cpf){
    for (Astronauta *astronauta : astronautas){
        if(astronauta->getCpf() == cpf){
            return astronauta;
        }
    }
    return nullptr;
}

Voo* Gerenciador::encontrarVoo(int codigoVoo){
    for (Voo *voo : voos){
        if (voo->getCodigo() == codigoVoo){
            return voo;
        }
    }
    return nullptr;
}

bool Gerenciador::podeLancarVoo(int codigoVoo){
    Voo *voo = encontrarVoo(codigoVoo);
    for(Astronauta *astronauta : voo->getPassageiros()){
        if(!astronauta->isDisponivel()){
            return false;
        }
    }
    return true;
}

bool Gerenciador::checarCpf(std::string cpf){
    for(Astronauta *astronauta : astronautas){
        if(cpf == astronauta->getCpf()){
            return false;
        }
    }
    return true;    
}

bool Gerenciador::checarCodigo(int codigo){
    for(Voo *voo : voos){
        if(codigo == voo->getCodigo()){
            return false;
        }
    }
    return true;    
}

bool Gerenciador::podeAdicionarAstronauta(std::string cpf, int codigo){
    Voo *voo = encontrarVoo(codigo);
    for (Astronauta *a: voo->getPassageiros()){
        if(a->getCpf() == cpf){
            return false;
        }
    }
    return true;
}

bool Gerenciador::podeRemoverAstronauta(std::string cpf, int codigo){
    Voo *voo = encontrarVoo(codigo);
    for (Astronauta *a: voo->getPassageiros()){
        if(a->getCpf() == cpf){
            return true;
        }
    }
    return false;
}