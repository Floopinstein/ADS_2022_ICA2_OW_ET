#pragma once
#include <string>

using namespace std;

class Gamer
{

	string id;
	string name;
	string email;
	string postcode;

public:
	Gamer();
	Gamer(string id, string name, string email, string postcode);
};