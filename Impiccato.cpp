#include "Impiccato.h"
#include <vector>

using namespace std;
string RED = "\033[31m";

Impiccato::Impiccato() {}
vector<string> omino = {
    " ------- ",  "  /   \\  ", "   / \\   ",
    "  / | \\  ", "   /|\\   ", "    O    ",
};

void Impiccato::disegnaOmino(int errori) { 
  for (int i = omino.size() - 1; i >= 0; i--) {
    if (i < errori) {
      cout << " ";
    } else {
      cout << "\033[32m" << omino[i] << "\033[0m" << endl;
    }
  }
}
bool Impiccato::livelloFacile(GeneraParola p) {
  return Gioco(p.parola, p);
} 

bool Impiccato::pvp() { 

  string indovinaparola, lettera;
  GeneraParola p(false); 
  cout << "Giocatore 1:\nInserisci una parola da indovinare: " << endl;
  cin >> indovinaparola;

  for (int i = 0; i < indovinaparola.length(); i++) {
    indovinaparola[i] =
        tolower(indovinaparola[i]); 
  }
  sleep(3); 
  (void)system("clear");

  return Gioco(indovinaparola, p);
}

bool Impiccato::Gioco(string indovinaparola, GeneraParola p) 
{

  string parolanascosta = p.nascondiparola(indovinaparola), lettera;
  int tentativi = 5;
  p.printASCII();
  while (tentativi > 0) 
  {
    cout << "Inserisci una lettera: " << endl;
    cin >> lettera;

    bool trovata = false;

    for (int i = 0; i < indovinaparola.length(); i++) 
    {
      if (tolower(lettera[0]) ==
          tolower(indovinaparola[i])) 
      { 
        parolanascosta[i] = tolower(lettera[0]);
        trovata = true;
      }
    }
    (void)system("clear");
    p.printASCII();
    if (!trovata) 
    {
      tentativi--;
      cout << "Tentativi Mancanti: " << tentativi << endl;
    }
    disegnaOmino(tentativi);
    cout << "\nParola nascosta: " << parolanascosta << endl;

    if (parolanascosta == indovinaparola) {
      cout << "\033[32m"
           << R"(
                    ██╗   ██╗██╗ ██████╗████████╗ ██████╗ ██████╗ ██╗   ██╗
                    ██║   ██║██║██╔════╝╚══██╔══╝██╔═══██╗██╔══██╗╚██╗ ██╔╝
                    ██║   ██║██║██║        ██║   ██║   ██║██████╔╝ ╚████╔╝ 
                    ╚██╗ ██╔╝██║██║        ██║   ██║   ██║██╔══██╗  ╚██╔╝  
                     ╚████╔╝ ██║╚██████╗   ██║   ╚██████╔╝██║  ██║   ██║   
                      ╚═══╝  ╚═╝ ╚═════╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝   ╚═╝   
            
        
      )"
           << "\033[0m" << endl;
      sleep(3);
      (void)system("clear");
      return true;
    }
  }
  if (tentativi <= 0) {
    cout << RED << R"(
             ██████╗  █████╗ ███╗   ███╗███████╗     ██████╗ ██╗   ██╗███████╗██████╗ 
            ██╔════╝ ██╔══██╗████╗ ████║██╔════╝    ██╔═══██╗██║   ██║██╔════╝██╔══██╗
            ██║  ███╗███████║██╔████╔██║█████╗      ██║   ██║██║   ██║█████╗  ██████╔╝
            ██║   ██║██╔══██║██║╚██╔╝██║██╔══╝      ██║   ██║╚██╗ ██╔╝██╔══╝  ██╔══██╗
            ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗    ╚██████╔╝ ╚████╔╝ ███████╗██║  ██║
             ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝     ╚═════╝   ╚═══╝  ╚══════╝╚═╝  ╚═╝
    )"
         << "\033[0m" << endl;
    sleep(3);
    (void)system("clear");
    return false;
  }
  return false;
}