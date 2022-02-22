#include "Simple_window.h"
#include "Graph.h"
#include <vector>

/*
g++ -w -Wall -std=c++11 ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp ../GUI/Simple_window.cpp drill_13.cpp `fltk-config --ldflags --use-images` -o a.out
*/

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

    for(int y = y_grid; y<=y_size; y += y_grid){
        grid.add(Point{0,y}, Point{x_size,y});
    }


    win.attach(grid);
	win.wait_for_button();

    Vector_ref<Rectangle> rectangles;
    for(int i=0; i < x_size; i += x_grid){
        rectangles.push_back(new Rectangle{Point{i,i},Point{i+x_grid,i+x_grid}});
        rectangles[i/100].set_fill_color(Color::red);
        win.attach(rectangles[i/100]);
    }

    win.wait_for_button();

    Image image_1{Point{100,500}, "pictures/why.jpg"};
    Image image_2{Point{300,0}, "pictures/why.jpg"};
    Image image_3{Point{600,300}, "pictures/why.jpg"};

    win.attach(image_1);
    win.attach(image_2);
    win.attach(image_3);

    win.wait_for_button();



}
