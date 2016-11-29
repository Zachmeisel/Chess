#include "Board.h"
# include <cstdlib>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <string>



Board::Board()
{
	
}
Board::~Board()
{
}
void Board::init()
	{
		Piece1[0][0] = new Rook();
		Piece1[1][0] = new Knight();
		Piece1[2][0] = new Bishop();
		Piece1[3][0] = new Queen();
		Piece1[4][0] = new King();
		Piece1[5][0] = new Bishop();
		Piece1[6][0] = new Knight();
		Piece1[7][0] = new Rook();
		Piece1[0][7] = new Rook();
		Piece1[1][7] = new Knight();
		Piece1[2][7] = new Bishop();
		Piece1[3][7] = new Queen();
		Piece1[4][7] = new King();
		Piece1[5][7] = new Bishop();
		Piece1[6][7] = new Knight();
		Piece1[7][7] = new Rook();

		Piece::Color w = Piece::white;
		Piece::Color b = Piece::black;

		for (int q = 0; q < 8; q++)
		{//placing whether each piece is white or black
			Piece1[q][7]->c = b;
			Piece1[q][0]->c = w;
		}

		for (int g = 0; g < 8; g++)
		{
			Piece1[g][1] = new Pawn();
			Piece1[g][1]->c = w;
			Piece1[g][6] = new Pawn();
			Piece1[g][6]->c = b;
		}
	}

void Board::destruct()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			delete  Piece1[i][j];
		}
		
	}
	

}

bool Board::validate(std::string  name, int posx1, int posx2, int posy1, int posy2, int turn, int & errorcode)
{
	std::string check1;
	if (Piece1[posx1][posy1] == NULL)//makes sure it is not NULL
	{
		throw "There is no piece in that position position";
		//return false;
		
	}
	if (Piece1[posx1][posy1]->c == turn)//checks if it is the correct persons turn
	{
		if (posx1 >= 0 && posx1 <= 7 && posx2 >= 0 && posx2 <= 7 && posy1 >= 0 && posy1 <= 7 && posy2 >= 0 && posy2 <= 7)// makes sure a person cannot act outside of the board
		{
			if (Piece1[posx1][posy1]->c == 0 && Piece1[posx2][posy2] == NULL || Piece1[posx1][posy1]->c == 1 && Piece1[posx2][posy2] == NULL ||
				Piece1[posx1][posy1]->c == 0 && Piece1[posx2][posy2]->c == 1 || Piece1[posx1][posy1]->c == 1 && Piece1[posx2][posy2]->c == 0)//makes sure a piece doesn't hit the same color piece
			{
				if (turn == false)
				{
					check1 = "W" + Piece1[posx1][posy1]->geticon();
				}
				else
				{
					check1 = "B" + Piece1[posx1][posy1]->geticon();
				}
				if (check1 == name)//makes sure the piece name is the same as the one given by the user
				{
					return true;
				}
				else
				{
					throw "Incorrect piece name";
					
				}
			}
			else
			{
				throw "You cannot hit your own piece";
				
			}
		}
		else
		{
			throw "You cannot act outside of the board";
			
		}
	}
	else
	{
		throw "It is the other persons turn";
		
	}

	
}

void Board::move(int posx1, int posx2, int posy1, int posy2)
{
	Piece1[posx2][posy2] = Piece1[posx1][posy1];
	Piece1[posx1][posy1] = NULL;

	for (int i = 7; i >= 0; i--)
				{

					std::cout << i;
					for (int j = 0; j <= 7; j++)
					{
						std::cout << "|";
						if (Piece1[j][i] == NULL)
						{
							std::cout << "__";
						}
						else
						{
							if (Piece1[j][i]->c == 0)//c is the color given earlier
							{
								std::cout << "W" << Piece1[j][i]->geticon();
							}
							else
							{
								std::cout << "B" << Piece1[j][i]->geticon();
							}
							
						}
					}
					std::cout << "|" << std::endl;
				}
				for (int k = 0; k <= 7; k++)
				{
					std::cout << "  " << k;
				}
				if (NULL != Piece1[posx2][posy2])
				{

				
				if (Piece1[posx2][posy2]->c == 0)
				{
					std::cout << "\nWhite " << Piece1[posx2][posy2]->getname() << " has moved." << std::endl;
				}
				else
				{
					std::cout << "\nBlack " << Piece1[posx2][posy2]->getname() << " has moved." << std::endl;

				}
				}
}

void Board::undopop(int posx1, int posx2, int posy1, int posy2, Memory * Undor)
{
	Undor->Srccol = posy1;
	Undor->srcrow = posx1;
	Undor->targcol = posy2;
	Undor->targrow = posx2;
	Undor->takenpiece = Piece1[posx2][posy2];



}

void Board::unmove(int posx1, int posx2, int posy1, int posy2, Piece * takenpiece)
{
	Piece1[posx2][posy2] = Piece1[posx1][posy1];
	Piece1[posx1][posy1] = takenpiece;

	for (int i = 7; i >= 0; i--)
	{

		std::cout << i;
		for (int j = 0; j <= 7; j++)
		{
			std::cout << "|";
			if (Piece1[j][i] == NULL)
			{
				std::cout << "__";
			}
			else
			{
				if (Piece1[j][i]->c == 0)//c is the color given earlier
				{
					std::cout << "W" << Piece1[j][i]->geticon();
				}
				else
				{
					std::cout << "B" << Piece1[j][i]->geticon();
				}

			}
		}
		std::cout << "|" << std::endl;
	}
	for (int k = 0; k <= 7; k++)
	{
		std::cout << "  " << k;
	}
	if (NULL != Piece1[posx2][posy2])
	{


		if (Piece1[posx2][posy2]->c == 0)
		{
			std::cout << "\nWhite " << Piece1[posx2][posy2]->getname() << " has moved." << std::endl;
		}
		else
		{
			std::cout << "\nBlack " << Piece1[posx2][posy2]->getname() << " has moved." << std::endl;

		}
	}
}
void Board::drawboard()
{
	

			for (int i = 7; i >= 0; i--)
			{

				std::cout << i;
				for (int j = 0; j <= 7; j++)
				{
					std::cout << "|";
					if (Piece1[j][i] == NULL)
					{
						std::cout << "__";
					}
					else
					{
						if (Piece1[j][i]->c == 0)//c is the color given earlier
						{
							std::cout << "W" << Piece1[j][i]->geticon();
						}
						else
						{
							std::cout << "B" << Piece1[j][i]->geticon();
						}

					}
				}
				std::cout << "|" << std::endl;
			}
			for (int k = 0; k <= 7; k++)
			{
				std::cout << "  " << k;
			}
}
