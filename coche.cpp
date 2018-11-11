using namespace IA;

void car::move(){
    node* busqueda = new node(map->get_point(x_coordinate, y_coordinate), (IA::table*)map);
    std::vector<node*> nodos = A_star();
    std::vector<point*> camino;
    for(auto tiles: nodos){
        camino.push_back(tiles->tile);
    }
    std::cout << "a star done.\n";
}