#include <iostream>
#include <fstream>
#include <ncurses.h>
#include <unistd.h>
#include <stdio.h>

#include "table.hpp"

using namespace std;
//int dim=100;


    // int current_state,next_state = 0;
    // int current_x,current_y,next_x,next_y = 0;
    // int current_grid,next_grid = 0;
    
    // int row = 0;
    // int col = 0;
    // char button = 'a';
    // int delay = 3;
    // bool color;
    
    // void inicializar(){
      
    //     while(button != ' '){
    //     clear();
    //     getmaxyx(stdscr,row,col);
    //     if (color) {
    //         attron(COLOR_PAIR(1));
    //     }
    //     mvprintw(row/2, col/2-11, "Espacio para empezar");
    //     mvprintw(row/2+1, col/2-12, "Espacio para salir");
    //     if(color){
    //         attroff(COLOR_PAIR(1));
    //     }
    //     refresh();
    //     button=getch();
    // }
    // clear();
    // // valores iniciales
//     current_grid=-1;
//     current_state=2;
//     current_y=row/2;
//     current_x=col/2;
//     //init first frame
// for (int i=0; i<row; i++) {
//   for (int j=0; j<col; j++) {
//             if (color) {
//                 attron(COLOR_PAIR(3));
//                 mvprintw(i, j, white);
//                 attroff(COLOR_PAIR(3));
//             }
//             else{
//                 mvprintw(i, j, white);
//             }
//         }
//     }
//     if (color) {
//         attron(COLOR_PAIR(5));
//         mvprintw(current_y,current_x,coche[current_state-1]);
//         attroff(COLOR_PAIR(5));
//     }
//     else{
//         mvprintw(current_y,current_x,coche[current_state-1]);
//     }
//     refresh();
// }

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
    
    //IA::
    ifstream ifs;
    ifs.open("map.txt");
    car* coche= new car(0, 0);
    table* mapa;
    if (ifs.is_open()){
        mapa = new table(ifs,coche);
    }else{
        cout << "Introduzca el tamaño del tablero:\nx->";
        cin >> inputx;
        cout << "y->";
        cin >> inputy;
        mapa = new table(inputx,inputy,coche);//tamaño mapa;
    } 
    
    bool stay = true;
    mapa->final.first;
    
    while(stay){
    cout << "Escoja una opción:\nchange->cambia el valor de una casilla\nbool->crea o destrulle un obstaculo\niter->mostrar mapa\nquit->Terminar" << endl;
    cin >> opc;
        if (opc == "change"){
            cin >> inputx >> inputy >> inputz;
            mapa->set_final(inputx, inputy, inputz);
        }
        else if (opc == "move"){
            cin >> inputx >> inputy;
            mapa->set_car(inputx, inputy);//inicio simulación o iteración
        }
        else if (opc == "bool"){
            cin >> inputx >> inputy >> stay;
            mapa->set_obstacle(inputx, inputy, (bool)stay);
            stay = true;
        }
        else if (opc == "iter"){
            mapa->write(cout);//inicio simulación o iteración
        }
        else if (opc == "quit"){
            stay = false;
        }
    }
    return 0;
}
//hacer una salida tipo: tamaño %obstaculos (solución, tiempo de computo, nodos procesados)por cada función heuristica
//la solucion tiene que ser la misma