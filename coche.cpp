#ifndef COCHE_CPP
#define COCHE_CPP
//using namespace IA;

void car::move_rect(){
    map->clear_points();
    //map->path.clear();
    node* busqueda = new node(map->get_point(x_coordinate, y_coordinate), map);
    std::pair<bool,std::vector<node*>> solucion = busqueda->A_rect();
    std::cout << "A* Rectilinear algorithm:\n";
    if(solucion.first){ 
        std::cout << "Se ha encontrado solucion.\n";
        std::cout << "Solución: (" << solucion.second.end()[-1]->tile->x << "," << solucion.second.end()[-1]->tile->y << ")" << "\n";
        for(auto tiles: solucion.second){
            //std::cout << tiles->tile->x << "," << tiles->tile->y << std::endl;
            //std::cout << tiles->my_dist << std::endl;
            map->path.push_back(std::make_pair(tiles->tile->x,tiles->tile->y));
        }
        std::cout << "nodos recorridos:" << solucion.second.end()[-2]->busq - acc << "\nCamino en " << solucion.second.size() << " pasos.\n";
        acc = solucion.second.end()[-2]->busq;
    }
    else std::cout << "No se ha encontrado solucion.\n";
}

void car::move_lvlalg(){
    map->clear_points();
    //map->path.clear();
    node* busqueda = new node(map->get_point(x_coordinate, y_coordinate), map);
    std::pair<bool,std::vector<node*>> solucion = busqueda->level_alg();
    std::cout << "Level algorithm:\n";
    if(solucion.first){ 
        std::cout << "Se ha encontrado solucion.\n";
        std::cout << "Solución: (" << solucion.second.end()[-1]->tile->x << "," << solucion.second.end()[-1]->tile->y << ")" << "\n";
        for(auto tiles: solucion.second){
            //std::cout << tiles->tile->x << "," << tiles->tile->y << std::endl;
            map->path.push_back(std::make_pair(tiles->tile->x,tiles->tile->y));
        }
        std::cout << "nodos recorridos:" << solucion.second.end()[-2]->busq - acc << "\nCamino en " << solucion.second.size() << " pasos.\n";
        acc = solucion.second.end()[-2]->busq;
    }
    else std::cout << "No se ha encontrado solucion.\n";
}
void car::move_euc(){
    map->clear_points();
    //map->path.clear();
    node* busqueda = new node(map->get_point(x_coordinate, y_coordinate), map);
    std::pair<bool,std::vector<node*>> solucion = busqueda->A_euc();
    std::cout << "A* Euclid algorithm:\n";
    if(solucion.first){ 
        std::cout << "Se ha encontrado solucion.\n";
        std::cout << "Solución: (" << solucion.second.end()[-1]->tile->x << "," << solucion.second.end()[-1]->tile->y << ")" << "\n";
        for(auto tiles: solucion.second){
            //std::cout << tiles->tile->x << "," << tiles->tile->y << std::endl;
            //std::cout << tiles->my_dist << std::endl;
            map->path.push_back(std::make_pair(tiles->tile->x,tiles->tile->y));
        }
        std::cout << "nodos recorridos:" << solucion.second.end()[-2]->busq - acc << "\nCamino en " << solucion.second.size() << " pasos.\n";
        acc = solucion.second.end()[-2]->busq;
    }
    else std::cout << "No se ha encontrado solucion.\n";
}
#endif