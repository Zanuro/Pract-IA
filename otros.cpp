#include <ncurses.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>


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
        mvprintw(row/2, col/2-11, "Space para comenzar");
        mvprintw(row/2+1, col/2-12, "Otro space para acabar");
        if (color) {
            attroff(COLOR_PAIR(1));
        }
        refresh();
        button=getch();
    }
    clear();

    tabla_actual=-1;
    estado_actual=2;
    y_act=row/2;
    x_act=col/2;

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



int main()
{
    initscr();
    curs_set(0);
    noecho();
    cbreak();
    halfdelay(delay_10th);
    color=has_colors();
    if (color) {
        start_color();
        init_pair(1, COLOR_vacio, COLOR_BLACK);
        init_pair(2, COLOR_BLUE, COLOR_BLUE);
        init_pair(3, COLOR_CYAN, COLOR_CYAN);
        init_pair(4, COLOR_MAGENTA, COLOR_BLUE);
        init_pair(5, COLOR_MAGENTA, COLOR_CYAN);
    }
    while (1) {
        int new_fila=1;
        int new_col=1;
        getmaxyx(stdscr,new_fila,new_col);
        if (new_fila!=filas || new_col!=columnas) {
            init_game();
        }
        //check keyboard
        button=getch();
        if(button==' '){
            break;
        }

        y_sig=y_act+(estado_actual%2)*(estado_actual-2);
        if (y_sig<0) {
            y_sig=row-1;
        }else if (y_sig>row-1) {
            y_sig=0;
        }
        x_sig=x_act+(estado_actual%2-1)*(estado_actual-3);
        if (x_sig<0) {
            x_sig=col-1;
        }else if(x_sig>col-1){
            x_sig=0;
        }
        //
        char test=(char)mvinch(y_sig, x_sig);
        if (test==vacio[0]) {
            next_grid=-1;
        }else if(test==black[0]){
            next_grid=1;
        }
        next_state=estado_actual+next_grid;
        if (next_state<1) {
            next_state=4;
        }else if (next_state>4){
            next_state=1;
        }
        //draw current grid
        tabla_actual*=-1;
        if (tabla_actual==-1) {
            if (color) {
                attron(COLOR_PAIR(3));
                mvprintw(y_act, x_act, vacio);
                attroff(COLOR_PAIR(3));
            }else{
                mvprintw(y_act, x_act, vacio);
            }
        }else{
            if (color) {
                attron(COLOR_PAIR(2));
                mvprintw(y_act, x_act, black);
                attroff(COLOR_PAIR(2));
            }else{
                mvprintw(y_act, x_act, black);
            }
        }
        y_act=y_sig;
        x_act=x_sig;
        tabla_actual=next_grid;
        estado_actual=next_state;
        if (color) {
            if (tabla_actual==-1) {
                attron(COLOR_PAIR(4));
            }else{
                attron(COLOR_PAIR(5));
            }
            mvprintw(y_act,x_act,ant[estado_actual-1]);
            if (tabla_actual==-1) {
                attroff(COLOR_PAIR(4));
            }else{
                attroff(COLOR_PAIR(5));
            }
        }else{
            mvprintw(y_act,x_act,ant[estado_actual-1]);
        }
        refresh();
    }
    button=0;
    while (button!=' ') {
        clear();
        getmaxyx(stdscr,row,col);
        if (color) {
            attron(COLOR_PAIR(1));
        }
        mvprintw(row/2, col/2-10, "Final");
        mvprintw(row/2+1, col/2-12, "Espacio para salir");
        refresh();
        if (color) {
            attroff(COLOR_PAIR(1));
        }
        button=getch();
    }
    endwin();
}
