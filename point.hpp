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

class point: public pair<int,int>
{
public:
    point(void):
        pair<int,int>(0,0) {}

    point(int a, int b):
        pair<int,int>(a, b) {}

    virtual ~point(void) {}

    void write(ostream& os) const
    {
        os << setw(7) << fixed << first << " " << setw(7) << fixed << second;
    }

    void read(istream& is)
    {
        is >> first >> second;
    }

    inline const double get_x(void) const {return first;}
    inline const double get_y(void) const {return first;}

    inline double distance(const point& punt)
    {
        return round(sqrt(pow((first-punt.first),2) + pow((second - punt.second),2)));

    }

};

}


istream& operator>>(istream& is, IA::point& a);

ostream& operator<<(ostream& os, const IA::point& a);



#endif // POINT_HPP
