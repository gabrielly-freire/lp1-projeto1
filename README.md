# Gerenciador de Voos de Astronautas

O gerenciador de voos consiste em um projeto da Linguagens de Programação 1 (LP1), disciplina do currículo base do BTI, que tem o objetivo de exercitar conhecimentos básicos de Programação Orientada a Objetos (POO) e gerenciamento de memória.

## Classes

- **Astronauta**
  - Atributos
    - cpf (string)
    - nome (string)
    - idade (int)
  - Métodos
    - Construtores
    - Getters
    - Métodos para manipulação de disponibilidade e vitalidade
    - toString para impressão dos dados

- **Voo**
  - Atributos
    - Código do voo (int)
    - Lista de passageiros (astronautas)
    - Status (int) - 1: planejado, 2: em curso, 3: finalizado, 4: explodiu
  - Métodos
    - Construtor
    - Getters e setters
    - Métodos para adicionar e remover passageiros
    - toString para impressão dos dados

- **Gerenciador**
  - Atributos
    - Vetores de astronautas e voos
  - Métodos
    - Funcionalidades para cadastrar astronautas e voos
    - Adicionar e remover astronautas de voos
    - Lançar, explodir e finalizar voos
    - Listar todos os voos e astronautas mortos

## Funcionalidades

- [x] Cadastrar Astronauta
- [x] Cadastrar Voo
- [x] Adicionar Astronauta em Voo (por cpf)
  - Somente se está em planejamento
- [x] Remover Astronauta de um Voo (por cpf)
  - Somente se está em planejamento
- [x] Lançar um voo
  - Precisa que tenha pelo menos 1 astronauta e todos estarem disponíveis
  - Astronautas dele ficam indisponíveis
- [x] Explodir Voo
  - Astronautas dele morrem
- [ ] Finalizar um voo (com sucesso)
  - Astronautas dele voltam a ficar disponíveis
- [ ] Listar todos os voos (com os seus astronautas)
  - Planejados (com os astronautas)
  - Em curso (com os astronautas)
  - Finalizados (com os astronautas que estavam nele)
    - sinalizar se finalizado com sucesso ou não
- [ ] Listar todos os astronautas mortos
  - cpf
  - nome
  - voos que participou

## Organização do projeto

```plaintext
projeto
│   ├── dominio
│   │   ├── Astronauta.cpp
│   │   ├── Astronauta.h
│   │   ├── Gerenciador.cpp
│   │   ├── Gerenciador.h
│   │   ├── Voo.cpp
│   │   └── Voo.h
│   ├── Main.cpp
