#pragma once
#include <string>
#include "date.h"
using namespace std;



class GamerKey
{
#pragma region Fields
	string user_id;
	string first_name;
	string email;

#pragma endregion

public:

#pragma region Constructors
	GamerKey(string user_id, string first_name, string email)
		

		: user_id(user_id), first_name(first_name), email(email)
	{
	}
#pragma endregion

#pragma region Get/Set
	string getUser_id() const { return this->user_id; }
	string getFirst_name() const { return this->first_name; }
	string getEmail() const { return this->email; }
#pragma endregion

#pragma region Operators & Hash

	bool operator==(const GamerKey& gamer)
	{
		return this->user_id == gamer.user_id
			&& this->first_name == gamer.first_name
			&& this->email == gamer.email;
	}

	friend ostream& operator<<(ostream& output, GamerKey& gamer)
	{
		output << gamer.user_id << ",";
		output << gamer.first_name << ",";
		output << gamer.email << ",";
		return output;
	}

	friend istream& operator>>(istream& input, GamerKey)
	{
		string gamerAsString;
		input >> gamerAsString;

		return input;
	}


#pragma endregion 
};