#pragma once
#include "Piece.h"
#include "Rook.h"
#include "Knight.h"
#include "Pawn.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Memory.h"
class Board
{
public:
	Board();
	~Board();

	Piece * Piece1[8][8] = { NULL };

	void init();

	void destruct();

	void drawboard();

	bool validate(std::string, int, int, int, int, int, int &);

	void move(int , int , int , int );

	void unmove(int, int, int, int, Piece *);

	void undopop(int, int, int, int, Memory *);

	

};

