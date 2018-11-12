#ifndef COCHE_CPP
#define COCHE_CPP
//using namespace IA;

void car::move_rect(){
    map->clear_points();
    node* busqueda = new node(map->get_point(x_coordinate, y_coordinate), map);
    std::vector<point*> camino;
    std::pair<bool,std::vector<node*>> solucion = busqueda->rect();
    std::cout << "Rectilinear algorithm:\n";
    if(solucion.first){ 
        std::cout << "Se ha encontrado solucion.\n";
        std::cout << "Solución: (" << solucion.second.end()[-1]->tile->x << "," << solucion.second.end()[-1]->tile->y << ")" << "\n";
    }
    else std::cout << "No se ha encontrado solucion.\n";
    for(auto tiles: solucion.second){
        //std::cout << tiles->tile->x << "," << tiles->tile->y << std::endl;
        camino.push_back(tiles->tile);
    }
    std::cout << "nodos recorridos:" << solucion.second.end()[-2]->busq - acc << " en " << solucion.second.size() << " pasos.\n";
    acc = solucion.second.end()[-2]->busq;
}

void car::move_lvlalg(){
    map->clear_points();
    node* busqueda = new node(map->get_point(x_coordinate, y_coordinate), map);
    std::vector<point*> camino;
    std::pair<bool,std::vector<node*>> solucion = busqueda->level_alg();
    std::cout << "Level algorithm:\n";
    if(solucion.first){ 
        std::cout << "Se ha encontrado solucion.\n";
        std::cout << "Solución: (" << solucion.second.end()[-1]->tile->x << "," << solucion.second.end()[-1]->tile->y << ")" << "\n";
    }
    else std::cout << "No se ha encontrado solucion.\n";
    for(auto tiles: solucion.second){
        //std::cout << tiles->tile->x << "," << tiles->tile->y << std::endl;
        camino.push_back(tiles->tile);
    }
    std::cout << "nodos recorridos:" << solucion.second.end()[-2]->busq - acc << " en " << solucion.second.size() << " pasos.\n";
    acc = solucion.second.end()[-2]->busq;
}
void car::move_Astar(){
    map->clear_points();
    node* busqueda = new node(map->get_point(x_coordinate, y_coordinate), map);
    std::vector<point*> camino;
    std::pair<bool,std::vector<node*>> solucion = busqueda->A_star();
    std::cout << "A* algorithm:\n";
    if(solucion.first){ 
        std::cout << "Se ha encontrado solucion.\n";
        std::cout << "Solución: (" << solucion.second.end()[-1]->tile->x << "," << solucion.second.end()[-1]->tile->y << ")" << "\n";
    }
    else std::cout << "No se ha encontrado solucion.\n";
    for(auto tiles: solucion.second){
        //std::cout << tiles->tile->x << "," << tiles->tile->y << std::endl;
        camino.push_back(tiles->tile);
    }
    std::cout << "nodos recorridos:" << solucion.second.end()[-2]->busq - acc << " en " << solucion.second.size() << " pasos.\n";
    acc = solucion.second.end()[-2]->busq;
}
#endif