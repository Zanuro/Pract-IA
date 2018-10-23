//#include "table.hpp"

using namespace IA;

void table::set_car(int x, int y,table* clase){
    coche->set_x(x);
    coche->set_y(y);
    //auto clase = this;//this=> * const
    coche->set_tablero((IA::car::table*)clase);
}

std::ostream& table::write(std::ostream& os) {
    for(int i=0;i<num_col;i++){
		for(int j=0;j<num_row;j++){
		    if((coche->get_x()==i)&&(coche->get_y()==j)){
		        std::cout << coche->get_color() << ' ';
		    }else{
				celda[i][j].write(os);
		    }
	    }
	std::cout << endl; 
    }
    //coche.move(); A implementar
	return os;
}