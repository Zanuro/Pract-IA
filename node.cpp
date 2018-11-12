#ifndef NODE_CPP
#define NODE_CPP
#include <limits>
#include <queue>
#include <bits/stdc++.h> //para ordenar el primer valor del pair

//namespace IA{
class node{//Esto sera usado para interaccionar con la clase table
        public:
        point* tile;
        table* map;
        node* parent;
        std::vector<std::pair<double,node*>> nodos;
        unsigned int nivel;
        double my_dist;
        unsigned int busq = 0;
        
        node(point* pos, table* grid):
            map(grid),
            parent(NULL),
            tile(pos),
            my_dist(grid->distance(pos->x, pos->y)),
            nivel(0){}
        
        node(node* dad,point* pos,unsigned int lev, table* grid):
            map(grid),
            parent(dad),
            tile(pos),
            my_dist(grid->distance(pos->x, pos->y)),
            nivel(lev){}
            
        
        inline void set_tablero(table* grid){map = grid;}//(IA::table*)grid;}
        
        void gen_tiles(){//crea el vector con puntos no accedidos y accesibles ,asi no existe solapamiento
            std::vector<point*> celdas;
            static unsigned int busqueda = 0;
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
                busqueda++;
                //std::cout << zona->x << "," << zona->y << "->" << busqueda << std::endl;
                tmp.first = map->distance(zona->x, zona->y);
                tmp.second = new node(this, zona, nivel+1, map);
                nodos.push_back(tmp);
            }
            busq += busqueda;
            sort(nodos.begin(), nodos.end()); //ordena en base al primer valor
        }
        
        std::pair<bool,std::vector<node*>> A_star(){ 
            return A_star(this);
        }
        std::pair<bool,std::vector<node*>> A_star(node* iter){//se generan los nodos a partir del punto mas adecuado
            static std::vector<node*> camino;
            static bool finish = false;
            camino.push_back(iter);
            // for(auto ite: camino){
            //     std::cout << ite->tile->x << "," << ite->tile->y << std::endl;
            // }
            // std::cout << std::endl;
            if(iter->my_dist == 0){
                finish = true;
            } 
            else iter->gen_tiles();
            for(auto step: iter->nodos){
                if(finish) break;
                A_star(step.second);
            }
            std::pair<bool,std::vector<node*>> result;
            result.first = finish;
            result.second = camino;
            return result;
        }
        
        std::pair<bool,std::vector<node*>> level_alg(){ 
            return level_alg(this);
        }
        std::pair<bool,std::vector<node*>> level_alg(node* iter){//se generan los nodos a partir del punto mas adecuado
            std::vector<node*> camino;
            bool finnish = false;
            queue<node*> q; 
            q.push(iter); 
          
            while (q.empty() == false) 
            { 
                node *nodo = q.front(); 
                //std::cout << nodo->tile->x << "," << nodo->tile->y << std::endl;
                camino.push_back(nodo);
                if(nodo->my_dist == 0){
                    finnish = true;
                    break;
                } 
                q.pop();
                /* Pone en cola los niveles*/
                nodo->gen_tiles();
                for(auto step: nodo->nodos){
                    q.push(step.second);
                }
            }
            std::pair<bool,std::vector<node*>> result;
            result.first = finnish;
            result.second = camino;
            return result;
        }
};
//}

#endif















