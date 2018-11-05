namespace IA{
class node:public table{//Esto sera usado para interaccionar con la clase table
    private:
        node* parent;
        node* son;
        unsigned int x;
        unsigned int y;
        unsigned int nivel = 0;
        std::vector<point*> nodos;
    public:
        double distance;
        node(unsigned int i,unsigned int j,double dist):
            x(i),
            y(j),
            parent(NULL),
            distance(dist){}
        
        node(node* dad,double dist,unsigned int lev):
            parent(dad),
            distance(dist),
            nivel(lev){}
            
        
        inline void set_tablero(table* grid){map = grid;}
        
        void gen_tiles(){
            for(int i=-1;i < 2;i+=2){
                if((x >= 0) && (x_pos < map->num_col)){
                    push_back(get_cell(x+i, y));
                }
            }
            for(int i=-1;i < 2;i+=2){
                if((y >= 0) && (y_pos < map->num_row)){
                    push_back(get_cell(x, y+i));
                }
            }
            for(auto i:nodos){
                i->distance = distance(i->x, i->y);
            }
        }
        void gen_node(){
            for(auto i : nodos){
                
            }
        }
}
}