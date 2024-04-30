#include "GeneraParola.h"

using namespace std;

GeneraParola::GeneraParola(bool p) {
  file = "wordlistita.txt";
  if (p == true) {
    file = "wordlist.txt";
  }
}
void GeneraParola::Generatore() {
  srand(time(NULL));
  ifstream inputFile(file);  
  string line;
  string words[7776];
  int i = 0;
  while (getline(inputFile, line)) {
    words[i] = line;
    i++;
    if (i == 7776)
      break;
  };
  parola = words[rand() % 99];
  for (int i = 0; i < parola.length(); i++) {
    parola[i] = tolower(parola[i]);
  }
}

string GeneraParola::nascondiparola(string parola) {
  for (int i = 0; i < parola.length(); ++i) {
    if (parola[i] >= 'a' && parola[i] <= 'z') {
      parola[i] = '_';
    } else if (parola[i] >= 'A' && parola[i] <= 'Z') {
      parola[i] = '_';
    }
  }
  return parola;
}

void GeneraParola::visualizza() {
  cout << "La parola nascosta e': " << parola << endl;
}

void GeneraParola::printASCII() {
  cout << "\033[36m"
       << R"(

    ██╗      ██╗   ██╗███╗   ███╗██████╗ ██╗ ██████╗ ██████╗ █████╗ ████████╗ ██████╗ 
    ██║     ██╔╝   ██║████╗ ████║██╔══██╗██║██╔════╝██╔════╝██╔══██╗╚══██╔══╝██╔═══██╗
    ██║    ██╔╝    ██║██╔████╔██║██████╔╝██║██║     ██║     ███████║   ██║   ██║   ██║
    ██║    ╚═╝     ██║██║╚██╔╝██║██╔═══╝ ██║██║     ██║     ██╔══██║   ██║   ██║   ██║
    ███████╗       ██║██║ ╚═╝ ██║██║     ██║╚██████╗╚██████╗██║  ██║   ██║   ╚██████╔╝
    ╚══════╝       ╚═╝╚═╝     ╚═╝╚═╝     ╚═╝ ╚═════╝ ╚═════╝╚═╝  ╚═╝   ╚═╝    ╚═════╝ 
                                                              Credits: Vergani Alberto 
                                                                       Gaceur Nour
                                                                       Kandil Alaa 
                                                                       Zahra Somaya
                                                      
)"
       << "\033[0m" << endl;
}