 #ifndef VOO_H
 #define VOO_H

 #include <iostream>
 #include <vector>
 #include "Astronauta.h"

 class Voo{
 private:
    int codigo;
    int status; // 1 - planejado; 2 - em curso; 3 - finalizado; 4 - explodiu;
    std::vector<Astronauta*> passageiros;
   
 public:
    
   Voo(int codigo);

   int getCodigo();
   int getStatus();
   std::vector<Astronauta*> getPassageiros();

   void setStatus(int status);

   void adicionarPassageiro(Astronauta* astronauta);
   void removerPassageiro(Astronauta* astronauta);

   std::string toString();
   std::string toStringVoo();

};

 #endif