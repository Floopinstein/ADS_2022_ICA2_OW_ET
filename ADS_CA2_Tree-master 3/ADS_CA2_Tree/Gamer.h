#pragma once
#include <string>
#include "date.h"
using namespace std;


//class Gamer
//{
	//string user_id;
	//string rank;
	//string first_name;
	//string sName;
	//string gender;
	//string dob;
	//string email;
	//string phone;
	//string postcode;
	//string country;
	//string lastLogOn;
	//string lastLogOnTime;
	//string joinedON;
	//double accountCredit;
	//string address;
//
//
//public:
//	Gamer();
//	Gamer(string user_id, string first_name, string email);
//	Gamer(string user_id, int rank, string first_Name, string sName, string gender, string dob, string email, string phone, string postcode, string address, string country, string lastLogOn, string lastLogOnTime, string joinedON, double accountCredit);
//
//
//	string getuser_id();
//	string getfirst_name();
//	string getemail();
//
//	string Change_to_string();
//
//};

class GamerData
{
#pragma region Fields
	string user_id;
	int rank;
	string first_name;
	string second_name;
	string gender;
	string dob;
	string email;
	string phone;
	string postcode;
	string country;
	string lastLogOn;
	string lastLogOnTime;
	string joinedON;
	double accountCredit;
	string address;
#pragma endregion

public:

#pragma region Constructors
	GamerData(string user_id, int rank, string first_name, string second_name, string gender, string dob, string email, string phone, string postcode,
			  string country, string lastLogOn, string lastLogOnTime, string joinedON, double accountCredit, string address)

		: user_id(user_id), rank(rank), first_name(first_name),second_name(second_name), gender(gender), dob(dob), email(email), phone(phone), postcode(postcode), 
		country(country), lastLogOn(lastLogOn), lastLogOnTime(lastLogOnTime), joinedON(joinedON), accountCredit(accountCredit), address(address)
	{

	}
#pragma endregion

#pragma region Get/Set
	string getUser_id() const { return this->user_id; }
	string getFirst_name() const { return this->first_name; }
	string getEmail() const { return this->email; }
#pragma endregion

#pragma region Operators & Hash

	bool operator==(const GamerData& gamer)
	{
		return this->user_id == gamer.user_id
			&& this->first_name == gamer.first_name
			&& this->email == gamer.email;
	}

	friend ostream& operator<<(ostream& output, GamerData& gamer)
	{
		output << gamer.user_id << ",";
		output << gamer.first_name << ",";
		output << gamer.email << ",";
		return output;
	}

	friend istream& operator>>(istream& input, GamerData)
	{
		string gamerAsString;
		input >> gamerAsString;

		return input;
	}
#pragma endregion 
};