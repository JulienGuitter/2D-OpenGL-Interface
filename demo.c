#include <stdio.h>
#include "demo.h"
#include "window.h"

#define RESOURCES_PATH      "./resources/"
#define WIN_SIZE            600

unsigned int background, circle;

static float pos_x, pos_y = 0;

void show_items(){
    draw_object(background, 0, 0);


    draw_object(circle, pos_x, pos_y);
}

void mouse_clicked(double x, double y){
    // printf("Mouse clicked at %f, %f\n", x, y);

    pos_x = (float)x-((int)x % 200);
    pos_y = (float)y-((int)y%200);
}


int main(){
    init_window(WIN_SIZE, WIN_SIZE);
    set_render_callback(show_items);
    set_mouse_callback(mouse_clicked);

    background = add_object(RESOURCES_PATH "background.png", WIN_SIZE, WIN_SIZE);
    circle = add_object(RESOURCES_PATH "sprite_O.png", WIN_SIZE/3, WIN_SIZE/3);
    

    while (!windowShouldClose()){
        render_window();
    }
    
    free_window();

    return 0;
}