#ifndef POINT_HPP
#define POINT_HPP
#pragma once

#include <utility> //pair
#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>

using namespace std;

namespace IA{

class point: public pair<bool,int>
{
    private:
    //Branch Miguel
        char color_;
    public:
        point(void):
            pair(0,0) {}
    
        point(bool accesible, int personas):
            pair(accesible, personas) {}
    
        virtual ~point(void) {}
    
        void write(ostream& os) const//Diria de usar esto como un log de cada iteracion
        {
            if(first){//funciona si se usa el log a la hora de rastrear y no solo cuando se avanza
                os << "No se puede acceder";
            }
            os << "Persona recojidas: " << second;
        }
    
        // void read(istream& is)
        // {
        //     is >> first >> second;
        // }
    
        // inline const double get_x(void) const {return first;}
        // inline const double get_y(void) const {return first;}
    
    //Habria que ver si se implementa la funcion distancia y se se hace, el como.
        // inline double distance(const point& punt)
        // {
        //     return round(sqrt(pow((first-punt.first),2) + pow((second - punt.second),2)));
    
        // }
        
        //Branch Miguel
        inline char get_color(){return color_;}

};

}


// istream& operator>>(istream& is, IA::point& a);

// ostream& operator<<(ostream& os, const IA::point& a);



#endif // POINT_HPP
