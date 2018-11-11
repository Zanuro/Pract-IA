#ifndef TABLE_HPP
#define TABLE_HPP
#pragma once
#include "point.hpp"
#include "coche.hpp"


//namespace IA{

class table{ //public car no hace falta w/line 19
private:
    int num_col;
    int num_row;
    int n_obstacle;
    int n_pers;
    int pers_density;
    ::point** celda;
    ::car* coche;

public:
    std::pair <int,int> final;
    
    table(int x, int y, car* carro):
        num_col(x),
        num_row(y),
        coche(carro)
        {
            carro->set_tablero(this);
            final = std::pair<int, int>(x/2, y/2);
            celda = new point*[x];//rowCount
            for(int i = 0; i < x; ++i){//rowCount
                celda[i] = new point[y];}//colCount
           // casilla=new celda[b][c]; <- Basicamente
           celda[x/2][y/2].second=-1;
           for(int i=0;i<num_row;i++){
        		for(int j=0;j<num_col;j++){
        		    celda[j][i].x = j;
        		    celda[j][i].y = i;
        	    }
            }
        };
    table(ifstream &tablero, car* carro):
        coche(carro)
        {
            std::string str;
            getline(tablero, str, ' ');
            num_col = std::stoi(str);
            getline(tablero, str, '\n');
            num_row = std::stoi(str);
            
            carro->set_tablero(this);
            celda = new point*[num_row];//rowCount
            for(int i = 0; i < num_row; ++i){//rowCount
                celda[i] = new point[num_col];}//colCount
            // casilla=new celda[b][c]; <- Basicamente
            for(int i=0;i<num_row;i++){
        		for(int j=0;j<num_col;j++){
        		    celda[j][i].x = j;
        		    celda[j][i].y = i;
        	    }
            }
            int i = 0;
            int j = 0;
            while(!tablero.eof()) // To get you all the lines.
            {
	            getline(tablero, str, '\n');
	            for(char& c : str) {
    	            if(c == 'F')set_final(j, i, -1);
            		else if(c == '_')celda[j][i].second = 0;
            		else if(c == 'X')celda[j][i].first = 1;
            		else if(c == 'P'){
            		    int w = 0;
            		    std::cout << "Introduzca el numero de personas en (" << j << "," << i << ")";
            		    std::cin >> w;
            		    celda[j][i].second = w;
            		}
            		if(++i == num_col)i++;
                }
                i=0;
                j++;
            }
            tablero.close();
        };
        
    const int get_col() const{return num_col;}
    const int get_row() const{return num_row;}
    // void set_col(int col_){num_col=col_;}
    // void set_row(int row_){num_row=row_;}
    // const int get_pos(int i,int j);
    // const int get_val() const;
   // void set_percentage(int per_){perc_density=per_;}
    
    void set_pers(int person); //Nose cual es la movida con n_pers y pers_density
    void set_car(int x, int y); //Mueve coche
    void set_final(int x,int y, int z);
    inline void set_obstacle(int x,int y, bool z){celda[x][y].first=z;}
    
    inline char get_color(int x,int y){return celda[x][y].get_color();}
    void obstaculos_random();
    void pasajeros_random();
    void coche_random();
    void meta_random();
    std::ostream& write(std::ostream& os);
    inline double distance(int x, int y)
    {
        return sqrt(pow((final.first-x),2) + pow((final.second - y),2));
    }
    inline point* get_point(int x, int y){return &celda[x][y];}

};

//}
#include "table.cpp"
#include "node.cpp"
#include "coche.cpp"
#endif // TABLE_HPP
