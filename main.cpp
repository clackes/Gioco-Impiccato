#include "GeneraParola.h"
#include "Impiccato.h"

string CYAN = "\033[36m";
string GREEN = "\033[32m";
string YELLOW = "\033[33m";
string BLUE = "\033[34m";
string PURPLE = "\033[35m";
string RESET = "\033[0m";

using namespace std;

void livellouno(GeneraParola p, Impiccato I) {
  p.Generatore();                   
                                    
  if (I.livelloFacile(p) == true) { 
                                    
    GeneraParola p(true);           
                                    
    p.Generatore();                 
    p.visualizza();
    cout << p.nascondiparola(p.parola) << endl;
    if (I.livelloFacile(p) !=
        true) { 
      p.visualizza();
    }
  } else {
    p.visualizza();
  }
}

int main() {

  while (true) {

    GeneraParola p(false); 
    p.printASCII();        

    Impiccato I; 
    int scelta;
    do {
      cout << R"(
                              Scegli il livello di difficoltà: 
                                    1: Livello Standard            
                                    2: Livello PvP
        )" << endl; 
      cin >> scelta;
    } while (scelta != 1 && scelta != 2);
    switch (scelta) {
    case 1:
      (void)system("clear"); 

      livellouno(p, I); 
      break;
    case 2:
      (void)system("clear");
      p.printASCII();
      I.pvp(); 
      break;
    default:
      p.visualizza();
      break;
    }
  }
  return 0;
}
