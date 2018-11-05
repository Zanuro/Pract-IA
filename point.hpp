#ifndef POINT_HPP
#define POINT_HPP
#pragma once

#include <utility> 
#include <iomanip>
#include <math.h>

using namespace std;

namespace IA{

class point: public pair<bool,int>
{
    public:
        double distance;
        unsigned int x;
        unsigned int y;
        point(void):
            pair(0,0) {}
            
        point(double inf):
            distance(inf),
            pair(0, 0) {}
            
        point(bool accesible):
            pair(accesible, 0) {}
    
        point(bool accesible, int personas):
            pair(accesible, personas) {}
            
        point(bool accesible, int personas, double dist):
            pair(accesible, personas),
            distance(dist){}
    
        virtual ~point(void) {}
    
        void write(ostream& os) const//Diria de usar esto como un log de cada iteracion
        {
            if(first){//funciona si se usa el log a la hora de rastrear y no solo cuando se avanza
                os << 'X' << ' ';
            }else if(second < 0){//final
                os << "F" << ' ';
            }else if(second == 0){//tierra normal
                os << " " << ' ';
            }else if(second > 0){//persona/s
                os << "P" << ' ';
            }
        }
        
        inline char get_color(){return 'E';}
};

}

#endif // POINT_HPP
