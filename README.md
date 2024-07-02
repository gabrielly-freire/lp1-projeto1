# Gerenciador de Voos de Astronautas

O gerenciador de voos consiste em um projeto da Linguagens de Programação 1 (LP1), disciplina do currículo base do BTI, que tem o objetivo de exercitar conhecimentos básicos de Programação Orientada a Objetos (POO) e gerenciamento de memória.

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
- [x] Finalizar um voo (com sucesso)
  - Astronautas dele voltam a ficar disponíveis
- [x] Listar todos os voos (com os seus astronautas)
  - Planejados (com os astronautas)
  - Em curso (com os astronautas)
  - Finalizados (com os astronautas que estavam nele)
    - sinalizar se finalizado com sucesso ou não
- [x] Listar todos os astronautas mortos
  - cpf
  - nome
  - voos que participou

## Classes

### Astronauta

- Atributos
  - cpf (string)
  - nome (string)
  - idade (int)
- Métodos
  - Construtores
  - Getters
  - Métodos para manipulação de disponibilidade e vitalidade
  - toString para impressão dos dados

### Voo

- Atributos
  - Código do voo (int)
  - Lista de passageiros (astronautas)
  - Status (int) - 1: planejado, 2: em curso, 3: finalizado, 4: explodiu
- Métodos
  - Construtor
  - Getters e setters
  - Métodos para adicionar e remover passageiros
  - toString para impressão dos dados

### Gerenciador

- Atributos
  - Vetor de astronautas
  - Vetor de voos
- Métodos
  - Funcionalidades para cadastrar astronautas e voos
  - Adicionar e remover astronautas de voos
  - Lançar, explodir e finalizar voos
  - Listar todos os voos e astronautas mortos
  - Método auxiliares a essas ações

## Organização do projeto

```plaintext
├── projeto
│   ├── dominio
│   │   ├── Astronauta.cpp
│   │   ├── Astronauta.h
│   │   ├── Gerenciador.cpp
│   │   ├── Gerenciador.h
│   │   ├── Voo.cpp
│   │   └── Voo.h
│   ├── Main.cpp
│   ├── Makefile
│   ├── README.md
│   └── util
│       ├── util.cpp
│       └── util.h
```

## Como usar?

### 1. Compile os arquivos

```bash
make programa
```

### 2. Execute o programa

```bash
./programa
```

### 3. Explorar o projeto por meio do menu de operações

```plaintext
======================MENU=============================
1 - Cadastrar astronauta
2 - Cadastrar voo
3 - Adicionar astronauta em voo
4 - Remover astronauta de um voo
5 - Lançar um voo
6 - Explodir voo
7 - Finalizar um voo
8 - Listar todos os voos
9 - Listar todos os astronautas mortos
0 - Sair
Digite a opção desejada: 
```

#### Explicação das operações

1. Cadastrar astronauta: Informe o CPF, nome e idade para cadastrar um novo astronauta.
2. Cadastrar voo: Informe o código do voo para cadastrá-lo
3. Adicionar astronauta em voo: Informe o CPF do astronauta e o código do voo para adicioná-lo.
4. Remover astronauta de um voo: Informe o CPF do astronauta e o código do voo para removê-lo.
5. Lançar um voo: Informe o código do voo para lançá-lo (necessário ter pelo menos um astronauta disponível).
6. Explodir voo: Informe o código do voo para explodi-lo (todos os astronautas a bordo morrerão).
7. Finalizar um voo: Informe o código do voo para finalizá-lo com sucesso (astronautas a bordo voltarão a ficar disponíveis).
8. Listar todos os voos: Lista todos os voos cadastrados, com seus respectivos astronautas.
9. Listar todos os astronautas mortos: Lista todos os astronautas que morreram em voos, com detalhes dos voos que participaram.
10. Sair: Encerra o programa, mas o dados não ficam salvos.
