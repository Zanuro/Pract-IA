#ifndef COCHE_CPP
#define COCHE_CPP
//using namespace IA;

void car::move(){
    node* busqueda = new node(map->get_point(x_coordinate, y_coordinate), map);
    std::vector<node*> nodos = busqueda->A_star();
    std::vector<point*> camino;
    for(auto tiles: nodos){
        camino.push_back(tiles->tile);
    }
    std::cout << "a star done.\n";
}
#endif