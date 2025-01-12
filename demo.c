#include <stdio.h>
#include <stdbool.h>
#include "demo.h"
#include "window.h"

#define RESOURCES_PATH      "./resources/"
#define DEFAULT_WIN_SIZE            600

unsigned int background, circle;

static float pos_x, pos_y = 0;

void show_items(){
    draw_object(background, 0, 0);


    draw_object(circle, pos_x, pos_y);
}

void mouse_clicked(double x, double y){
    // printf("Mouse clicked at %f, %f\n", x, y);

    int width, height;
    get_window_size(&width, &height);

    pos_x = (float)x-((int)x % (int)(width/3));
    pos_y = (float)y-((int)y%(int)(height/3));
}


int main(){
    init_window(DEFAULT_WIN_SIZE, DEFAULT_WIN_SIZE, false);
    set_render_callback(show_items);
    set_mouse_callback(mouse_clicked);

    background = add_object(RESOURCES_PATH "background.png", DEFAULT_WIN_SIZE, DEFAULT_WIN_SIZE);
    circle = add_object(RESOURCES_PATH "sprite_O.png", DEFAULT_WIN_SIZE/3, DEFAULT_WIN_SIZE/3);
    

    while (!windowShouldClose()){
        render_window();
    }
    
    free_window();

    return 0;
}