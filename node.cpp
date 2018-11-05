#include <limits>

namespace IA{
class node:public table{//Esto sera usado para interaccionar con la clase table
    private:
        point* tile;
        std::vector<point*> nodos;
        unsigned int nivel;
    public:
        node* parent;
        node* son;
        double distance;
        
        node(point* pos):
            tile(pos),
            parent(NULL),
            distance(dist),
            nivel(0){}
        
        node(node* dad,point* pos,unsigned int lev):
            parent(dad),
            tile(pos),
            nivel(lev){}
            
        
        inline void set_tablero(table* grid){map = grid;}
        
        void gen_tiles(){
            for(int i=-1;i < 2;i+=2){
                if((tile->x >= 0) && (tile->x < get_col())){
                    push_back(get_cell(x+i, y));
                }
            }
            for(int i=-1;i < 2;i+=2){
                if((tile->y >= 0) && (tile->y < get_row())){
                    push_back(get_cell(x, y+i));
                }
            }
            for(auto i:nodos){
                i->distance = distance(i->x, i->y);
            }
        }
        
        void gen_node(){
            gen_node(this);
        }
        void gen_node(node* iter){
            if(tile->second >= 0){
                point* inf = new point(std::numeric_limits<double>::infinity());
                for(auto i : nodos){
                    if(i->distance < inf->distance)inf = i;
                }
                iter->son = new node(iter, inf, nivel+1);
                gen_node(son);
            }
        }
}
}