#ifndef COCHE_HPP
#define COCHE_HPP
#include <utility>
#include <set>
//#include "point.hpp" ya declarado

enum class Direction{
    north,
    south,
    west,
    east
};

namespace IA {

typedef struct grid Grid;
struct comparate;

//using x_coordinate = int; PORQUE?!?!?!?
//using y_coordinate = int;

using coordinates = std::pair<int,int>;//<x_coordinate,y_coordinate>;//PORQUEEEEEEEEEEEEEE

const coordinates movement[] = {coordinates(1,0),coordinates(0,-1),coordinates(-1,0),coordinates(0,1)};


class car{
    protected:
        /*Direction direction;
        coordinates position;*/
    private:
        int x_coordinate;
        int y_coordinate;
        int number_clients;
        char color = 'C';
    public:
        class table;
    private:
        table* map;//Esto sera usado para interaccionar con la clase table
    public:
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
    
        const int get_number_of_clients(void) const {return number_clients;}
    
        void set_x(int x){
            x_coordinate=x;
        }  //POSIBLES INLINE
        void set_y(int y){
            y_coordinate=y;
        }
        void set_number_clients(int clients){
            number_clients = clients;
        }
        void move_up(){
            set_y(get_y()+1);
        }
        void move_down(){
            set_y(get_y()-1);
        }
        void move_left(){
            set_x(get_x()-1);
        }
        void move_right(){
            set_x(get_x()+1);
        }
        
        //Branch Miguel
        inline void add_clients(int passengers){
            number_clients += passengers;
        }
        inline void set_tablero(table* grid){map = grid;}
        void move();//Implementar backtracking y traza
        inline char get_color(){return color;}
        

};

}



#endif // COCHE_HPP
