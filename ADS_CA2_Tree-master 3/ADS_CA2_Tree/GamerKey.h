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

	std::size_t hash() const
	{
		//What is the size of size_t? https://www.geeksforgeeks.org/size_t-data-type-c-language/
		//What are these numbers? https://en.wikipedia.org/wiki/List_of_prime_numbers#The_first_1000_prime_numbers
		size_t hash = std::hash<string>()(this->user_id)
			+ 31 * std::hash<string>()(this->first_name)
			+ 57 * std::hash<string>()(this->email);

	}
#pragma endregion 
};