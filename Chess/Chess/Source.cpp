#include <iostream>
#include "Source.h"
# include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <algorithm>
#include <stdio.h>
using namespace std;
Source::Source()
{

}


Source::~Source()
{
}
bool errorcheck(Piece * [][8], std::string, int, int, int, int,int ,int & );
bool move(std::string, std::string, int &, int &, int &, int &);
Stack stack;
Memory * Undor = new Memory;
int main(int argc, string argv[])
{ 
	
	char input = NULL; 
	string Filepath1 ;
	bool check = true;
	cout << "Do you want to play a game of chess? (S/E)" << endl;
	
	cin >> input;
	int boo = argc;
	if (argc == 2)
	{
		    

		cin >> Filepath1;
	}
	

	
	Board * run = new Board;

	while (check == true)
	{
		if (input == 'S' || input == 's')
		{
			cout << "You can enter 'E' to end your game.";
			cout << " Have fun.\n";
			
			check = false;
			system("PAUSE");//a short pause before drawing the board

		}
		else if (input == 'E' || input == 'e')
		{
			run->destruct();
			delete run;
			return 0;
			

		}
		else
		{
			cout << "Invalid answer" << endl;
			cin >> input;
		}
	}
	

	run -> init();
	run-> drawboard();

	std::string in, name, pos1, pos2;
	int posx1 , posx2, posy1, posy2 , errorcode = 0;
	bool loop = true, turn = false, moveon,check1;
	cout << "\nType M to move then the name of the piece its \nposition and the position you want it to move to \n(As so, M [Press enter] WP[Press enter]1,2 [Press enter]2,2[Press enter]).";
	while (loop = true)
	{
		

		
		
		do
		{
			if (turn == 0)
			{
				cout << "It is Whites turn\n";
			}
			else
			{
				cout << "It is Blacks turn\n";
			}

			cout << "\nMove(M/m) or Leave(e/E) or Undo th elast move(u/U)\n";
			cin >> in;
			if (in == "m" || in == "M")
			{
				do
				{
					moveon = false;
					cout << "Enter the name of the Piece." << endl;
					cin >> name;
					std::transform(name.begin(), name.end(), name.begin(), ::toupper);//change lowercase to upper 
					cout << "Enter " << name << "'s position." << endl;
					cin >> pos1;
					cout << "Enter where you want it to move." << endl;
					cin >> pos2;
					
				} while (move(pos1, pos2, posx1, posy1, posx2, posy2) == false);
			}
			else if (in == "e" || in == "E")
			{
				run->destruct();
				delete run;
				return 0;
			}
			else if(in == "u" || in == "U")
			{
				//Memory * Undo = new Memory;
				if (Undor->targrow == -1)
				{
					cout << "There are no more moves to undo/n";
				}
				else
				{	stack.pop(Undor);
					run->unmove(Undor->targrow, Undor->srcrow, Undor->targcol, Undor->Srccol, Undor->takenpiece);
					
					//stack.pop(Undo)
					moveon = true;
				}
				
			}
			else
			{
				moveon = true;
				cout << "Incorrect input" << endl;
			}
		} while (moveon == true);


		try
		{
			run->validate(name, posx1, posx2, posy1, posy2, turn, errorcode);
			run->undopop(posx1, posx2, posy1, posy2, Undor);
			stack.push(Undor);
			run->move(posx1, posx2, posy1, posy2);
			turn = !turn;
		}
		catch (const char* msg)
		{
			cout << msg << endl;
		}
		catch (const std::exception&)
		{

		}
		
		
			
			
		
			
		
			


			//switch (errorcode)//error code is just so there is some sort of information given besides just wrong input
			//{
			//case 1:
			//{
			//	cout << "There is no piece on position " << posx1 << "," << posy1 << endl;
			//	break;
			//}
			//case 2:
			//{
			//	cout << "It is the other persons turn" << endl;
			//	break;
			//}
			//case 3:
			//{
			//	cout << "You cannot hit your own piece " << endl;
			//	break;
			//}
			//case 4:
			//{
			//	cout << "Incorrect piece name or trying to move other persons piece"<< endl;
			//	break;
			//}
			//case 5:
			//{
			//	cout << "You cannot act outside of the board" << endl;
			//	break;
			//}
			//default:
			//	break;
			//}
			posx1 = -1;//set these to negative one so it doesn't try to access back up at the this piece has moved part 
			posx2 = -1;
			posy1 = -1;
			posy2 = -1;
		
	}

}


bool move( std::string pos1, std::string pos2, int & posx1, int & posy1, int & posx2, int & posy2)
{
	std::string delimiter = ",";//parsing out the input and changing to ints
	std::string token = pos1.substr(0, pos1.find(delimiter));
	std::string token1 = pos1.substr(2, pos1.find(delimiter));
	std::string token2 = pos2.substr(0, pos2.find(delimiter));
	std::string token3 = pos2.substr(2, pos2.find(delimiter));

	posx1 = atoi(token.c_str());
	posy1 = atoi(token1.c_str());
	posx2 = atoi(token2.c_str());
	posy2 = atoi(token3.c_str());

	if (posx1 < 0 || posx1 > 7 || posx2 < 0 || posx2 > 7 || posy1 < 0 || posy1 > 7 || posy2 < 0 || posy2 > 7)
	{
		return false;
	}
	else
	{
return true;
	}
	
}
