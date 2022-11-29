#include <iostream>
#include <fstream>
#include "Gamer.h"
#include <vector>
using namespace std;

void display(Gamer& game)
{
	
}
struct gamerStruct
{
	string id;
	string name;
	string email;
	string postcode;
};
void readFile()
{
	string line;
	ifstream fin("ourdata.txt");
	if (fin)
	{
		while (!fin.eof())
		{
			getline(fin, line);
			cout << line << endl;
			gamerStruct game;
			vector<string> items;
			string field = "";
			bool quoteOpen = false;
			for (int i = 0; i < line.length(); i++)
			{
				if (!quoteOpen && line[i] == ',')
				{
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