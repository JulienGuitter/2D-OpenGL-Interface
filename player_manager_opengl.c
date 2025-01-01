/**
 * @file player_manager_opengl.c
 *
 * @date 1 jan 2025
 * @author Guitter Julien
 */

#include "board.h"
#include "board_view.h"
#include <assert.h>

#include "window.h"

#include <stdbool.h>

#if defined CONFIG_PLAYER_MANAGER_OPENGL

static int cell_x, cell_y = 0;
static bool isClicked = false;

void mouse_clicked(double x, double y){
	// TODO: à compléter
    printf("Mouse clicked at %f, %f\n", x, y);
}

void PlayerManager_init (void)
{
	set_mouse_callback(mouse_clicked);
}

void PlayerManager_free (void)
{
}

static bool tryMove (int x, int y)
{

  // TODO: à compléter
}

void PlayerManager_oneTurn (void)
{
	if(isClicked){
		if(tryMove(cell_x, cell_y)){
			isClicked = false;
		}
	}
}

#endif // defined CONFIG_PLAYER_MANAGER_OPENGL
