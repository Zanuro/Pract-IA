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
    return os;
}

void table::meta_random()
{
    srand(time(nullptr));
    int xrando = rand();
    int yrando = rand();
    bool salida = false;
    do{
        xrando = rand() ;
        yrando = rand() ;
        int x = xrando%(num_row-1);
        int y = yrando%(num_col-1);
        if (celda[x][y].first != true)
        {
            set_final(x, y, -1);
            salida = true;
        }
    }while(!salida);
}

void table::obs_random(int iter)
{
    srand(time(nullptr));
    for(int i = 0; i<=iter; i++){
        int xrando = rand();
        int yrando = rand();
        bool salida = false;
        do{
            xrando = rand() ;
            yrando = rand() ;
            int x = xrando%(num_row-1);
            int y = yrando%(num_col-1);
            if (celda[x][y].first != true)
            {
                set_obstacle(x, y, 1);
                salida = true;
            }
        }while(!salida);
    }
}
#endif