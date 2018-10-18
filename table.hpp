#ifndef TABLE_HPP
#define TABLE_HPP
#pragma once
#include "point.hpp"
#include "coche.hpp"


namespace IA{

class table:public car{ //public car no hace falta w/line 20

    int num_col;
    int num_row;
    int n_obstacle;
    car car_;
    //Persona pers;
    int n_pers;
    int pers_density;
    point** celda;
    car coche;

public:
    const int get_col() const{return num_col;}
    const int get_row() const{return num_row;}
    void set_col(int col_){num_col=col_;}
    void set_row(int row_){num_row=row_;}
    const int get_pos(int i,int j);
    const int get_val() const;
    void set_percentage(int per_){perc_density=per_;}
    
    //Miguel branch
    table(int x,int y);
    void set_pers(int person); //Nose cual es la movida con n_pers y pers_density
    void set_car(int x, int y); //Necesario para linkear tablero y coche
    inline auto get_color(int x,int y){return point[][].get_color();}
    std::ostream& write(std::ostream& os);


};


}
#endif // TABLE_HPP
