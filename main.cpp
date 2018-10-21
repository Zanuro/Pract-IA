#include <iostream>
#include "table.hpp"

using namespace std;
int dim=100;
int main()
{
    IA::table* mapa=new table(dim,dim);//tamaño mapa
    IA::car* coche;
    (*mapa).set_car(0,0,mapa);
    //mapa.set_car(coche);
    (*mapa).write(cout);//inicio simulación o iteración
    cout<<"Buenos dias."<<endl;
    return 0;
}
