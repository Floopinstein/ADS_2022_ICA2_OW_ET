#pragma once
#include <string>

using namespace std;

//create gamer class
class Gamer
{
	//gammer variables for Key
	string id;
	string name;
	string email;
	string postcode;

	//make public
public:
	Gamer();
	Gamer(string id, string name, string email, string postcode);
};