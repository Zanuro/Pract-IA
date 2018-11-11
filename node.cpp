#ifndef NODE_CPP
#define NODE_CPP
#include <limits>
#include <bits/stdc++.h> //para ordenar el primer valor del pair

//namespace IA{
class node{//Esto sera usado para interaccionar con la clase table
        public:
        point* tile;
        table* map;
        node* parent;
        std::vector<std::pair<double,node*>> nodos;
        std::vector<point*> celdas;
        unsigned int nivel;
        double my_dist;
        
        node(point* pos, table* grid):
            map(grid),
            parent(NULL),
            tile(pos),
            my_dist(pos->distance),
            nivel(0){}
        
        node(node* dad,point* pos,unsigned int lev, table* grid):
            map(grid),
            parent(dad),
            tile(pos),
            my_dist(pos->distance),
            nivel(lev){}
            
        
        inline void set_tablero(table* grid){map = grid;}//(IA::table*)grid;}
        
        void gen_tiles(){//crea el vector con puntos no accedidos y accesibles ,asi no existe solapamiento
            for(int i=-1;i < 2;i+=2){
                if((tile->x+i >= 0) && (tile->x+i < map->get_col())){
                    if( (!map->get_point(tile->x+i, tile->y)->first) && (!map->get_point(tile->x+i, tile->y)->check) ){//si NO hay obstaculo y NO ha sido checkeado
                        celdas.push_back(map->get_point(tile->x+i, tile->y));
                        map->get_point(tile->x+i, tile->y)->check = true;
                    } 
                }
            }
            for(int i=-1;i < 2;i+=2){
                if((tile->y+i >= 0) && (tile->y+i < map->get_row())){
                    if( (!map->get_point(tile->x, tile->y+i)->first) && (!map->get_point(tile->x, tile->y+i)->check) ){
                        celdas.push_back(map->get_point(tile->x, tile->y+i));
                        map->get_point(tile->x, tile->y+i)->check = true;
                    } 
                }
            }
            for(auto zona : celdas){
                std::pair<double, node*> tmp;
                tmp.first = map->distance(zona->x, zona->y);
                tmp.second = new node(this, zona, nivel+1, map);
                nodos.push_back(tmp);
            }
            sort(nodos.begin(), nodos.end()); //ordena en base al primer valor
        }
        
        std::vector<node*> A_star(){ 
            A_star(this);
        }
        std::vector<node*> A_star(node* iter){//se generan los nodos a partir del punto mas adecuado
            static std::vector<node*> camino;
            static bool finish = false;
            camino.push_back(iter);
            if(iter->my_dist == 0) finish = true;
            iter->gen_tiles();
            for(auto step: nodos){
                A_star(iter);
                if(finish) break;
            }
            return camino;
        }
};
//}

#endif















