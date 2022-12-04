#include <iostream>
#include <fstream>
#include "Gamer.h"
#include <vector>
#include <iomanip>


using namespace std;

void display(Gamer& game)
{
	
}
//create gammer struct
struct gamerStruct
{
	string id;
	string name;
	string email;
	string postcode;
};

void readFile()
{
	//read from ourdata txt file
	string line;
	ifstream fin("ourdata.txt");
	if (fin)
	{
		while (!fin.eof())
		{
			//read the line and print as line in terminal on run
			getline(fin, line);
			cout << line << endl;
			gamerStruct game;
			vector<string> items;
			string field = "";
			bool quoteOpen = false;
			//loop for each line
			for (int i = 0; i < line.length(); i++)
			{
				//scan for , to seperate the data
				if (!quoteOpen && line[i] == ',')
				{
					//push items into Nodes
					items.push_back(field);
					field = "";
				}
				else
				{
					field += line[i];
				}
			}
			if (field != "")
			{
				items.push_back(field);
			}

			game.id = items[0];
			game.name = items[1];
			game.email = items[2];
			game.postcode = items[3];
			cout << "----------------------------------------------" << endl;
		}
	}
}

int main()
{
	readFile();

}