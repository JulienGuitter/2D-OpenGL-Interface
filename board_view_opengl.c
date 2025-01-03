/**
 * @file board_view_opengl.c
 *
 * @date 1 jan 2025
 * @author Guitter Julien
 */

#include "board_view.h"
#include <assert.h>
#include <stdio.h>

#include "window.h"

#include "tictactoe_errors.h"

#if defined CONFIG_OPENGLUI


#define RESOURCES_PATH      "./resources/"
#define WIN_SIZE            600

void render(){
	
}

void BoardView_init (void)
{
	init_window(WIN_SIZE, WIN_SIZE);
	set_render_callback(render);
}

void BoardView_free (void)
{
    free_window();
}

void BoardView_displayAll (void)
{
	render_window();
}

void BoardView_displaySquare (Coordinate x, Coordinate y, PieceType kindOfPiece)
{
	/* utiliser "render" pour afficher le sprite correspondant à kindOfPiece à
	 * l'endroit correspondant aux coordonnées logiques "x" et "y".
	 */

}

void BoardView_displayEndOfGame (GameResult result)
{
	// TODO: vous pouvez améliorer ceci (lorsque le reste fonctionnera)
}

void BoardView_displayPlayersTurn (PieceType thisPlayer)
{
	// TODO: vous pouvez améliorer ceci (lorsque le reste fonctionnera)
}

void BoardView_sayCannotPutPiece (void)
{
	// TODO: vous pouvez améliorer ceci (lorsque le reste fonctionnera)
}

#endif // defined CONFIG_OPENGLUI
