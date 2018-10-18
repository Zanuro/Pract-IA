#include <iostream>

using namespace std;

int main()
{
    car* coche;
    table mapa(100,100);//tamaño mapa
    mapa.set_car(coche);
    mapa.write();//inicio simulación o iteración
    return 0;
}
