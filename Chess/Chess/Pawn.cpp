#include "Pawn.h"



Pawn::Pawn()
{
}


Pawn::~Pawn()
{
}

std::string Pawn::getname()
{
	name = "Pawn";
	return "Pawn";
}

bool Pawn::move()
{
	return true;
}
std::string Pawn::geticon()
{
	return "P";

}