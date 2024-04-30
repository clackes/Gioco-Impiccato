#ifndef GENERAPAROLA_H
#define GENERAPAROLA_H
#include <fstream>
#include <iostream>
#include <string>
#include <time.h>
#include <unistd.h>

using namespace std;

class GeneraParola {
public:
  GeneraParola(bool p); 

  string parola; 
  string file;   
  void printASCII();
  void
  Generatore(); 
  string nascondiparola(string pParola); 
  void visualizza();
};

#endif // GENERAPAROLA_H
