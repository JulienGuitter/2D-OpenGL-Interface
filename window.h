/**
  *   @file window.h
  * 
  *   @author Guitter Julien
  *   @date 1 jan 2025
  */

#ifndef WINDOW_H
#define WINDOW_H

void init_window(int width, int height);
void set_render_callback(void (*callback)(void));
void set_mouse_callback(void (*callback)(double, double));

void free_window();
int windowShouldClose();

unsigned int add_object(const char* texture_path, double width, double height);
void draw_object(unsigned int object, double x, double y);
void render_window();

#endif // WINDOW_H