#include <stdio.h>
#include <stdbool.h>
#include "demo.h"
#include "window.h"

#define RESOURCES_PATH      "./resources/"
#define DEFAULT_WIN_SIZE            600

unsigned int background, circle;

static float pos_x, pos_y = 0;

void mouse_clicked(double x, double y){
    printf("Mouse clicked at %f, %f\n", x, y);

    int width, height;
    get_window_size(&width, &height);

    pos_x = (float)x-((int)x % (int)(width/3));
    pos_y = (float)y-((int)y%(int)(height/3));

    draw_image(circle, pos_x, pos_y);
}


int main(){
    init_window(DEFAULT_WIN_SIZE, DEFAULT_WIN_SIZE, true, "");
    
    set_mouse_callback(mouse_clicked);

    background = add_image(RESOURCES_PATH "background.png", DEFAULT_WIN_SIZE, DEFAULT_WIN_SIZE);
    circle = add_image(RESOURCES_PATH "sprite_O.png", DEFAULT_WIN_SIZE/3, DEFAULT_WIN_SIZE/3);

    draw_image(background, 0, 0);
    

    while (!windowShouldClose()){
        render_window();
    }
    
    free_window();

    return 0;
}