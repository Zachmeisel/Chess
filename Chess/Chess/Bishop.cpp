#include "Bishop.h"



Bishop::Bishop()
{
}


Bishop::~Bishop()
{
}

std::string Bishop::getname()
{
	return "Bishop";
}

bool Bishop::move()
{
	return true;
}
std::string Bishop::geticon()
{
	return "B";

}