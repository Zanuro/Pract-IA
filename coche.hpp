#ifndef COCHE_HPP
#define COCHE_HPP
#pragma once
#include <utility> //pair
#include <set>

class table;
//namespace IA {

class car{
    public:
    private:
        int x_coordinate;
        int y_coordinate;
        int number_clients;
        char color = 'C';
        unsigned int acc = 0;
        
    public:
        ::table* map;//Esto sera usado para interaccionar con la clase table
        car(void):
            x_coordinate(0),
            y_coordinate(0),
            number_clients(0){}
    
        car(int primera,int segunda):
            x_coordinate(primera),
            y_coordinate(segunda),
            number_clients(0){}
    
        virtual ~car() = default;
    
        int get_x(void) {return x_coordinate;}
        int get_y(void) {return y_coordinate;}
        inline char get_color(){return color;}
    
        inline const int get_number_of_clients(void) const {return number_clients;}
    
        inline void set_x(int x){
            x_coordinate=x;
        } 
        inline void set_y(int y){
            y_coordinate=y;
        }
        inline void set_number_clients(int clients){
            number_clients = clients;
        }
        
        inline void add_clients(int passengers){
            number_clients += passengers;
        }
        inline void set_tablero(::table* grid){map = grid;}
        void move_Astar();
        void move_rect();
        void move_lvlalg();
        

};

//}
#endif // COCHE_HPP
