#include "table.hpp"

using namespace IA;

table::maquina(int x,int y):
num_col(x),
num_row(y)
{
    celda = new point*[y];//rowCount
        for(int i = 0; i < y; ++i)//rowCount
        celda[i] = new point[x];//colCount
   // casilla=new celda[b][c]; <- Basicamente
};

void table::set_car(int x, int y){
    coche.set_x(x);
    coche.set_y(y);
    //table* clase = this;
    coche.set_tablero(this);
}

std::ostream& table::write(std::ostream& os) {
    //cout<<"Iteración:"<<ciclo_++<<endl;
    for(int i=0;i<x_;i++){
		for(int j=0;j<y_;j++){
		    if((car.get_x()==i)&&(car.get_y()==j)){
		        std::cout<<car.get_color();
		    }else{
				std::cout << celda[i][j].get_color();
		}}
	std::cout << endl; 
    }
    car.move();
		return os;
}