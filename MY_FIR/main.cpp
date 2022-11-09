#include <iostream>
#include "ChessGame.h"

int main(void)
{
	Man man;
	Chess chess;
	AI ai;
	ChessGame game(&man, &ai, &chess);

	game.play();

	return 0;
}