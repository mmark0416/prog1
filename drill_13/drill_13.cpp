#include "Simple_window.h"
#include "Graph.h"

int main(){
    using namespace Graph_lib;

	Point tl{ 100, 100 };

    int xmax = 800;
    int ymax = 1000;
	Simple_window win {tl, xmax, ymax, "grid-image drill" };

	int x_size = 800;
	int y_size = 800;
	int x_grid = 100;
	int y_grid = 100;
    Lines grid;

	for(int x = x_grid; x<x_size;x+=x_grid){
        grid.add(Point{x,0},Point{x,y_size});
	}

    for(int y = y_grid; y<y_size; y += y_grid){
        grid.add(Point{0,y}, Point{x_size,y});
    }



	win.attach(grid);
	win.wait_for_button();
}
