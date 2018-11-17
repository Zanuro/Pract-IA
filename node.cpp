#ifndef NODE_CPP
#define NODE_CPP
#include <limits>
#include <queue>
#include <bits/stdc++.h> //para ordenar el primer valor del pair
#include <algorithm>

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
                tmp.second->my_dist = tmp.first;
                nodos.push_back(tmp);
            }
            busq += busqueda;
            sort(nodos.begin(), nodos.end()); //ordena en base al primer valor
        }
        
        static bool ValueCmp(const node * a, const node * b)
        { 
            //if(a->my_dist<b->my_dist) std::cout << a->my_dist << "<" << b->my_dist << "  true\n";
            //return a->my_dist < b->my_dist; 
            return isless(a->my_dist,b->my_dist);
        }
        std::pair<bool,std::vector<node*>> A_euc(){ 
            return A_euc(this);
        }
        std::pair<bool,std::vector<node*>> A_euc(node* iter){
            static std::vector<node*> camino;
            static bool finish = false;
            vector<node*> q; 
            q.push_back(iter);
            
            while (q.empty() == false) 
            { 
                std::sort(q.begin(), q.end(), node::ValueCmp);//usa la función ValueCmp
                node *nodo = q.front(); 
               // std::cout << nodo->my_dist <<"\n";
                camino.push_back(nodo);
                if(nodo->my_dist == 0){
                    finish = true;
                    break;
                } 
                q.erase(q.begin());
                
                nodo->gen_tiles();
                for(auto at : nodo->nodos){
                    at.second->my_dist = (abs((int)map->final.first - (int)at.second->tile->x) + abs((int)map->final.second - (int)at.second->tile->y));
                }
                
                for(auto step: nodo->nodos){
                    q.push_back(step.second);
                }
            }
            
            node* last = camino.end()[-1];
            camino.clear();
            do{
                camino.push_back(last);
                last = last->parent;
            }while(last != NULL);
            std::reverse(camino.begin(), camino.end());
            
            std::pair<bool,std::vector<node*>> result;
            result.first = finish;
            result.second = camino;
            return result;
        }
        
        std::pair<bool,std::vector<node*>> level_alg(){ 
            return level_alg(this);
        }
        std::pair<bool,std::vector<node*>> level_alg(node* iter){
            std::vector<node*> camino;
            bool finnish = false;
            queue<node*> q; 
            q.push(iter); 
          
            while (q.empty() == false) 
            { 
                node *nodo = q.front(); 
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
            node* last = camino.end()[-1];
            camino.clear();
            do{
                camino.push_back(last);
                last = last->parent;
            }while(last != NULL);
            std::reverse(camino.begin(), camino.end());
            
            std::pair<bool,std::vector<node*>> result;
            result.first = finnish;
            result.second = camino;
            return result;
        }
        
        std::pair<bool,std::vector<node*>> A_rect(){ 
            return A_rect(this);
        }
        std::pair<bool,std::vector<node*>> A_rect(node* iter){
            static std::vector<node*> camino;
            static bool finish = false;
            vector<node*> q; 
            q.push_back(iter); 
          
            while (q.empty() == false) 
            { 
                std::sort(q.begin(), q.end(), node::ValueCmp);
                node *nodo = q.front(); 
                q.erase(q.begin());
                camino.push_back(nodo);
                if(nodo->my_dist == 0){
                    finish = true;
                    break;
                } 
                
                nodo->gen_tiles();
                for(auto at : nodo->nodos){
                    at.second->my_dist = abs(sqrt(pow((map->final.first),2) + pow((map->final.second ),2)) - sqrt(pow(at.second->tile->x,2) + pow(at.second->tile->y,2)));
                    //at.second->my_dist = sqrt(pow((map->final.first - at.second->tile->x),2) + pow((map->final.second - at.second->tile->y),2));//esto esta maaal
                }
                
                for(auto step: nodo->nodos){
                    q.push_back(step.second);
                }
            }
            
            node* last = camino.end()[-1];
            camino.clear();
            do{
                camino.push_back(last);
                last = last->parent;
            }while(last != NULL);
            
            std::reverse(camino.begin(), camino.end());
            
            std::pair<bool,std::vector<node*>> result;
            result.first = finish;
            result.second = camino;
            return result;
        }
};
//}
            //euclid
            // if(iter->my_dist == 0){
            //     finish = true;
            // } 
            // else iter->gen_tiles();
            // for(auto zona : iter->nodos){
            //     zona.first = zona.second->tile->x + zona.second->tile->y;
            // }
            // for(auto step: iter->nodos){
            //     if(finish) break;
            //     A_euc(step.second);
            //     if(finish) break;
            //     camino.pop_back();
            // }
            //rectilinear
            // if(iter->my_dist == 0){
            //     finish = true;
            // } 
            // else{ 
            //     iter->gen_tiles();
            //     for(auto gen: iter->nodos){
            //         cola.push_back(gen);
            //     }
            //     sort(cola.begin(), cola.end());
            //     iter = cola.at(0).second;
            //     cola.erase(cola.begin());
            //     A_rect(iter);
            // }

#endif















