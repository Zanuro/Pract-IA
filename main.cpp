#include <iostream>

using namespace std;

int main()
{
    car* coche;
    table mapa(100,100);//tamaño mapa
    mapa.set_car(coche);
    mapa.write();//inicio simulación o iteración
    cout<<"Buenos dias."<<endl;
    return 0;
}
