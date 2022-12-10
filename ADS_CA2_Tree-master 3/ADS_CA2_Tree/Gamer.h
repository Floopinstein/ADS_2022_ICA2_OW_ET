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

//Creating GamerData Class
class GamerData
{
#pragma region Fields
	string user_id;
	string rank;
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
	string accountCredit;
	string address;
#pragma endregion

public:

	//Making Contructors for variables
#pragma region Constructors
	GamerData(string user_id, string rank, string first_name, string second_name, string gender, string dob, string email, string phone, string postcode,
		string country, string lastLogOn, string lastLogOnTime, string joinedON, string accountCredit, string address)

		: user_id(user_id), rank(rank), first_name(first_name), second_name(second_name), gender(gender), dob(dob), email(email), phone(phone), postcode(postcode),
		country(country), lastLogOn(lastLogOn), lastLogOnTime(lastLogOnTime), joinedON(joinedON), accountCredit(accountCredit), address(address)
	{

	}
#pragma endregion

	//Making Getters/Setters for each variable
#pragma region Get/Set
	string getUser_id() const { return this->user_id; }
	string    getrank() const { return this->rank; }
	string getFirst_name() const { return this->first_name; }
	string getsecond_name() const { return this->second_name; }
	string getgender() const { return this->gender; }
	string getdob() const { return this->dob; }
	string getEmail() const { return this->email; }
	string getphone() const { return this->phone; }
	string getpostcode() const { return this->postcode; }
	string getcountry() const { return this->country; }
	string getlastLogOn() const { return this->lastLogOn; }
	string getlastLogOnTime() const { return this->lastLogOnTime; }
	string getjoinedON() const { return this->joinedON; }
	string getaccountCredit() const { return this->accountCredit; }
	string getaddress() const { return this->address; }
#pragma endregion

#pragma region Operators & Hash

	//Getting all variables back as one group
	bool operator==(const GamerData& gamer)
	{
		return this->user_id == gamer.user_id
			&& this->rank == gamer.rank
			&& this->first_name == gamer.first_name
			&& this->second_name == gamer.second_name
			&& this->gender == gamer.gender
			&& this->dob == gamer.dob
			&& this->email == gamer.email
			&& this->phone == gamer.phone
			&& this->postcode == gamer.postcode
			&& this->country == gamer.country
			&& this->lastLogOn == gamer.lastLogOn
			&& this->lastLogOnTime == gamer.lastLogOnTime
			&& this->joinedON == gamer.joinedON
			&& this->accountCredit == gamer.accountCredit
			&& this->address == gamer.address;

	}

	//Seperating variables with commas
	friend ostream& operator<<(ostream& output, GamerData& gamer)
	{
		output << gamer.user_id << ",";
		output << gamer.rank << ",";
		output << gamer.first_name << ",";
		output << gamer.second_name << ",";
		output << gamer.gender << ",";
		output << gamer.dob << ",";
		output << gamer.email << ",";
		output << gamer.phone << ",";
		output << gamer.postcode << ",";
		output << gamer.country << ",";
		output << gamer.lastLogOn << ",";
		output << gamer.lastLogOnTime << ",";
		output << gamer.joinedON << ",";
		output << gamer.accountCredit << ",";
		output << gamer.address << ",";

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