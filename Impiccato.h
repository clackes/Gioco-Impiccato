#ifndef IMPICCATO_H
#define IMPICCATO_H

#include "GeneraParola.h"
#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

class Impiccato {
public:
  Impiccato();

  bool livelloFacile(GeneraParola p); 
  bool pvp();                         
  bool Gioco(string indovina,
             GeneraParola p);    
  void disegnaOmino(int errori); 
};

#endif
