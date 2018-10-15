#ifndef OTHER_CPP
#define OTHER_CPP

#include <iostream>

#include "coche.hpp"

std::string IA::get_color_code(const Color& color)
{
    static std::string black 			= "\033[30m";
    static std::string white            = "\033[37m";
    static std::string red 				= "\033[31m";
    static std::string green 			= "\033[32m";
    static std::string violet          = "\033[35m";
    static std::string white_background	= "\033[1;47m";
    static std::string black_background = "\033[1;40m";
    static std::string red_background 	= "\033[1;31m";
    static std::string green_background	= "\033[1;42m";
    static std::string violet_background = "\033[1;45m]";
    static std::string reset 			= "\033[0m";

    switch (color) {
        case Color::negro   : return black_background  + ' ' + char(Color::negro)  + ' ' + reset;
        case Color::blanco  : return white_background  + ' ' + char(Color::blanco) + ' ' + reset;
        case Color::verde   : return green_background  + ' ' + char(Color::verde)  + ' ' + reset;
        case Color::magenta : return violet_background + ' ' + char(Color::magenta)+ ' ' + reset;
        case Color::red     : return red_background + ' ' + char(Color::red) + ' ' + reset;
    }
}


bool AEDA::comp::operator()(const AEDA::Cuadro& cuadro1, const AEDA::Cuadro& cuadro2)
{

    if (cuadro1.coordenadas_.first < cuadro2.coordenadas_.first)
        return true;

    else if ((cuadro1.coordenadas_.first == cuadro2.coordenadas_.first && cuadro1.coordenadas_.second < cuadro2.coordenadas_.second) || (cuadro1.coordenadas_.first < cuadro2.coordenadas_.first && cuadro1.coordenadas_.second == cuadro2.coordenadas_.second))
        return true;


  return false;

}


std::string AEDA::direction_color(const Dir& direction)
{
    static std::string black 			= "\033[30m";
    static std::string red 				= "\033[31m";
    static std::string green 			= "\033[32m";
    static std::string violet          = "\033[35m";
    static std::string white 			= "\033[37m";
    static std::string black_background = "\033[1;30m";
    static std::string red_background 	= "\033[1;41m";
    static std::string green_background = "\033[1;32m";
    static std::string violet_background = "\033[1;45m]";
    static std::string white_background = "\033[1;37m";
    static std::string reset 			= "\033[0m";

    std::string ant = green_background;
    switch (direction) {
        case Dir::norte  : ant += " ^ "; break;
        case Dir::sur    : ant += " v "; break;
        case Dir::oeste  : ant += " < "; break;
        case Dir::este   : ant += " > "; break;
    }
    return ant += reset;
}


void print_iteration(int iteration, std::ostream& os)
{
    os << "\033[36m" << "\033[1;30m" << " N`: " << iteration << " " << "\033[0m" << std::endl;
}
#endif // OTHER_CPP
