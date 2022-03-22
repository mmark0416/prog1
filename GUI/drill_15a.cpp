#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

/*
g++ -w -Wall -std=c++11 ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp ../GUI/Simple_window.cpp drill_15a.cpp `fltk-config --ldflags --use-images` -o drill_15a.out
*/

//2. rész
double one(double x){return 1;}
double slope(double x){return x/2;}
double square(double x){return x*x;}
double sloping_cos(double x){return cos(x)+slope(x);}

int main(){
    using namespace Graph_lib;

    //----------1. rész 1-5 feladat-------------

    int x_max = 600;
    int y_max = 600;
    Point tl {100, 100};
    Simple_window win {tl, x_max,y_max, "Function graphs"};

    int x_length = 400;
    int y_length = 400;
    int x_orig = x_max/2;
    int y_orig = y_max/2;
    int x_scale = 20;
    int y_scale = 20;

    Axis x {Axis::x,Point{100,y_orig}, x_length,x_length/x_scale, "1 == 20 pixels"};
    Axis y {Axis::y,Point{x_orig,y_length+100}, y_length,y_length/y_scale, "1 == 20 pixels"};
    
    x.set_color(Color::red);
    y.set_color(Color::red);

    win.attach(x);
    win.attach(y);

    win.wait_for_button();

    //----------2. rész 1-9 feladat---------------
    //1-3.
    Point orig {x_orig,y_orig};
    Function s1 {one,-10,11,orig, 400, x_scale,y_scale};
    win.attach(s1);
    win.wait_for_button();

    //4-5.
    Function s2 {slope,-10,11,orig, 400, x_scale,y_scale};
    Text ts2{Point{100,400},"x/2"};
    win.attach(s2);
    win.wait_for_button();

    //6.
    Function s3 {square,-10,11,orig, 400, x_scale,y_scale};
    win.attach(s3);
    win.wait_for_button();

    //7-8.
    Function s4 {cos,-10,11,orig, 400, x_scale,y_scale};
    win.attach(s4);
    s4.set_color(Color::blue);
    win.wait_for_button();

    //9.
    Function s5 {sloping_cos,-10,11,orig, 400, x_scale,y_scale};
    win.attach(s5);
    win.wait_for_button();


    return 0;
}