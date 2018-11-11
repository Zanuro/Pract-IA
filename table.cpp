#ifndef TABLE_CPP
#define TABLE_CPP
#include <cmath>

//using namespace IA;

void table::set_car(int x, int y){
    coche->set_x(x);
    coche->set_y(y);
}

void table::set_final(int x,int y, int z){
	if(z < 0){
		celda[final.first][final.second].second = 0;
		final.first = x;
		final.second = y;
	}
	celda[x][y].second=z;
}

std::ostream& table::write(std::ostream& os) {
    for(int i=0;i<num_row;i++){
		for(int j=0;j<num_col;j++){
		    if((coche->get_x()==i)&&(coche->get_y()==j)){
		        std::cout << coche->get_color() << ' ';
		    }else{
				celda[j][i].write(os);
		    }
	    }
	std::cout << endl; 
    }
    //coche->move();
	return os;
}
#endif