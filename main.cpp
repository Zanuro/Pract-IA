#include <iostream>
#include "table.hpp"

using namespace std;
//int dim=100;
int main()
{
    int inputx, inputy, inputz;
    string opc;
    
    cout << "Introduzca el tamaño del tablero:\nx->";
    cin >> inputx;
    cout << "y->";
    cin >> inputy;
    
    IA::table* mapa = new table(inputx,inputy);//tamaño mapa
    IA::car* coche;
    (*mapa).set_car(0,0,mapa);
    
    bool stay = true;
    
    while(stay){
    cout << "Escoja una opción:\nchange->cambia el valor de una casilla\nbool->crea o destrulle un obstaculo\niter->mostrar mapa\nquit->Terminar" << endl;
    cin >> opc;
      if (opc == "change"){
          cin >> inputx >> inputy >> inputz;
          mapa->set_final(inputx, inputy, inputz);
        }
      else if (opc == "bool"){
          cin >> inputx >> inputy >> stay;
          mapa->set_obstacle(inputx, inputy, (bool)stay);
          stay = true;
        }
      else if (opc == "iter"){
          mapa->write(cout);//inicio simulación o iteración
        }
      else if (opc == "quit"){
          stay = false;
        }
    }
    return 0;
}
