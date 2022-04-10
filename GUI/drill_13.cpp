#include "Simple_window.h"
#include "Graph.h"

/*
g++ -w -Wall -std=c++11 ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp ../GUI/Simple_window.cpp drill_13.cpp `fltk-config --ldflags --use-images` -o drill_13.out
*/

int main(){
    using namespace Graph_lib;

    //1. Make an 800-by-1000 Simple_window

	Point tl{ 100, 100 };

    int xmax = 800;
    int ymax = 1000;
	Simple_window win {tl, xmax, ymax, "grid-image drill" };

    //Put an 8-by-8 grid

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

    //3. Make the eight squares on the diagonal

    Vector_ref<Rectangle> rectangles;
    for(int i=0; i < x_size; i += x_grid){
        rectangles.push_back(new Rectangle{Point{i,i},Point{i+x_grid,i+x_grid}});
        rectangles[rectangles.size()-1].set_color(Color::invisible);
        rectangles[rectangles.size()-1].set_fill_color(Color::red);
        win.attach(rectangles[rectangles.size()-1]);
    }

    win.wait_for_button();

    //4. Find a 200-by-200-pixel image

    Image image_1{Point{100,500}, "pictures/why.jpg"};
    Image image_2{Point{300,0}, "pictures/why.jpg"};
    Image image_3{Point{600,300}, "pictures/why.jpg"};

    win.attach(image_1);
    win.attach(image_2);
    win.attach(image_3);
    win.wait_for_button();

    //5. Add a 100-by-100 image

    Image image_4{Point{0,0}, "pictures/kozlegeny.jpg"};
    win.attach(image_4);
    win.wait_for_button();
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            image_4.move(100,0);
            win.wait_for_button();
        }
        image_4.move(-800,100);
        win.attach(image_4);
        win.wait_for_button();
    }
    
    win.wait_for_button();

}
