#ifndef TABLE_CPP
#define TABLE_CPP
#include <cmath>
#include <chrono>

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
	std::cout << "Tamaño " << num_row << "x" << num_col << std::endl;
	std::cout << "Obstaculos " << obstacles/(num_row*num_col)*100 << "%" << std::endl;
    for(int i=0;i<num_row;i++){
		for(int j=0;j<num_col;j++){
		    if((coche->get_x()==i)&&(coche->get_y()==j)){
		        std::cout << coche->get_color() << ' ';
		    }else{
				celda[i][j].write(os);
		    }
	    }
	std::cout << endl; 
    }
    cout << "\n-----------------------" << endl;
    auto start = std::chrono::high_resolution_clock::now(); 
    coche->move_Astar();
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "Elapsed time: " << duration.count() << " microseconds(10^-9)" << endl;
    
    cout << "\n-----------------------" << endl;
    
    start = std::chrono::high_resolution_clock::now();
    coche->move_lvlalg();
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "Elapsed time: " << duration.count() << " microseconds(10^-9)" << endl;
	return os;
}
#endif