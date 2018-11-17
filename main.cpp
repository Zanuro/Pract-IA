#include <iostream>
#include <fstream>
#include <ncurses.h>
#include <unistd.h>
#include <stdio.h>
#include <chrono>

#include "table.hpp"

using namespace std;
//int dim=100;

/*
char vacio[]=" ";
char obstaculo[]="O";
char persona[]="P";
char coch[]="C";
char meta[]="M";

int tabla_actual,tabla_prox;

int estado_actual,estado_sig;

int x_act,y_act,x_sig,y_sig;

int filas=0;
int columnas=0;
char button='a';
int delay_10th=3;
bool color;

void init_game(){
    while (button!=' ') {
        clear();
        getmaxyx(stdscr,filas,columnas);
        if (color) {
            attron(COLOR_PAIR(1));
        }
        mvprintw(filas/2, columnas/2-11, "Space para comenzar");
        mvprintw(filas/2+1, columnas/2-12, "Otro space para acabar");
        if (color) {
            attroff(COLOR_PAIR(1));
        }
        refresh();
        button=getch();
    }
    clear();

    tabla_actual=-1;
    estado_actual=2;
    y_act=filas/2;
    x_act=columnas/2;

    for (int i=0; i<filas; i++) {
        for (int j=0; j<columnas; j++) {
            if (color) {
                attron(COLOR_PAIR(3));
                mvprintw(i, j, vacio);
                attroff(COLOR_PAIR(3));
            }else{
                mvprintw(i, j, vacio);
            }
        }
    }
    if (color) {
        attron(COLOR_PAIR(5));
        mvprintw(y_act,x_act,coche[estado_actual-1]);
        attroff(COLOR_PAIR(5));
    }else{
        mvprintw(y_act,x_act,coche[estado_actual-1]);
    }
    refresh();
}
*/

int main()
{
    int inputx, inputy, inputz;
    string opc;
    
    
    // initscr();
    // curs_set(0);
    // noecho();
    // cbreak();
    // halfdelay(delay);
    // color=has_colors();
    // if(color){
    
    //     start_color();
    //     init_pair(COLOR_BLACK,COLOR_RED);//‘int init_pair(short int, short int, short int)’
    //     init_pair(COLOR_BLACK,COLOR_BLUE);
    //     init_pair(COLOR_BLACK,COLOR_MAGENTA);
        
    //     while(1){
    //       int new_row = 1;
    //       int new_col = 1;
    //       getmaxyx(stdscr,new_row,new_col);
    //       if(new_row!=row || new_col!= col){
    //         inicializar();
    //       }
    //       button = getch();
    //       if(button == ' ')
    //         break;
            
    //       current_x+=next_x*(current_state%2)*(current_state-2);
    //       current_y+=nex
    //     }
    // }
    // //wborder(win, 0, 0, 0, 0, 0, 0, 0, 0);
    table* mapa;
    car* coche= new car(1, 1);
    //IA::
    cout << "\033[32m"<< "Escoja una opción:\nfile->abrir fichero\nnormal->tablero por defecto\nrand->generar valor" <<"\033[0m"<< endl;
        cin >> opc;
        if (opc == "file"){
            ifstream ifs;
            ifs.open("map.txt");
            mapa = new table(ifs,coche);
        }else if (opc == "normal"){
            cout << "\033[32m"<< "Introduzca el tamaño del tablero:\nx->";
            cin >> inputx;
            cout << "y->";
            cin >> inputy;
            cout << "\033[0m";
            mapa = new table(inputx,inputy,coche,false);//tamaño mapa;
        }else if (opc == "rand"){
            cout << "\033[32m"<<"Introduzca el tamaño del tablero:\nx->";
            cin >> inputx;
            cout << "y->";
            cin >> inputy;
            cout << "\033[0m";
            mapa = new table(inputx,inputy,coche,true);
        }else cout <<"\033[31m" << "error" << "\033[0m";
    
    bool stay = true;
    mapa->final.first;
    cout << "\033[32m" <<"Escoja una opción:\nchange->cambia el valor de una casilla\nbool->crea o destruye un obstaculo\niter->mostrar mapa\n>rectilinear\n>euclid\n>level\nquit->Terminar" << "\033[0m"<< endl;
    while(stay){
        cin >> opc;
        if (opc == "change"){
            cin >> inputx >> inputy >> inputz;
            mapa->set_final(inputx, inputy, inputz);
        }
        else if (opc == "move"){
            cin >> inputx >> inputy;
            mapa->set_car(inputx, inputy);
        }
        else if (opc == "bool"){
            cin >> inputx >> inputy >> stay;
            mapa->set_obstacle(inputx, inputy, (bool)stay/2);
            stay = true;
        }
        else if (opc == "iter"){
            mapa->write(std::cout);
        }
        else if (opc == "rectilinear"){
            cout << "-----------------------" << endl;
            auto start = std::chrono::high_resolution_clock::now(); 
            coche->move_rect();
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
            cout << "\033[32m"<<"Elapsed time: " << duration.count() << " microseconds(10^-9)" << "\033[0m"<< endl;
            
        }
        else if (opc == "level"){
            cout << "-----------------------" << endl;
            auto start = std::chrono::high_resolution_clock::now();
            coche->move_lvlalg();
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
            cout << "\033[32m"<<"Elapsed time: " << duration.count() << " microseconds(10^-9)" << "\033[0m"<< endl;
        }
        else if (opc == "euclid"){
            cout << "-----------------------" << endl;
            auto start = std::chrono::high_resolution_clock::now(); 
            coche->move_euc();
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
            cout << "\033[32m"<<"Elapsed time: " << duration.count() << " microseconds(10^-9)" << "\033[0m"<< endl;
            
        }
        else if (opc == "quit"){
            stay = false;
        }
    }
    return 0;
}